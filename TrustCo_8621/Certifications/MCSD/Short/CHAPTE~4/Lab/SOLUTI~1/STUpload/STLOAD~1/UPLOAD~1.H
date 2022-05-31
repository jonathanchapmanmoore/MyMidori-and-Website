// UploadStockData.h : Declaration of the CUploadStockData

#ifndef __UPLOADSTOCKDATA_H_
#define __UPLOADSTOCKDATA_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUploadStockData
class ATL_NO_VTABLE CUploadStockData : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUploadStockData, &CLSID_UploadStockData>,
	public IDispatchImpl<IUploadStockData, &IID_IUploadStockData, &LIBID_STLOADDATALib>
{
public:
	CUploadStockData()
	{
		m_pConnection = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_UPLOADSTOCKDATA)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CUploadStockData)
	COM_INTERFACE_ENTRY(IUploadStockData)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IUploadStockData
public:
	STDMETHOD(ConnectToDatabase)();
	STDMETHOD(Disconnect)();
	STDMETHOD(UploadRecord)(/*[in]*/ BSTR fund, /*[in]*/ DATE date, /*[in]*/ double price, /*[in]*/ BSTR uplBy, /*[in]*/ DATE uplDate);
protected:
	_ConnectionPtr m_pConnection;
};

#endif //__UPLOADSTOCKDATA_H_
