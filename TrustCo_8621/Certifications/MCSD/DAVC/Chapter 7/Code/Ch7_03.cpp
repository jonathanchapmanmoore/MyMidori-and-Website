	CQueryDialog aQDlg;
	
	// Set the default values for the Date Time Picker controls
	// with first and last date on file (all funds)
	CStockData sdFirst = m_DocList.GetHead();
	CStockData sdLast = m_DocList.GetTail();

	aQDlg.m_fromdate = sdFirst.GetDate();
	aQDlg.m_todate = sdLast.GetDate();


	if( aQDlg.DoModal() == IDOK )
	{
		// Construct query
		CString strQuery = "select * from PriceHistory where ph_fund = '";
		strQuery += aQDlg.m_strFund;
		strQuery += "' and ph_date between '";
		strQuery += aQDlg.m_fromdate.Format( "%Y/%m/%d" );
		strQuery += "' and '";
		strQuery += aQDlg.m_todate.Format( "%Y/%m/%d" );
		strQuery += "'";

		// Construct caption string
		CString strCaption = aQDlg.m_strFund;
		strCaption += " Prices ";
		strCaption += aQDlg.m_fromdate.Format( "%d/%m/%Y" );
		strCaption += " - ";
		strCaption += aQDlg.m_todate.Format( "%d/%m/%Y" );

		CResultsDialog rd;

		rd.m_strQuery = strQuery;
		rd.m_strCaption = strCaption;

		rd.DoModal();

	}	
