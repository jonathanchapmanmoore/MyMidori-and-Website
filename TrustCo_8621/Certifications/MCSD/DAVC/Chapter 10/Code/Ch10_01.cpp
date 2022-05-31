int main(int argc, char* argv[])
{
	::CoInitialize( NULL );

	IEncoder * pServer;

	HRESULT hr = ::CoCreateInstance( CLSID_Encoder, NULL,
									 CLSCTX_INPROC_SERVER,
									 IID_IEncoder,
									 (void **) &pServer );

	if( SUCCEEDED( hr ) )
	{
		short nKey = 1;
		cout << "Enter a code key between -5 and 5: ";
		cin >> nKey;

		wchar_t wstrHello[ 16 ] = L"Hello World!";
		BSTR bstrHello = ::SysAllocString( wstrHello );
		BSTR bstrCodedHello;

		HRESULT hr = pServer->put_Key( nKey );
		if( FAILED( hr )) goto ComError;

		hr = pServer->EncodeString( bstrHello, &bstrCodedHello );
		if( FAILED( hr )) goto ComError;

		char strOut[ 16 ];
		wcstombs( strOut, bstrCodedHello, 16 );
		cout << "\n" << strOut << "\n\n";  

		ComError: 
			if( FAILED( hr )) cout << "COM Error" << "\n\n";

		::SysFreeString( bstrHello );
		::SysFreeString( bstrCodedHello );
	
		pServer->Release();
	}
	

	::CoUninitialize();

	return 0;
}
