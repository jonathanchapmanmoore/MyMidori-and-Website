	// String to customize File Dialog
	CString strFilter = "Data Files (*.dat)|*.dat|All Files (*.*)|*.*||";
	
	CFileDialog aFileDialog( TRUE, NULL, NULL,
		                     OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
							 strFilter);
	
	int nID = aFileDialog.DoModal();

