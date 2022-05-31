	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		const RECT& rc = *reinterpret_cast<const RECT*>(di.prcBounds);
		HDC dc = di.hdcDraw;
		
		COLORREF colorBack, colorFore;
		OleTranslateColor( m_clrForeColor, NULL, &colorFore );
		OleTranslateColor( m_clrBackColor, NULL, &colorBack );

		// Get dimensions of control
		float ctrlWidth = float( rc.right - rc.left );
		float ctrlHeight = float( rc.bottom - rc.top );

		// Setup DC
		HBRUSH brush = CreateSolidBrush( colorBack );
		HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject( dc, brush ) );

		HPEN pen = CreatePen( PS_SOLID, 3, colorFore );
		HPEN oldPen = static_cast<HPEN>(SelectObject( dc, pen ) );

		HFONT SymbolFont = CreateFont( long(ctrlHeight / 1.1), long(ctrlWidth/6), 
			0, 0, 0, 0, 0, 0, SYMBOL_CHARSET, 0, 0, 0, 0,"WingDings" ); 

		HFONT oldFont = static_cast<HFONT>(SelectObject( dc, SymbolFont ) );

		// Draw bounding rectangle
		Rectangle( dc, rc.left, rc.top, rc.right, rc.bottom );
		SetBkMode( dc, TRANSPARENT );

		// Draw text
		SetTextColor( dc, colorFore );
		RECT rect;
		CopyRect( &rect, &rc );

		TCHAR strDisplay[ 5 ];
		_stprintf( strDisplay, "%c %c %c",
			m_symbols[ 0 ], m_symbols[ 1 ], m_symbols[ 2 ] );
	
		DrawText( dc, strDisplay, 5, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER  );

		// Draw vertical bars
		long onethird = long(ctrlWidth / 3);
		POINT ptTop = { rc.left, rc.top };
		POINT ptBtm = { rc.left, rc.bottom };

		ptTop.x += onethird; ptBtm.x += onethird;
		MoveToEx( dc, ptTop.x, ptTop.y, NULL );
		LineTo( dc, ptBtm.x, ptBtm.y );

		ptTop.x += onethird; ptBtm.x += onethird;
		MoveToEx( dc, ptTop.x, ptTop.y, NULL );
		LineTo( dc, ptBtm.x, ptBtm.y );


		// Restore device context
		SelectObject( dc, oldFont );
		SelectObject( dc, oldPen );
		SelectObject( dc, oldBrush );

		DeleteObject( brush );
		DeleteObject( pen );
		DeleteObject( SymbolFont );

		return S_OK;
	}
