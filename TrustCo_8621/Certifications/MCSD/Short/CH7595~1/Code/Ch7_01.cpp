	CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetApp()->m_pMainWnd);

	ASSERT_VALID( pWnd );

	CSTUploadDoc * pDoc = 
		dynamic_cast< CSTUploadDoc * >( pWnd->GetActiveDocument() );

	ASSERT_VALID( pDoc );

	const CFundDialog * pFD = pWnd->GetFundDialog();

	ASSERT_VALID( pFD );

	// Fill combo box with current fund names
	for( int n = 0; n < pFD->m_listBox.GetCount(); n++ )
	{
		CString strBuf;
		pFD->m_listBox.GetText( n, strBuf );
		m_cbFund.AddString( strBuf );
	}

	// Set listbox selection to strCurrentFund parameter
	int iPos = 
		m_cbFund.FindStringExact( -1, pDoc->GetCurrentFund() );
	
	m_cbFund.SetCurSel( iPos );

	// Setup Date Time Pickers
	m_dtFrom.SetFormat( "d MMM yyy" );
	m_dtTo.SetFormat( "d MMM yyy" );
