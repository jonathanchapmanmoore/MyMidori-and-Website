void CSTUploadView::OnDraw(CDC* pDC)
{
	CSTUploadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Save the current state of the device context
	int nDC = pDC->SaveDC();
	
	// Create font for axis labels
	CFont aFont;

	if( aFont.
		CreateFont( 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FF_MODERN, 0 ))   

		pDC->SelectObject( &aFont );
	else
	{
		AfxMessageBox( "Unable to create font" );
		return;
	}

	
	const CStockDataList & pData = pDoc->GetDocList();

	int yPos = 10;
	int nTextHeight = pDC->GetTextExtent( "A" ).cy;

	POSITION pos = pData.GetHeadPosition();

	while( pos )
	{
		CStockData sd = pData.GetNext( pos );
	
		pDC->TextOut( 10, yPos, sd.GetAsString() );
		yPos += nTextHeight;
	}

	// Restore the original device context
	pDC->RestoreDC( nDC );

}

