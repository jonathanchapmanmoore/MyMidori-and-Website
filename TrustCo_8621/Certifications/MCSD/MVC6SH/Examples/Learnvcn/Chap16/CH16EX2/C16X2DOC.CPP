// C16x2Doc.cpp : implementation of the CCh16Ex2Doc class
//

#include "stdafx.h"
#include "Ch16Ex2.h"

#include "C16x2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2Doc

IMPLEMENT_DYNCREATE(CCh16Ex2Doc, CDocument)

BEGIN_MESSAGE_MAP(CCh16Ex2Doc, CDocument)
	//{{AFX_MSG_MAP(CCh16Ex2Doc)
	ON_COMMAND(ID_CHANGE_EDIT_VALUES, OnChangeEditValues)
	ON_COMMAND(ID_CHANGE_ZERO_OUT, OnChangeZeroOut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2Doc construction/destruction

CCh16Ex2Doc::CCh16Ex2Doc()
{
	// TODO: add one-time construction code here
	// Create the two pointer data members.
	m_pMyObj = new CMyObject;
	m_pMyObj2 = new CMyObject2;
	// Initialize everything.
	OnChangeZeroOut();
}

CCh16Ex2Doc::~CCh16Ex2Doc()
{
	// Be sure to delete the pointers allocated in the constructor.
	if(m_pMyObj != NULL)
	{
		delete m_pMyObj;
		m_pMyObj = NULL;
	}
	if(m_pMyObj2 != NULL)
	{
		delete m_pMyObj2;
		m_pMyObj2 = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2Doc serialization

void CCh16Ex2Doc::Serialize(CArchive& ar)
{
	// Called to Serialize or Deserialize the document's contents.

	if(ar.IsStoring())
	{
		// TODO: add storing code here

		// Serialize the primitive types.
		ar << m_int << m_double << m_byte << m_str;

		// Serialize the objects derived from CObject.
		m_myObj.Serialize(ar);
		m_pMyObj->Serialize(ar);

		// Serialize the objects NOT derived from CObject.
		ar << m_myObj2.m_intObj2 << m_myObj2.m_strObj2;
		ar << m_pMyObj2->m_intObj2 << m_pMyObj2->m_strObj2;
	}
	else
	{
		// TODO: add loading code here

		// Deserialize the primitive types.
		ar >> m_int >> m_double >> m_byte >> m_str;

		// Deserialize the objects derived from CObject.
		m_myObj.Serialize(ar);
		m_pMyObj->Serialize(ar);

		// Deserialize the objects NOT derived from CObject.
		ar >> m_myObj2.m_intObj2 >> m_myObj2.m_strObj2;
		ar >> m_pMyObj2->m_intObj2 >> m_pMyObj2->m_strObj2;

		// Force redrawing.
		UpdateAllViews(NULL);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2Doc diagnostics

#ifdef _DEBUG
void CCh16Ex2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCh16Ex2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2Doc commands

void CCh16Ex2Doc::OnChangeEditValues() 
{
	// TODO: Add your command handler code here
	// Respond to the Assign Non-Zero Values command.
	m_int = 1;
	m_double = 1.0;
	m_byte = 255;
	m_str = "This is a CString.";

	m_myObj.m_intObj = 2;
	m_myObj.m_strObj = "String inside CMyObject embedded.";
	m_pMyObj->m_intObj = 3;
	m_pMyObj->m_strObj = "String inside CMyObject pointed to.";
	
	m_myObj2.m_intObj2 = 4;
	m_myObj2.m_strObj2 = "String inside CMyObject2 embedded.";
	m_pMyObj2->m_intObj2 = 5;
	m_pMyObj2->m_strObj2 = "String inside CMyObject2 pointed to.";

	// Redraw the sample values displayed in the view.
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

void CCh16Ex2Doc::OnChangeZeroOut() 
{
	// TODO: Add your command handler code here
	// Respond to the Zero Out Values command.
	m_int = 0;
	m_double = 0.0;
	m_byte = 0;
	m_str = "";

	m_myObj.m_intObj = 0;
	m_myObj.m_strObj = "";
	m_pMyObj->m_intObj = 0;
	m_pMyObj->m_strObj = "";
	
	m_myObj2.m_intObj2 = 0;
	m_myObj2.m_strObj2 = "";
	m_pMyObj2->m_intObj2 = 0;
	m_pMyObj2->m_strObj2 = "";

	// Redraw the sample values displayed in the view.
	UpdateAllViews(NULL);

	// I don't call SetModifiedFlag because zeroing out just
	//  alters the display so you can see the effect of reading
	//  values back in from the saved file.
}


BOOL CCh16Ex2Doc::OnNewDocument() 
{
	// Initialize a new document to zero values.

	// TODO: Add your specialized code here and/or call the base class
	OnChangeZeroOut();

	return CDocument::OnNewDocument();
}
