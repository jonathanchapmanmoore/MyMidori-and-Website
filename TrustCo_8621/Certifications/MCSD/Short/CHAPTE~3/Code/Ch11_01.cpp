void COneArmedBanditCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// Get colors of stock properties
	COLORREF colorBack = TranslateColor( GetBackColor() );
	COLORREF colorFore = TranslateColor( GetForeColor() );
	
	// Get dimensions of control
	float ctrlWidth = float( rcBounds.Width() );
	float ctrlHeight = float( rcBounds.Height() );

	// Setup DC
	CBrush brush( colorBack );
	CBrush * pOldBrush = pdc->SelectObject( &brush );

	CPen pen( PS_SOLID, 3, colorFore );
	CPen *pOldPen = pdc->SelectObject( &pen );
		
	CFont SymbolFont;
	CFont *pOldFont;

	if( SymbolFont.
		CreateFont( long(ctrlHeight / 1.1), long(ctrlWidth/6), 
			0, 0, 0, 0, 0, 0, SYMBOL_CHARSET, 0, 0, 0, 0,"WingDings" ) )   

		pOldFont = pdc->SelectObject( &SymbolFont );
	else
		pOldFont = SelectStockFont( pdc );

		// Draw bounding rectangle
	pdc->Rectangle( rcBounds );
	pdc->SetBkMode( TRANSPARENT );

	// Draw text
	pdc->SetTextColor( colorFore );
	RECT rect;
	::CopyRect( &rect, rcBounds );
	CString strDisplay;
	strDisplay.Format( "%c %c %c", 
		m_symbols[ 0 ], m_symbols[ 1 ], m_symbols[ 2 ] );
	
	pdc->DrawText( strDisplay, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER  );

	// Draw vertical bars
	long onethird = long(ctrlWidth / 3);
	CPoint ptTop( rcBounds.TopLeft() );
	CPoint ptBtm( rcBounds.left, rcBounds.bottom );

	ptTop.x += onethird; ptBtm.x += onethird;
	pdc->MoveTo( ptTop );
	pdc->LineTo( ptBtm );

	ptTop.x += onethird; ptBtm.x += onethird;
	pdc->MoveTo( ptTop );
	pdc->LineTo( ptBtm );

	// Restore device context
	pdc->SelectObject( pOldFont );
	pdc->SelectObject( pOldPen );
	pdc->SelectObject( pOldBrush );
}

