﻿//--
// <copyright file="CloudExecutionReport.cs" company="Microsoft Corporation">
//     Copyright (c) Microsoft Corporation.  All rights reserved.
// </copyright>
//--

namespace NuBuild
{
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Text;
    using System.Xml;
    using Microsoft.WindowsAzure.Storage.Queue;

    /// <summary>
    /// Message that is put on the cloud "reports" queue to inform a cloud
    /// execution engine client of the status of its request.
    /// </summary>
    public class CloudExecutionReport
    {
        /// <summary>
        /// XML element name for this object.
        /// </summary>
        public const string XmlTag = "CloudExecutionReport";

        /// <summary>
        /// Version of this object we create by default.
        /// </summary>
        private const int Version = 1;

        /// <summary>
        /// XML element name for our version field.
        /// </summary>
        private const string XmlVersionAttribute = "Version";

        /// <summary>
        /// XML element name for our identifier field.
        /// </summary>
        private const string XmlIdentifierElement = "Identifier";

        /// <summary>
        /// XML element name for our status field.
        /// </summary>
        private const string XmlStatusElement = "Status";

        /// <summary>
        /// XML element name for our processingNode field.
        /// </summary>
        private const string XmlProcessingNodeElement = "ProcessingNode";

        /// <summary>
        /// XML element name for our exitCode field.
        /// </summary>
        private const string XmlExitCodeElement = "ExitCode";

        /// <summary>
        /// XML element name for our standardOutput field.
        /// </summary>
        private const string XmlStandardOutputElement = "StandardOutput";

        /// <summary>
        /// XML element name for our standardError field.
        /// </summary>
        private const string XmlStandardErrorElement = "StandardError";

        /// <summary>
        /// XML element name for our cpuTime field.
        /// </summary>
        private const string XmlCpuTimeElement = "CpuTime";

        /// <summary>
        /// XML element name for our outputFileMappings field.
        /// </summary>
        private const string XmlOutputFileMappingsElement = "OutputFileMappings";

        /// <summary>
        /// Queued message this instance was created from (if it was).
        /// </summary>
        private CloudQueueMessage message;

        /// <summary>
        /// Version of this object instance.
        /// </summary>
        private int version;

        /// <summary>
        /// Request identifier this report is in response to.
        /// </summary>
        private string identifier;

        /// <summary>
        /// Status of request being conveyed by this report.
        /// </summary>
        private StatusCode status;

        /// <summary>
        /// Name of the node that produced this report.
        /// </summary>
        private string processingNode;

        /// <summary>
        /// Exit code returned from the process after execution.
        /// </summary>
        private int exitCode;

        /// <summary>
        /// Standard out from the process.
        /// </summary>
        private string standardOutput;

        /// <summary>
        /// Standard error from the process.
        /// </summary>
        private string standardError;

        /// <summary>
        /// CPU time used by the process.
        /// </summary>
        private double cpuTime;

        /// <summary>
        /// Collection of output files resulting from this execution,
        /// represented by both their item cache identifier and
        /// their relative path.
        /// </summary>
        private List<BuildObjectValuePointer> outputFileMappings;

        /// <summary>
        /// Initializes a new instance of the CloudExecutionReport class.
        /// </summary>
        /// <param name="identifier">Unique ID for this instance.</param>
        /// <param name="status">Status of the request.</param>
        /// <param name="exitCode">Exit code from the process.</param>
        /// <param name="standardOutput">
        /// Standard output from the process execution.
        /// </param>
        /// <param name="standardError">
        /// Standard error from the process execution.
        /// </param>
        /// <param name="cpuTime">CPU time used by the process.</param>
        /// <param name="outputFileMappings">
        /// Output files generated by this process execution.
        /// </param>
        public CloudExecutionReport(
            string identifier,
            StatusCode status,
            int exitCode,
            string standardOutput,
            string standardError,
            double cpuTime,
            List<BuildObjectValuePointer> outputFileMappings)
            : this(
                CloudExecutionReport.Version,
                identifier,
                status,
                Environment.MachineName,  // REVIEW: Probably insecure (from user settable environment variable?).  Do we care?
                exitCode,
                standardOutput,
                standardError,
                cpuTime,
            outputFileMappings)
        {
        }

        /// <summary>
        /// Initializes a new instance of the CloudExecutionReport class.
        /// </summary>
        /// <param name="identifier">Unique ID for this instance.</param>
        /// <param name="status">Status of the request.</param>
        public CloudExecutionReport(
            string identifier,
            StatusCode status)
            : this(
                CloudExecutionReport.Version,
                identifier,
                status,
                Environment.MachineName,
                0,
                null,
                null,
                0,
                null)
        {
        }

        /// <summary>
        /// Initializes a new instance of the CloudExecutionReport class.
        /// </summary>
        /// <param name="version">Version of this class instance.</param>
        /// <param name="identifier">Unique ID for this instance.</param>
        /// <param name="status">Status of the request.</param>
        /// <param name="processingNode">Name of node producing this report.</param>
        /// <param name="exitCode">Exit code from the process.</param>
        /// <param name="standardOutput">
        /// Standard output from the process execution.
        /// </param>
        /// <param name="standardError">
        /// Standard error from the process execution.
        /// </param>
        /// <param name="cpuTime">CPU time used by the process.</param>
        /// <param name="outputFileMappings">
        /// Output files generated by this process execution.
        /// </param>
        private CloudExecutionReport(
            int version,
            string identifier,
            StatusCode status,
            string processingNode,
            int exitCode,
            string standardOutput,
            string standardError,
            double cpuTime,
            List<BuildObjectValuePointer> outputFileMappings)
        {
            this.version = version;
            this.identifier = identifier;
            this.status = status;
            this.processingNode = processingNode;
            this.exitCode = exitCode;
            this.standardOutput = standardOutput;
            this.standardError = standardError;
            this.cpuTime = cpuTime;
            this.outputFileMappings = outputFileMappings;
        }

        /// <summary>
        /// Definition of Status field values.
        /// </summary>
        public enum StatusCode : int
        {
            /// <summary>
            /// The request was processed to completion and all other fields are meaningful.
            /// Note: this does NOT mean the request completed successfully.
            /// </summary>
            Completed,

            /// <summary>
            /// The request was aborted.
            /// </summary>
            Aborted,

            /// <summary>
            /// The request is in progress.
            /// </summary>
            InProgress
        }

        /// <summary>
        /// Gets the CloudQueueMessage this instance was derived from (if any).
        /// </summary>
        public CloudQueueMessage Message
        {
            get { return this.message; }
        }

        /// <summary>
        /// Gets the unique identifier for the request this report is in response to.
        /// </summary>
        public string Identifier
        {
            get { return this.identifier; }
        }

        /// <summary>
        /// Gets the current status of the request.
        /// </summary>
        public StatusCode Status
        {
            get { return this.status; }
        }

        /// <summary>
        /// Gets the name of processing node that produced this report.
        /// </summary>
        public string ProcessingNode
        {
            get { return this.processingNode; }
        }

        /// <summary>
        /// Gets the exit code returned from the process after execution.
        /// </summary>
        public int ExitCode
        {
            get { return this.exitCode; }
        }

        /// <summary>
        /// Gets the standard output from the process.
        /// </summary>
        public string StandardOutput
        {
            get { return this.standardOutput; }
        }

        /// <summary>
        /// Gets the standard error output from the process.
        /// </summary>
        public string StandardError
        {
            get { return this.standardError; }
        }

        /// <summary>
        /// Gets the CPU time used by the process execution.
        /// </summary>
        public double CpuTime
        {
            get { return this.cpuTime; }
        }

        /// <summary>
        /// Gets the collection of files generated by the process execution.
        /// </summary>
        public IEnumerable<BuildObjectValuePointer> OutputFileMappings
        {
            get { return this.outputFileMappings; }
        }

        /// <summary>
        /// Creates a CloudExecutionReport from a CloudQueueMessage
        /// representation.
        /// </summary>
        /// <param name="message">
        /// A CloudQueueMessage containing an XML document representing a
        /// CloudExecutionReport.
        /// </param>
        /// <returns>
        /// A new report corresponding to the XML representation contained in
        /// the message.
        /// </returns>
        public static CloudExecutionReport FromMessage(CloudQueueMessage message)
        {
            CloudExecutionReport report = CloudExecutionReport.FromXml(message.AsString);
            report.message = message;

            return report;
        }

        /// <summary>
        /// Creates a CloudExecutionReport from an XML representation.
        /// </summary>
        /// <param name="xs">
        /// A string containing an XML document representing a report.
        /// </param>
        /// <returns>
        /// A new report corresponding to the XML representation read.
        /// </returns>
        public static CloudExecutionReport FromXml(string xs)
        {
            XmlReader xr = XmlReader.Create(new StringReader(xs));
            while (xr.Read())
            {
                if (xr.NodeType == XmlNodeType.Element)
                {
                    break;
                }
            }

            return ReadXml(xr);
        }

        /// <summary>
        /// Helper function to read an XML element (not a full document)
        /// representing a cloud execution report.
        /// </summary>
        /// <remarks>
        /// Note that the XmlReader is expected to be positioned in the XML
        /// document such that the current node is a report element.
        /// </remarks>
        /// <param name="xr">The XmlReader object to read from.</param>
        /// <returns>
        /// A new report corresponding to the XML representation read.
        /// </returns>
        public static CloudExecutionReport ReadXml(XmlReader xr)
        {
            Util.Assert(xr.Name.Equals(CloudExecutionReport.XmlTag));

            string versionText = xr.GetAttribute(CloudExecutionReport.XmlVersionAttribute);
            int version = int.Parse(versionText, CultureInfo.InvariantCulture);

            string identifier = string.Empty;
            StatusCode status = StatusCode.Completed;
            string processingNode = "Unknown Benevolence";
            int exitCode = 0;
            string standardOutput = string.Empty;
            string standardError = string.Empty;
            double cpuTime = 0;
            bool inOutputFileMappings = false;
            List<BuildObjectValuePointer> outputFileMappings = new List<BuildObjectValuePointer>();
            List<BuildObject> outputFiles = new List<BuildObject>();
            while (xr.Read())
            {
                if (xr.NodeType == XmlNodeType.Element)
                {
                    switch (xr.Name)
                    {
                        case XmlIdentifierElement:
                            identifier = xr.ReadElementContentAsString();
                            break;

                        case XmlStatusElement:
                            status = (StatusCode)Enum.Parse(typeof(StatusCode), xr.ReadElementContentAsString());
                            break;

                        case XmlProcessingNodeElement:
                            processingNode = xr.ReadElementContentAsString();
                            break;

                        case XmlExitCodeElement:
                            exitCode = xr.ReadElementContentAsInt();
                            break;

                        case XmlStandardOutputElement:
                            standardOutput = xr.ReadElementContentAsString();
                            break;

                        case XmlStandardErrorElement:
                            standardError = xr.ReadElementContentAsString();
                            break;

                        case XmlCpuTimeElement:
                            cpuTime = xr.ReadElementContentAsDouble();
                            break;

                        case XmlOutputFileMappingsElement:
                            inOutputFileMappings = true;
                            break;

                        case BuildObjectValuePointer.XmlTag:
                            Util.Assert(inOutputFileMappings);
                            outputFileMappings.Add(BuildObjectValuePointer.ReadXml(xr));
                            break;
                    }
                }
                else if (xr.NodeType == XmlNodeType.EndElement)
                {
                    if (xr.Name.Equals(CloudExecutionReport.XmlTag))
                    {
                        break;  // All done.
                    }

                    switch (xr.Name)
                    {
                        case XmlOutputFileMappingsElement:
                            inOutputFileMappings = false;
                            break;
                    }
                }
            }

            // REVIEW: Require element presence?  Sanity check things here?
            return new CloudExecutionReport(
                version,
                identifier,
                status,
                processingNode,
                exitCode,
                standardOutput,
                standardError,
                cpuTime,
                outputFileMappings);
        }

        /// <summary>
        /// Creates an XML document representing this cloud execution report.
        /// </summary>
        /// <returns>
        /// A string containing an XML document representing this report.
        /// </returns>
        public string ToXml()
        {
            StringBuilder sb = new StringBuilder();
            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            XmlWriter xw = XmlWriter.Create(sb, settings);
            xw.WriteStartDocument();
            this.WriteXml(xw);
            xw.Close();
            return sb.ToString();
        }

        /// <summary>
        /// Helper function to write an XML element (not a full document)
        /// representing this result record.
        /// </summary>
        /// <param name="xw">The XmlWriter object to write to.</param>
        public void WriteXml(XmlWriter xw)
        {
            // Start writing the element for this object.
            xw.WriteStartElement(XmlTag);
            xw.WriteAttributeString(XmlVersionAttribute, this.version.ToString(CultureInfo.InvariantCulture));

            // Write the Identifier element.
            xw.WriteElementString(XmlIdentifierElement, this.identifier);

            // Write the Status element.
            xw.WriteElementString(XmlStatusElement, this.status.ToString());

            // Write the ProcessingNode element.
            xw.WriteElementString(XmlProcessingNodeElement, this.processingNode);

            if (this.status == StatusCode.Completed)
            {
            // Write the ExitCode element.
            xw.WriteElementString(XmlExitCodeElement, this.exitCode.ToString(CultureInfo.InvariantCulture));

            // Write the Standard Output element.
            xw.WriteElementString(XmlStandardOutputElement, this.standardOutput);

            // Write the Standard Error element.
            xw.WriteElementString(XmlStandardErrorElement, this.standardError);

            // Write the CPU Time element.
            xw.WriteElementString(XmlCpuTimeElement, this.cpuTime.ToString(CultureInfo.InvariantCulture));

            // Write the OutputFileMappings element.
            xw.WriteStartElement(XmlOutputFileMappingsElement);
            foreach (BuildObjectValuePointer outputFile in this.outputFileMappings)
            {
                outputFile.WriteXml(xw);
            }

            xw.WriteEndElement();
            }

            // Finish writing the element for this object.
            xw.WriteEndElement();
        }
    }
}
