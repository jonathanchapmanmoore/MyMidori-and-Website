BOOL CLinkDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// Get pointer to view
	CFrameWnd * pFrame = dynamic_cast<CFrameWnd *>( AfxGetMainWnd());
	ASSERT_VALID( pFrame );

	CHtmlView * pHtmlView = dynamic_cast<CHtmlView *>( pFrame->GetActiveView());
	ASSERT_VALID( pHtmlView );

	// Get pointer to the document object dispatch interface
	IDispatch * pDisp = pHtmlView->GetHtmlDocument();
	
	if( pDisp != NULL )
	{
		// Get pointer to IHTMLDocument2 interface to 
		// access document object's properties and methods
		IHTMLDocument2 * pHTMLDocument2;
		HRESULT hr;

		hr = pDisp->QueryInterface( IID_IHTMLDocument2,
			(void**)&pHTMLDocument2 );
		
		if( hr == S_OK )
		{
			// Get pointer to the anchors collection
			IHTMLElementCollection * pColl = NULL;
			hr = pHTMLDocument2->get_anchors( &pColl );

			if( hr == S_OK && pColl != NULL )
			{
				LONG nElem;
				hr = pColl->get_length( &nElem );

				if( hr == S_OK )
				{
					// Iterate across anchors collection
					for( long i = 0; i < nElem; i++ )
					{
						_variant_t vIndex( i );
						_variant_t vName = vIndex;
						
						IDispatch * pDisp2;

						hr = pColl->item( vName, vIndex, &pDisp2 );
						if( hr == S_OK )
						{
							// Retrieve pointer to each Anchor element so that you can
							// retrieve the URL text and add it to the list box
							IHTMLAnchorElement * pAnchElem;
							
							hr = pDisp2->QueryInterface( 
								IID_IHTMLAnchorElement,(void**) &pAnchElem );
							if( hr == S_OK )
							{
								BSTR bstrHref = 0;
								pAnchElem->get_href( &bstrHref );

								CString strLink( bstrHref );
								
								if( !strLink.IsEmpty() )
									m_lbLinkList.AddString( strLink );
								
								SysFreeString( bstrHref );
								pAnchElem->Release();
							}

							pDisp2->Release();
						}
					}
				}

				pColl->Release();
			}

			pHTMLDocument2->Release();
		}

		pDisp->Release();
	}

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
