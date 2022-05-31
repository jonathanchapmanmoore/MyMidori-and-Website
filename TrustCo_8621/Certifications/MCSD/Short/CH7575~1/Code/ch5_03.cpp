// Function to add one entry per fund to fund view listbox
// CStockDataLists are sorted by fundname so this is easy.

CListBox *pListBox = &m_wndFundDialog.m_listBox;

// Empty current contents of list box
pListBox->ResetContent();

CString strLastFund;

POSITION pos = pList.GetHeadPosition();

while( pos )
{
	CStockData sd = pList.GetNext( pos );
	CString strFund = sd.GetFund();
	if( strFund != strLastFund )
		pListBox->AddString( strFund );
	strLastFund = strFund;
}

// Set listbox selection to strCurrentFund parameter
// No selection if parameter empty or not found.
int iPos = pListBox->FindStringExact( -1, strCurrentFund );
pListBox->SetCurSel( iPos );
