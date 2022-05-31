	CMainFrame * pFrameWnd = 
		dynamic_cast< CMainFrame * > (m_pMainWnd);

	ASSERT_VALID( pFrameWnd );

	CSTUploadDoc * pDoc = 
		dynamic_cast< CSTUploadDoc * >( pFrameWnd->GetActiveDocument() );

	ASSERT_VALID( pDoc );

	if( pDoc->GetDocList().GetCount() > 0 )
	// Non-empty document at main window creation time means we are 
	// running from icon or from command line with file name argument
	{
		pFrameWnd->UpdateFundList( pDoc->GetDocList(),
			                       pDoc->GetCurrentFund() );
		pFrameWnd->SetFundsVisible( TRUE );
	}
