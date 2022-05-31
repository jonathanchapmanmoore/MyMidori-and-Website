/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Sep 26 15:55:55 1999
 */
/* Compiler settings for C:\Julian\MSPress\Desktop\Chapter 10\Solutions\STUpload\STLoadData\STLoadData.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IUploadStockData = {0x241A7771,0x6888,0x11D3,{0x93,0x4F,0x00,0x80,0xC7,0xFA,0x0C,0x3E}};


const IID LIBID_STLOADDATALib = {0x241A7765,0x6888,0x11D3,{0x93,0x4F,0x00,0x80,0xC7,0xFA,0x0C,0x3E}};


const CLSID CLSID_UploadStockData = {0x241A7772,0x6888,0x11D3,{0x93,0x4F,0x00,0x80,0xC7,0xFA,0x0C,0x3E}};


#ifdef __cplusplus
}
#endif

