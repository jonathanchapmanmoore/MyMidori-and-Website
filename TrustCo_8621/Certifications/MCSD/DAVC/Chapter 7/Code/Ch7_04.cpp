	// Enable the Query Database command only if there is 
	// data on file and a fund currently selected for viewing

	BOOL bEnable = FALSE;

	bEnable = m_strCurrentFund.IsEmpty() ? FALSE : TRUE;

	pCmdUI->Enable( bEnable );		
