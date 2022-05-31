		CFileException fx;
		if( !aFile.Open( aFileDialog.GetPathName(), CFile::modeRead | CFile::typeText, &fx ) )
		{
			TCHAR buf[ 255 ];
			fx.GetErrorMessage( buf, 255 );
			CString strPrompt( buf );
			AfxMessageBox( strPrompt );
			return;
		}
