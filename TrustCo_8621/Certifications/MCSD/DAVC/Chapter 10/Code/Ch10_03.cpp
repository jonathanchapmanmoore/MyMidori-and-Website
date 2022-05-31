STDMETHODIMP CUploadStockData::UploadRecord(BSTR fund, DATE date, double price, BSTR uplBy, DATE uplDate)
{
	// Test for live connection to data source
	if( m_pConnection == NULL )
		return E_FAIL;

	// Create recordset
	_RecordsetPtr pRecordset;
	
	HRESULT hr = pRecordset.CreateInstance(__uuidof( Recordset ));
	if( FAILED( hr ) ) return hr;

	try
	{
		// Open recordset
		_variant_t vConnection = m_pConnection.GetInterfacePtr(); 
		hr = pRecordset->Open( L"pricehistory", vConnection, adOpenForwardOnly,
						  adLockOptimistic, adCmdTableDirect );

		if( FAILED( hr ) ) return hr;

		// Add new record, set fields to new values and update
		hr = pRecordset->AddNew();
		if( FAILED( hr ) ) throw _com_error( hr );

		pRecordset->Fields->GetItem( L"ph_fund")->Value = fund;
		pRecordset->Fields->GetItem( L"ph_date")->Value = date;
		pRecordset->Fields->GetItem( L"ph_price")->Value = price;
		pRecordset->Fields->GetItem( L"ph_uploadedby")->Value = uplBy;
		pRecordset->Fields->GetItem( L"ph_uploaddate")->Value = uplDate;

		hr = pRecordset->Update();
		if( FAILED( hr ) ) throw _com_error( hr );

	}
	catch( _com_error e ) 	
	{
		// very unsophisticated error handling
		try
		{
			pRecordset->Close();
		}
		catch(...) // Close() may throw another exception
		{
		}
		return E_FAIL;
	}
	
	pRecordset->Close();

	return S_OK;
}
