void CSTUploadDoc::OnDataUpload() 
{
	if( AfxMessageBox( "Upload current file to database?",
					   MB_OKCANCEL ) == IDCANCEL )
		return;


	::CoInitialize( NULL ); 

	_COM_SMARTPTR_TYPEDEF(IUploadStockData, __uuidof(IUploadStockData));
	 
	IUploadStockDataPtr pServer;

	HRESULT hr = pServer.CreateInstance( CLSID_UploadStockData );

	if( SUCCEEDED( hr ) )
		hr = pServer->ConnectToDatabase();


	if( SUCCEEDED( hr ) )
	{
		try
		{
			POSITION pos = m_DocList.GetHeadPosition();

			while( pos )
			{
				CStockData sd = m_DocList.GetNext( pos );

				BSTR fund = sd.GetFund().AllocSysString();
				DATE date = sd.GetDate().m_dt;
				double price = sd.GetPrice();

				DWORD dwLen = UNLEN + 1;
				TCHAR cUser[ UNLEN + 1 ];
				::GetUserName( cUser, &dwLen );
				CString strUser( cUser );

				BSTR uplBy = (strUser.Left( 10 )).AllocSysString();
				COleDateTime dtToday = COleDateTime::GetCurrentTime();
				DATE uplDate = dtToday.m_dt;

				HRESULT hr = pServer->UploadRecord(fund,  
					date, price, uplBy, uplDate);

				::SysFreeString( fund );
				::SysFreeString( uplBy );

				if( FAILED( hr ))
				{
					CString strPrompt = "Upload of:\n";
					strPrompt += sd.GetAsString();
					strPrompt += "\nfailed";
					
					if( AfxMessageBox( strPrompt, MB_OKCANCEL ) == IDCANCEL )
						break;
				}
						 
			}

			if( !pos ) // We got to the end of the loop
				AfxMessageBox( "Upload completed successfully" );
		}
		catch( _com_error e )
		{
			::MessageBox( NULL, e.ErrorMessage(), NULL, MB_OK );
		}
		pServer->Disconnect();

	}

	::CoUninitialize();
	
}
