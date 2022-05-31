CSTUploadDoc::CSTUploadDoc()
{
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 1, 0, 0, 0 ),
					   22.33 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 2, 0, 0, 0 ),
					   23.44 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 3, 0, 0, 0 ),
					   24.55 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 4, 0, 0, 0 ),
					   25.66 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 5, 0, 0, 0 ),
					   26.77 ));
	
}
