	m_DocList.RemoveAll();

	CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());

	if( pWnd )
	{
		pWnd->UpdateFundList( m_DocList );
		// No funds on file, so hide fund window 
		pWnd->SetFundsVisible( FALSE );
		// And reset current fund value
		SetCurrentFund("");
	}

