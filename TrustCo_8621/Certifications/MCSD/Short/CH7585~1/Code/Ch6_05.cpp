void CSTUploadDoc::Serialize(CArchive& ar)
{
	m_DocList.Serialize( ar );

	if (ar.IsStoring())
	{
		ar << m_strCurrentFund;	
	}
	else
	{
		ar >> m_strCurrentFund;

		// Update Fund Selection window
		CMainFrame* pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());

		if( pWnd ) 
		// Will fail if running from icon or from
		// command line with file name argument
		{
			// Update and show fund window
			pWnd->UpdateFundList( m_DocList, m_strCurrentFund );
			pWnd->SetFundsVisible( TRUE );
		}
	
	}
}
