void CSTUploadView::OnDraw(CDC* pDC)
{
	CSTUploadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Save the current state of the device context
	int nDC = pDC->SaveDC();
	
	const CStockDataList & pData = pDoc->GetDocList();

	// Make a small array containing the
	// records for the current fund.
	// We use an array to take advantage of indexed access
	CArray< CStockData, CStockData & > arrFundData;

	POSITION pos = pData.GetHeadPosition();

	while( pos )
	{
		CStockData sd = pData.GetNext( pos );

		if( sd.GetFund() == pDoc->GetCurrentFund() )
			arrFundData.Add( sd );
	}

	int nPrices = arrFundData.GetSize();
	if( nPrices == 0 ) 
		return; 

	// Some constant sizes (in device units)
	const int AXIS_DIVIDER_LENGTH = 6;
	const int AXIS_FONT_HEIGHT = 24;
	const int HEADING_FONT_HEIGHT = 36;

	// Create font for axis labels
	CFont AxisFont;
	if( AxisFont.
		CreateFont( AXIS_FONT_HEIGHT, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FF_ROMAN, 0 ))   

		pDC->SelectObject( &AxisFont );
	else
	{
		AfxMessageBox( "Unable to create Axis font" );
		return;
	}


	CPen AxisPen;
    if( AxisPen.CreatePen( PS_SOLID, 1, RGB(0,0,0) ) )    
        pDC->SelectObject( &AxisPen );
	else
	{
		AfxMessageBox( "Unable to create Axis Pen" );
		return;
	}

	// Array to graph co-ordinates as we go
	CArray< CPoint, CPoint& > CoordArray;
	for( int i = 0; i < nPrices; i++ )
		CoordArray.Add( CPoint( 0, 0) );

	// Set viewport origin to bottom left corner of window 
	CPoint ptBottomLeft( 0, -850 );
	pDC->LPtoDP( &ptBottomLeft );
	pDC->SetViewportOrg( ptBottomLeft );

	// Base co-ordinates for axes
	const CPoint ORIGIN(100, 100);
	const CPoint Y_EXTENT( ORIGIN.x, ORIGIN.y + 650);
	const CPoint X_EXTENT(ORIGIN.x + 900, ORIGIN.y);

	// Draw axes
	pDC->MoveTo( Y_EXTENT );
	pDC->LineTo( ORIGIN );
	pDC->LineTo( X_EXTENT );

	int nLabelPos = Y_EXTENT.y + ((ORIGIN.y - Y_EXTENT.y) / 2);
	pDC->TextOut( ORIGIN.x - 50, nLabelPos, '$' ); 

	// Divide x-axis into number of prices held in the file
	int nXIncrement = (X_EXTENT.x - ORIGIN.x) / nPrices;

	double nMaxPrice = 0;
	double nMinPrice = 0;

	for( i = 0; i < nPrices; i++ )
	{
		int xPoint = (ORIGIN.x + (i * nXIncrement));
		CoordArray[ i ].x = xPoint;

		pDC->MoveTo( xPoint, ORIGIN.y );
		pDC->LineTo( xPoint, ORIGIN.y + AXIS_DIVIDER_LENGTH );
		
		COleDateTime aDate = arrFundData[ i ].GetDate();
		double aPrice = arrFundData[ i ].GetPrice();

		nMaxPrice = max( nMaxPrice, aPrice );
		nMinPrice = nMinPrice == 0 ? 
                                 nMaxPrice : 
		                         min( nMinPrice, aPrice );

		CString strDate = aDate.Format( "%m/%d/%y" ); 
		
		if( i == 0 || i == (nPrices-1) )
			pDC->TextOut( xPoint-2, ORIGIN.y - AXIS_FONT_HEIGHT / 2, 
						  strDate );
		else
		{
			CString strDay = strDate.Mid( strDate.Find( '/' ) + 1);
			strDay = strDay.Left( strDay.Find( '/' ) );
			pDC->TextOut( xPoint-6, ORIGIN.y - AXIS_FONT_HEIGHT / 2, 
						  strDay );
		}
	}


	// Divide y-axis into suitable scale based on 
	// the difference between max and min prices on file
	nMaxPrice += 2.0;
	nMinPrice -= 1.0;
	int iScale = int(nMaxPrice) - int(nMinPrice);

	int nYIncrement = ( ORIGIN.y - Y_EXTENT.y ) / iScale;
	
	for( i = 0; i < iScale; i++ )
	{
		int yPoint = (ORIGIN.y - (i * nYIncrement));
		pDC->MoveTo( ORIGIN.x, yPoint);
		pDC->LineTo( ORIGIN.x - AXIS_DIVIDER_LENGTH, yPoint);
		
		int iCurrentPrice = int(nMinPrice) + i;

		for( int j = 0; j < nPrices; j++ )
		{
			double aPrice = arrFundData[ j ].GetPrice();
			if( aPrice >= double(iCurrentPrice) && 
				aPrice <  double(iCurrentPrice) + 1.0 )
			{
				double dFraction = aPrice - double(iCurrentPrice);
				CoordArray[ j ].y = 
					yPoint - int(dFraction * double( nYIncrement ) );
			}
		}


		CString strPrice;
		strPrice.Format( "%d", iCurrentPrice );

		int nTextSize = pDC->GetTextExtent( strPrice ).cx;
		nTextSize += 10;
		
		pDC->TextOut( ORIGIN.x - nTextSize, yPoint+12, strPrice );
	}


	// Graph figures stored in CoordArray
	CPen GraphPen;	
    if( GraphPen.CreatePen( PS_SOLID, 1, RGB(255,0,0) ) )  // Red pen  
	{
        pDC->SelectObject( &GraphPen );
	}
	else
	{
		AfxMessageBox( "Unable to create Graph Pen" );
		return;
	}


	// Draw Graph
	// Label graph points with price value (in blue)

	COLORREF crOldText = pDC->SetTextColor( RGB( 0,0,255 ) );

	pDC->MoveTo( CoordArray[ 0 ] );

	for( i = 0; i < nPrices; i++ )
	{

		pDC->LineTo( CoordArray[ i ] );
		
		CPoint TextPoint;

		if( (i+1) < nPrices )
		{
			if( CoordArray[ i + 1 ].y >= CoordArray[ i ].y )
				TextPoint = CoordArray[ i ] + CPoint( 5, 0 );
			else
				TextPoint = CoordArray[ i ] + CPoint( 5, AXIS_FONT_HEIGHT );
		}
		else
			TextPoint = CoordArray[ i ] + CPoint( 5, 0);

		CString strPrice;
		strPrice.Format( "%.2f", arrFundData[ i ].GetPrice() );

		pDC->TextOut( TextPoint.x, TextPoint.y, strPrice  ); 
	}

	pDC->SetTextColor( crOldText );


	// Create heading
	CFont HeadingFont;
	if( HeadingFont.
		CreateFont( HEADING_FONT_HEIGHT, 0, 0, 0, FW_BOLD, 1, 0, 0, 0, 0, 0, 0, FF_ROMAN, 0 ))   

		pDC->SelectObject( &HeadingFont );
	else
	{
		AfxMessageBox( "Unable to create Heading Font" );
		return;
	}

	CString strHeading = pDoc->GetCurrentFund();
	strHeading += " - Closing Prices ";

	COleDateTime aDate = arrFundData[ 0 ].GetDate();
	strHeading += aDate.Format( "%m/%d/%y" ); 
	strHeading += " to ";
	aDate = arrFundData[ nPrices - 1 ].GetDate();
	strHeading += aDate.Format( "%m/%d/%y" ); 

	CSize sizeText = pDC->GetTextExtent( strHeading );

	pDC->TextOut( X_EXTENT.x - sizeText.cx, 
				  Y_EXTENT.y + sizeText.cy, strHeading );

	// Restore the original device context
	pDC->RestoreDC( nDC );

}
