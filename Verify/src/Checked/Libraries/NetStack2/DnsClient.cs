///////////////////////////////////////////////////////////////////////////////
//
//  Microsoft Research Singularity
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//
//  File:   DnsClient.cs
//

#define DEBUG_DNS_CLIENT

using System;
using System.Collections;
using System.Diagnostics;
using System.Text;

using System.Net.IP;
using Drivers.Net;

using Microsoft.Singularity.NetStack.Protocols;

using Dns = Microsoft.Singularity.NetStack2.Protocols.Dns;

using Microsoft.Singularity.Channels;
using Microsoft.Singularity.Io;
using Microsoft.Singularity;
using Microsoft.SingSharp;


namespace Microsoft.Singularity.NetStack2
{
    /// <summary>
    /// Dns Client for UDP lookups.
    /// </summary>
    public class BasicDnsClient
    {
        private IPv4      dnsServer;
        private TimeSpan  timeout;
        private Dns.Flags flags;

        public const int DefaultTimeoutMillis = 500;

        public enum StatusCode : int
        {
            Success         = 0,
                NoNameServer    = 1,
                TransportError  = 2,
                RequestFailed   = 3,
                Timeout         = 4,
                OverSizeMessage = 5
                }

        public BasicDnsClient()
            : this(IPv4.Any)
        {
        }

        public BasicDnsClient(IPv4 dnsServer)
        {
            this.dnsServer  = dnsServer;
            this.timeout    = TimeSpan.FromMilliseconds(DefaultTimeoutMillis);
            this.flags      = Dns.Flags.RD;
        }

        public IPv4 DnsServer
        {
            get {
                if (dnsServer != IPv4.Any)
                    return dnsServer;
                HostConfiguration hostConfiguration = IP.GetHostConfiguration();
                return hostConfiguration.GetCurrentNameServer();
            }
        }

        public TimeSpan Timeout
        {
            get { return timeout; }
            set { timeout = value; }
        }

        public Dns.Flags Flags
        {
            get { return flags; }
            set { flags = value; }
        }

        [Conditional("DEBUG_DNS_CLIENT") ]
        private static void DebugPrint(string format, params object [] arguments)
        {
            DebugStub.Print("DNSClient {0}", DebugStub.ArgList(
                                string.Format(format, arguments)));
        }

        [ System.Diagnostics.Conditional("DEBUG_DNS_CLIENT") ]
        private static void Dump(byte [] data, int offset)
        {
            for (int i = offset; i < data.Length; i += 16) {
                DebugPrint("{0:x4}  ", i);
                int n = Math.Min(16, data.Length - i) + i;
                for (int j = i; j < n; j++)
                    DebugPrint("{0:x2} ", data[j]);
                for (int j = n; j != i + 16; j++)
                    DebugPrint("   ");
                DebugPrint("  ");
                for (int j = i; j < n; j++) {
                    char c = '.';
                    if (data[j] > 31 && data[j] < 128)
                        c = (char)data[j];
                    DebugPrint("{0}", c);
                }
                DebugPrint("\n");
            }
        }

        /// <summary>
        /// Gets the DNS information for the specified DNS host name.
        /// </summary>
        public StatusCode GetHostByName(string            name,
                                        out IPv4HostEntry hostEntry)
        {
            hostEntry = null;

            IPv4 dnsServer = DnsServer;
            if (dnsServer == IPv4.Zero)
                return StatusCode.NoNameServer;

            Dns.Query q = new Dns.Query(name, Dns.Type.A, Dns.Class.Internet);
            Dns.Format answer;

            StatusCode askResponse = Ask(dnsServer, q, out answer);
            if (askResponse != StatusCode.Success)
                return askResponse;
            VTable.Assert(answer != null);

            if (answer.GetRCode() != Dns.RCode.NoError) {
                DebugPrint("Dns query failed: RCode = {0}\n", answer.GetRCode());
                return StatusCode.RequestFailed;
            }

            hostEntry = new IPv4HostEntry( new string [] { name }, new IPv4[] {} );
            ArrayList addressList = new ArrayList();

            foreach (Dns.ResourceRecord rr in answer.AnswerRRs) {
                if (rr.Type != Dns.Type.A || rr.Class != Dns.Class.Internet)
                    continue;

                byte [] rdata = rr.RData;
                if (rdata == null)
                    continue;

                if ((rdata.Length % IPv4.Length) != 0)
                    continue;

                int offset = 0;
                while (offset != rdata.Length) {
                    addressList.Add(IPv4.ParseBytes(rdata, offset));
                    offset += 4;
                }
            }

            IPv4[] al = hostEntry.AddressList = new IPv4 [addressList.Count];
            for (int i = 0; i < addressList.Count; i++)
                al[i] = (IPv4) addressList[i];

            return StatusCode.Success;
        }

        /// <summary>
        /// Gets DNS host information for an IP address.
        /// </summary>
        public StatusCode GetHostByAddress(IPv4              address,
                                           out IPv4HostEntry hostEntry)
        {
            hostEntry = null;

            IPv4 dnsServer = DnsServer;
            if (dnsServer == IPv4.Zero)
                return StatusCode.NoNameServer;

            // Formulate request a.b.c.d -> d.b.c.a
            IPv4 reversed = new IPv4(ByteOrder.Swap((uint)address));
            string name = String.Format("{0}.IN-ADDR.ARPA", reversed);

            DebugPrint("Looking up {0}\n", name);

            Dns.Query q = new Dns.Query(name, Dns.Type.PTR, Dns.Class.Internet);
            Dns.Format answer;

            StatusCode askResponse = Ask(dnsServer, q, out answer);
            if (askResponse != StatusCode.Success)
                return askResponse;
            VTable.Assert(answer != null);

            if (answer.GetRCode() != Dns.RCode.NoError) {
                DebugPrint("Dns query failed: RCode = {0}\n", answer.GetRCode());
                return StatusCode.RequestFailed;
            }

            hostEntry = new IPv4HostEntry(new string[]{}, new IPv4 [] { address });

            ArrayList aliases = new ArrayList();
            foreach (Dns.ResourceRecord rr in answer.AnswerRRs) {
                DebugPrint("Answer: Type = {0} Class = {1} TTL = {2}\n",
                           rr.Type, rr.Class, rr.TtlSeconds);
                if ((rr.Type != Dns.Type.PTR && rr.Type != Dns.Type.CNAME) ||
                    rr.Class != Dns.Class.Internet)
                    continue;

                byte [] rdata = rr.RData;
                if (rdata == null)
                    continue;

                int offset = 0;
                while (offset != rdata.Length) {
                    string alias;
                    offset += Dns.LabelEncoding.GetString(rdata, offset,
                                                          out alias);
                    aliases.Add(alias);
                }
            }
            string[] arr = new string[aliases.Count];
            for (int i = 0; i < arr.Length; i++) {
                arr[i] = (string)(aliases[i]);
            }
            hostEntry.Aliases = arr;

            return StatusCode.Success;
        }

        /// <summary>
        /// Resolves a DNS host name or IP address to an IPv4HostEntry instance.
        /// </summary>
        public StatusCode Resolve(string            hostName,
                                  out IPv4HostEntry hostEntry)
        {
            IPv4 hostAddress;

            if (IPv4.Parse(hostName, out hostAddress) == true) {
                StatusCode status = GetHostByAddress(hostAddress, out hostEntry);

                if (status != StatusCode.Success) {
                    // As a convenience to the caller, instead of failing
                    // outright, at least give back the parsed version of
                    // the net address.
                    hostEntry = new IPv4HostEntry(new string [] { hostName },
                                                  new IPv4 [] { hostAddress });

                    return StatusCode.Success;
                }
            }

            return GetHostByName(hostName, out hostEntry);
        }

        private StatusCode Ask(IPv4           dnsServer,
                               Dns.Query []  queries,
                               out Dns.Format answer)
        {
            answer = null;

            Dns.Format outFrame = new Dns.Format();
            outFrame.SetFlags(flags);
            foreach (object o in queries) {
                outFrame.Queries.Add(o);
            }

            byte[] outData = new byte [outFrame.Size];
            if (outData.Length > Dns.Format.MaxUdpMessageLength) {
                return StatusCode.OverSizeMessage;
            }

            int offset = 0;
            outFrame.Write(outData, ref offset);

            byte[] rcvData;
            StatusCode askResponse = AskDnsServer(dnsServer, outData, out rcvData);
            if (askResponse != StatusCode.Success) {
                return askResponse;
            }
            VTable.Assert(rcvData != null);

            try {
                offset = 0;
                Dump(rcvData, offset);
                answer = Dns.Format.Parse(rcvData, ref offset);
            }
            catch (Exception e) {
                DebugPrint("Parser threw {0}", e);
                return StatusCode.TransportError;
            }

            return StatusCode.Success;
        }

        public StatusCode Ask(IPv4           dnsServer,
                              Dns.Query      query,
                              out Dns.Format answer)
        {
            return Ask(dnsServer, new Dns.Query [] { query }, out answer);
        }

        //way too many copies.  But for now we'll live with it.
        private StatusCode AskDnsServer(IPv4       dnsServer,
                                        byte[]    outData,
                                        out byte[] rcvData)
        {

            UDP udp = new UDP();
            udp.Bind(IPv4.Any, 0);
            udp.Connect(dnsServer, Dns.Format.ServerPort);

            Bytes packet = Bitter.FromByteArray(outData);
            udp.WriteData(packet);

            Bytes buffer;
            buffer = udp.PollReadData(TimeSpan.FromTicks(timeout.Ticks));

            //This is silly..I'll come back and clean this up.
            udp.Close();

            if (buffer == null) {
                rcvData = null;
                return StatusCode.Timeout;
            }
            rcvData = new byte[buffer.Length];
            Bitter.ToByteArray(buffer, 0, buffer.Length, rcvData, 0);
            //delete buffer;

            return StatusCode.Success;
        }
    }
}
