// bballDoc.cpp : implementation of the CBballDoc class
//

#include "stdafx.h"
#include "bball.h"

#include "bballDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBballDoc

IMPLEMENT_DYNCREATE(CBballDoc, CDocument)

BEGIN_MESSAGE_MAP(CBballDoc, CDocument)
	//{{AFX_MSG_MAP(CBballDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBballDoc construction/destruction

CBballDoc::CBballDoc()
{
	// TODO: add one-time construction code here
	// Establish initial sizes for the arrays
	arTeams.SetSize(30, 10);
	arWinners.SetSize(100, 10);
	arNoWins.SetSize(100, 10);

}

CBballDoc::~CBballDoc()
{
}

BOOL CBballDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	// Read in the list of existing baseball teams
	char* szFileName1 = "teams.txt";

	CStdioFile fTeams;
	try
	{
	    fTeams.Open(szFileName1, CFile::modeRead | CFile::typeText);
	}
	catch(CFileException* pExcept)
	{
		CString strMsg;
		strMsg.Format("Failed to open Teams file - %s\n", pExcept->m_cause);
		AfxMessageBox(strMsg);
		pExcept->Delete();
	}

	CString strTeam;
	try
	{
		int nIndex = 0;
		while(fTeams.ReadString(strTeam))
		{
			arTeams.SetAt(nIndex, strTeam);
			nIndex++;
		}
	}
	catch(CFileException* pExcept)
	{
		CString strMsg;
		strMsg.Format("Failed to read from Teams file - %s\n", pExcept->m_cause);
		AfxMessageBox(strMsg);
		pExcept->Delete();
	}
	fTeams.Close();
    UpdateAllViews(NULL);

	// Read in the list of World Series winners
	char* szFileName2 = "winners.txt";

	CStdioFile fWinners;
	try
	{
	    fWinners.Open(szFileName2, CFile::modeRead | CFile::typeText);
	}
	catch(CFileException* pExcept)
	{
		CString strMsg;
		strMsg.Format("Failed to open Winners file - %s\n", pExcept->m_cause);
		AfxMessageBox(strMsg);
		pExcept->Delete();
	}

	CString strWinner;
	try
	{
		int nIndex = 0;
		while(fWinners.ReadString(strWinner))
		{
			arWinners.SetAt(nIndex, strWinner);
			nIndex++;
		}
	}
	catch(CFileException* pExcept)
	{
		CString strMsg;
		strMsg.Format("Failed to read from Winners file - %s\n", pExcept->m_cause);
		AfxMessageBox(strMsg);
		pExcept->Delete();
	}
	fWinners.Close();



	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBballDoc serialization

void CBballDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBballDoc diagnostics

#ifdef _DEBUG
void CBballDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBballDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBballDoc commands

void CBballDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	//arTeams.RemoveAll();
	//arWinners.RemoveAll();
	//arNoWins.RemoveAll();

	UpdateAllViews(NULL);

	CDocument::DeleteContents();
}

void CBballDoc::WriteNonWinners()
{
	// Write out the list of teams that have never won
	char* szFileName1 = "nowins.txt";
	CString strMsg1;
	strMsg1.Format("Failed to open output file. Unable to write non-winners file.\n");
    CString strMsg2;
	strMsg2.Format("Unable to write to output file for non-winners.\n");

	// Construct and create/open output file
	CStdioFile fNoWins;
	int nFlags = CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::typeText;
	try
	{
	    fNoWins.Open(szFileName1, nFlags);
	}
	catch(CFileException* pExcept)
	{
		AfxMessageBox(strMsg1);
		pExcept->Delete();
	}

	// Write list of non-winners to file
	CString strTeam;
	try
	{
		for(int i = 0; i < arNoWins.GetSize(); i++)
		{
			strTeam = arNoWins[i];
			fNoWins.WriteString(strTeam + "\n");
			// Uncomment following line to test exception handler
			//AfxThrowFileException(CFileException::diskFull);
		}
	}
	catch(CFileException* pExcept)
	{
		AfxMessageBox(strMsg2);
		pExcept->Delete();
	}
	fNoWins.Flush();
	fNoWins.Close();
}
