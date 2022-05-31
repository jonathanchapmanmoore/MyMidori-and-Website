/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Sep 25 18:48:10 1999
 */
/* Compiler settings for C:\Julian\MSPress\Desktop\Chapter 9\Solutions\STUpload\STLoadData\STLoadData.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __STLoadData_h__
#define __STLoadData_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IUploadStockData_FWD_DEFINED__
#define __IUploadStockData_FWD_DEFINED__
typedef interface IUploadStockData IUploadStockData;
#endif 	/* __IUploadStockData_FWD_DEFINED__ */


#ifndef __UploadStockData_FWD_DEFINED__
#define __UploadStockData_FWD_DEFINED__

#ifdef __cplusplus
typedef class UploadStockData UploadStockData;
#else
typedef struct UploadStockData UploadStockData;
#endif /* __cplusplus */

#endif 	/* __UploadStockData_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IUploadStockData_INTERFACE_DEFINED__
#define __IUploadStockData_INTERFACE_DEFINED__

/* interface IUploadStockData */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUploadStockData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("241A7771-6888-11D3-934F-0080C7FA0C3E")
    IUploadStockData : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UploadRecord( 
            /* [in] */ BSTR fund,
            /* [in] */ DATE date,
            /* [in] */ double price,
            /* [in] */ BSTR uplBy,
            /* [in] */ DATE uplDate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConnectToDatabase( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUploadStockDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IUploadStockData __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IUploadStockData __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IUploadStockData __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IUploadStockData __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IUploadStockData __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IUploadStockData __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IUploadStockData __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UploadRecord )( 
            IUploadStockData __RPC_FAR * This,
            /* [in] */ BSTR fund,
            /* [in] */ DATE date,
            /* [in] */ double price,
            /* [in] */ BSTR uplBy,
            /* [in] */ DATE uplDate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConnectToDatabase )( 
            IUploadStockData __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IUploadStockData __RPC_FAR * This);
        
        END_INTERFACE
    } IUploadStockDataVtbl;

    interface IUploadStockData
    {
        CONST_VTBL struct IUploadStockDataVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUploadStockData_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUploadStockData_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUploadStockData_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUploadStockData_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUploadStockData_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUploadStockData_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUploadStockData_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUploadStockData_UploadRecord(This,fund,date,price,uplBy,uplDate)	\
    (This)->lpVtbl -> UploadRecord(This,fund,date,price,uplBy,uplDate)

#define IUploadStockData_ConnectToDatabase(This)	\
    (This)->lpVtbl -> ConnectToDatabase(This)

#define IUploadStockData_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUploadStockData_UploadRecord_Proxy( 
    IUploadStockData __RPC_FAR * This,
    /* [in] */ BSTR fund,
    /* [in] */ DATE date,
    /* [in] */ double price,
    /* [in] */ BSTR uplBy,
    /* [in] */ DATE uplDate);


void __RPC_STUB IUploadStockData_UploadRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUploadStockData_ConnectToDatabase_Proxy( 
    IUploadStockData __RPC_FAR * This);


void __RPC_STUB IUploadStockData_ConnectToDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUploadStockData_Disconnect_Proxy( 
    IUploadStockData __RPC_FAR * This);


void __RPC_STUB IUploadStockData_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUploadStockData_INTERFACE_DEFINED__ */



#ifndef __STLOADDATALib_LIBRARY_DEFINED__
#define __STLOADDATALib_LIBRARY_DEFINED__

/* library STLOADDATALib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_STLOADDATALib;

EXTERN_C const CLSID CLSID_UploadStockData;

#ifdef __cplusplus

class DECLSPEC_UUID("241A7772-6888-11D3-934F-0080C7FA0C3E")
UploadStockData;
#endif
#endif /* __STLOADDATALib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
