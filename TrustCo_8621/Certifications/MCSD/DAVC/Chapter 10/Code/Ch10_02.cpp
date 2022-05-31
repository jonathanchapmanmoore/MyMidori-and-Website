int main(int argc, char* argv[])
{
	CoInitialize( NULL );

	{
		IEncoderPtr pServer;

		HRESULT hr = pServer.CreateInstance( __uuidof( Encoder ) );

		if( SUCCEEDED( hr ) )
		{
			short nKey = 1;
			cout << "Enter a code key between -5 and 5: ";
			cin >> nKey;

			_bstr_t bstrHello = "Hello World!";
			_bstr_t bstrCodedHello;

			try
			{
				pServer->Key = nKey; 
				bstrCodedHello = pServer->EncodeString( bstrHello );

				cout << "\n" << (const char *) bstrCodedHello << "\n\n";  

			}
		
			catch( _com_error e )
			{
				cout <<  e.ErrorMessage() << "\n\n";
			}

		}
	}

	::CoUninitialize();

	return 0;
}
