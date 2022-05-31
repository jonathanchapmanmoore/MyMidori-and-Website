	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 1, 0, 0, 0 ),
					   22.33 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 2, 0, 0, 0 ),
					   25.44 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 3, 0, 0, 0 ),
					   23.55 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 4, 0, 0, 0 ),
					   27.66 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 5, 0, 0, 0 ),
					   28.77 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 1, 0, 0, 0 ),
					   15.33 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 2, 0, 0, 0 ),
					   16.44 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 3, 0, 0, 0 ),
					   13.55 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 4, 0, 0, 0 ),
					   14.66 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 5, 0, 0, 0 ),
					   12.77 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 1, 0, 0, 0 ),
					   15.33 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 2, 0, 0, 0 ),
					   16.44 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 3, 0, 0, 0 ),
					   18.55 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 4, 0, 0, 0 ),
					   21.66 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 5, 0, 0, 0 ),
					   19.77 ));

	// Update main window
	UpdateAllViews( NULL );

	// Update Fund Selection window
	CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());
	if( pWnd )
	{
		pWnd->UpdateFundList( m_DocList );
		// Show fund window after loading new funds
		pWnd->SetFundsVisible( TRUE );
	}
	

	return TRUE;
