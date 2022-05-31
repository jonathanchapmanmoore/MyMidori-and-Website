	m_adodc.SetRecordSource( m_strQuery );
	m_adodc.Refresh();

	C_Recordset cRS = m_adodc.GetRecordset();

	long lRecs = cRS.GetRecordCount();

	if( lRecs < 1 )
	{
		AfxMessageBox( "No records match this query" );
		EndDialog( IDCANCEL );
	}

	m_datagrid.SetCaption( m_strCaption );
