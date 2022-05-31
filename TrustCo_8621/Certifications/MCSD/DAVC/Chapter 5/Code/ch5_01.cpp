	BOOL AreFundsVisible() { return m_bFundsVisible; }

	void SetFundsVisible( BOOL bSet ) 
	{ 
		m_bFundsVisible = bSet; 
		if( bSet ) m_wndFundDialog.ShowWindow( SW_SHOW );
		else m_wndFundDialog.ShowWindow( SW_HIDE );
	} 
