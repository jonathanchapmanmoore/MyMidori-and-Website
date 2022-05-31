	CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());
	ASSERT_VALID( pWnd );
	
	CSTUploadDoc * pDoc = 
		dynamic_cast< CSTUploadDoc * >( pWnd->GetActiveDocument());
	ASSERT_VALID( pDoc );
	
	CString strCurFund;
	
	int sel = m_listBox.GetCurSel();
	
	if( sel == LB_ERR ) sel = 0;
	
	m_listBox.GetText( sel, strCurFund );
	
	pDoc->SetCurrentFund( strCurFund );
	
	pDoc->UpdateAllViews( NULL );
	
	
