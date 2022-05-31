// Enable the View Funds Selection dialog if 
// The document CStockDataList is not empty
// If enabled then toggle button state checked/unchecked
// According to whether the window is displayed or hidden

BOOL bEnable = FALSE;

CSTUploadDoc * pDoc = 
	dynamic_cast< CSTUploadDoc * >( GetActiveDocument() );

if( pDoc )
	bEnable = pDoc->GetDocList().GetCount() ? TRUE : FALSE;

	pCmdUI->Enable( bEnable );	

if( bEnable )
	pCmdUI->SetCheck( m_bFundsVisible ? 1 : 0 );	
