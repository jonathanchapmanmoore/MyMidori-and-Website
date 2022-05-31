STDMETHODIMP CATLBandit::Play()
{
	srand( (unsigned)time( NULL ) );

	_tcscpy( m_symbols, _T("JJJ") );

	for( int i = 0; i < 3; i++ ) 
		m_symbols[ i ] += UINT(rand() % m_numberOfSymbols);
		
	m_spInPlaceSite->InvalidateRect( NULL, TRUE ) ; // repaints control

	if( m_symbols[ 0 ] == m_symbols[ 1 ] && 
		m_symbols[ 1 ] == m_symbols[ 2 ] )
		Fire_Jackpot();


	return S_OK;
}
