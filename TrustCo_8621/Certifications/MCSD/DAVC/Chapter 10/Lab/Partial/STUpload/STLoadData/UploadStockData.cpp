// UploadStockData.cpp : Implementation of CUploadStockData
#include "stdafx.h"
#include "STLoadData.h"
#include "UploadStockData.h"

/////////////////////////////////////////////////////////////////////////////
// CUploadStockData


STDMETHODIMP CUploadStockData::UploadRecord(BSTR fund, DATE date, double price, BSTR uplBy, DATE uplDate)
{
	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CUploadStockData::Disconnect()
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CUploadStockData::ConnectToDatabase()
{
	// TODO: Add your implementation code here

	return S_OK;
}
