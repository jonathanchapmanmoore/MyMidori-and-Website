// DrawDoc.cpp : implementation of the CMyDrawDoc class
//

#include "stdafx.h"
#include "MyDraw.h"

#include "DrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDrawDoc

IMPLEMENT_DYNCREATE(CMyDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyDrawDoc, CDocument)
	//{{AFX_MSG_MAP(CMyDrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDrawDoc construction/destruction

CMyDrawDoc::CMyDrawDoc()
{
	// TODO: add one-time construction code here
    m_pos = NULL;
}

CMyDrawDoc::~CMyDrawDoc()
{
}

BOOL CMyDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyDrawDoc serialization

void CMyDrawDoc::Serialize(CArchive& ar)
{	
	m_listShapes.Serialize(ar);
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
// CMyDrawDoc diagnostics

#ifdef _DEBUG
void CMyDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyDrawDoc commands

void CMyDrawDoc::DeleteLatestShape()
{
	ASSERT(!m_listShapes.IsEmpty());
    CShape* pShape = (CShape*)m_listShapes.RemoveHead();
    delete pShape;
}

void CMyDrawDoc::DeleteAllShapes()
{
	POSITION pos = m_listShapes.GetHeadPosition(); // NULL if empty
    while(pos != NULL)
    {
        delete m_listShapes.GetNext(pos);
    }
    m_listShapes.RemoveAll();
    SetModifiedFlag(false); // Nothing to save now
}

void CMyDrawDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	DeleteAllShapes();
    UpdateAllViews(NULL);

	CDocument::DeleteContents();
}

CShape* CMyDrawDoc::CreateShape(ShpType st)
{
	ASSERT(st >= shpRectangle && st <= shpEllipse);
    switch(st)
    {
    case shpRectangle:
        {
            CShpRectangle* pRectangle = new CShpRectangle;
            ASSERT(pRectangle != NULL);
            m_listShapes.AddHead(pRectangle);
        }
        break;
    case shpEllipse:
        {
            CShpEllipse* pEllipse = new CShpEllipse;
            ASSERT(pEllipse != NULL);
            m_listShapes.AddHead(pEllipse);
        }
        break;
    default: ;  // Nothing
    }

    // Return the object just created.
    if(m_listShapes.GetCount() > 0)         
        return (CShape*)m_listShapes.GetHead();     
    else
        return NULL;

}

void CMyDrawDoc::GetDocSizes(int nMapMode, CSize &sizeTotal,
							 CSize &sizePage, CSize &sizeLine)
{
	// Pass it 3 CSizes and get back sizeTotal, sizePage, sizeLine.
    // (Could perform some sort of check of the mapping mode here.)

    // For now, the size figures are in pixels
    // This will change to inches (in 0.01" units) in Step 7.
    sizeTotal = CSize(1000, 1600);

    // sizePage and sizeLine are same as CScrollView defaults.
    sizePage = CSize(sizeTotal.cx / 10, sizeTotal.cy / 10);
    sizeLine = CSize(sizePage.cx / 10, sizePage.cy / 10);

}
