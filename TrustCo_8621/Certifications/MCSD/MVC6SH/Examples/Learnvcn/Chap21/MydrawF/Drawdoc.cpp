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
	ON_COMMAND(ID_TOOL_BRING_FWD, OnToolBringFwd)
	ON_UPDATE_COMMAND_UI(ID_TOOL_BRING_FWD, OnUpdateToolBringFwd)
	ON_COMMAND(ID_TOOL_BRING_FRONT, OnToolBringFront)
	ON_UPDATE_COMMAND_UI(ID_TOOL_BRING_FRONT, OnUpdateToolBringFront)
	ON_COMMAND(ID_TOOL_SEND_BACK, OnToolSendBack)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SEND_BACK, OnUpdateToolSendBack)
	ON_COMMAND(ID_TOOL_SEND_BEHIND, OnToolSendBehind)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SEND_BEHIND, OnUpdateToolSendBehind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDrawDoc construction/destruction

CMyDrawDoc::CMyDrawDoc()
{
	// TODO: add one-time construction code here
    m_pos = NULL;
    m_typeNext = shpRectangle;
    m_bTransparent = true;
    m_nColorNext = ID_COLOR_BLACK;
    m_bSelectionMode = false;
    m_typeFormer = m_typeNext;
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

// *********** For details, see the document Diagnost.doc in
//             \learnvcn\Chap 13 in the companion code.

#ifdef _DEBUG

// In debug builds, test the validity of the document and its
//  data members. MFC calls this function at appropriate times.
void CMyDrawDoc::AssertValid() const
{
	CDocument::AssertValid();

	// Test validity of view data members.
	//  The InRange helper function is in file Shape.h.
	//  I use ID_COLOR_LTGRAY + 1 below to account for a Custom Color.
	ASSERT(InRange(int(ID_COLOR_BLACK), int(ID_COLOR_LTGRAY + 1), int(m_nColorNext)));
	ASSERT(InRange(shpSelecting, shpEllipse, m_typeNext));
	ASSERT(InRange(shpRectangle, shpEllipse, m_typeFormer));
	// Uncomment the TRACE statement below to see how often
	//  MFC calls this function.
	//TRACE("\nIn CMyDrawDoc::AssertValid\n");

	// To test the validity of the shapes in the shape list, 
	//  we would need to derive a class from CObList, use that class
	//  as our data structure, and, in the new list class's
	//  AssertValid override, iterate the shape list, calling
	//  AssertValid for each shape. Check the Help index for
	//  "AssertValid member function" and double-click the subtopic
	//  "using."
	// Note that I do test the validity of shapes as they are
	//  created. See CMyDrawDoc::CreateShape.
}

// In debug builds, obtain a diagnostic dump of the document, the
//  view, and the stored shapes. MFC calls this function in
//  conjunction with a diagnostic dump of the view object. 
void CMyDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);

	// Dump the document's data members.
	//  "Insert" each item into the dump context object, dc.

	dc << "\n*** My document data:\n\n";
	dc << "\nm_typeNext = " << m_typeNext << " -- ";

	// See if we're in selection mode. If not, print shape type in effect.
	if(m_typeNext == shpSelecting)
		dc << "In selection mode";
	else
	   dc << (m_typeNext == shpRectangle ? "Rectangle" : "Ellipse");

	// Use arColorNames to print the color's name.
	dc << "\nm_nColorNext = " << m_nColorNext 
	   << " (" << arColorNames[m_nColorNext - ID_COLOR_BLACK] << ")";

	// Use the arithmetic if operator (?:) to print Boolean values.
	dc << "\nm_bTransparent = " << (m_bTransparent ? "true" : "false");
	dc << "\nm_bSelectionMode = " << (m_bSelectionMode ? "true" : "false");
	dc << "\nm_typeFormer = " << m_typeFormer << " -- "
	   << (m_typeNext == shpRectangle ? "Rectangle" : "Ellipse") << "\n\n";

	// Dump the shape list.
	dc << "\n*** Dump of the shape list:\n";
	m_listShapes.Dump(dc);
	dc << "*** More MFC view data:\n";

}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyDrawDoc commands

CShape* CMyDrawDoc::CreateShape(ShpType st)
{
    ASSERT(st >= shpRectangle && st <= shpEllipse);

	try
	{
        // Uncomment the next line to test the exception handler.
		//AfxThrowMemoryException();

		switch(st)
		{
		case shpRectangle:
			{
				CShpRectangle* pRectangle = new CShpRectangle;
				ASSERT(pRectangle != NULL);
				m_listShapes.AddHead(pRectangle);
				ASSERT_VALID(pRectangle);	// Added for diagnostics
			}
			break;
		case shpEllipse:
			{
				CShpEllipse* pEllipse = new CShpEllipse;
				ASSERT(pEllipse != NULL);
				m_listShapes.AddHead(pEllipse);
				ASSERT_VALID(pEllipse);		// Added for diagnostics
			}
			break;
		default: ;  // Nothing
		}
	}
	catch(CMemoryException* e)
	{
        // A memory allocation probably failed
        CString s = "MyDraw Exception: ";
        s += "Unable to allocate memory for a new shape\n";
        AfxMessageBox(s);
        e->Delete();
    }


    // Return the object just created
    if(m_listShapes.GetCount() > 0)         
        return (CShape*)m_listShapes.GetHead();     
    else
        return NULL;
}


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

void CMyDrawDoc::GetDocSizes(int nMapMode, CSize &sizeTotal, CSize &sizePage, CSize &sizeLine)
{
    // Pass it three CSizes and get back sizeTotal, sizePage, sizeLine
    // (Could perform some sort of check of the mapping mode here)

	// Width and height of our two-page drawing surface.
    sizeTotal = CSize(1600, 925);

    // sizePage and sizeLine are same as CScrollView defaults
    sizePage = CSize(sizeTotal.cx / 10, sizeTotal.cy / 10);
    sizeLine = CSize(sizePage.cx / 10, sizePage.cy / 10);
}

// Exercise 1, Chapter 11
// Added to support deleting the selected shape rather than the
//  latest shape, after Chapter 18 adds selection.
void CMyDrawDoc::DeleteSelectedShape()
{
	// Iterate the shapes
	CObject* pShape;
	POSITION pos1, pos2;  // pos1 iterates, pos2 deletes
	// The for loop starts at head of list, 
	//  ends when pos1 becomes NULL.
	// The loop sets pos2 = pos1 so we can delete that item if needed.
	// The loop advances by calling CObList::GetNext.
    for(pos1 = m_listShapes.GetHeadPosition(); (pos2 = pos1) != NULL;)   
	{
	    // If current shape is selected, delete it.
        if(((CShape*)m_listShapes.GetNext(pos1))->m_bSelected)       
		{
			// Save the old pointer for deletion.
            pShape = m_listShapes.GetAt(pos2);
		    m_listShapes.RemoveAt(pos2);
            delete pShape; // Delete to avoid memory leak. 
			break;		   // Exit loop now that selection found.
		}
	}   
}

// Get the position of the selected shape in the list.
//  NULL if there is no selected shape.
POSITION CMyDrawDoc::GetSelectedShape()
{
	CShape* pShape;
	POSITION pos1, pos2;
	pos1 = m_listShapes.GetHeadPosition();
	while(pos1 != NULL)
	{
		// Store the position for possible return.
		pos2 = pos1;
		pShape = (CShape*)m_listShapes.GetNext(pos1);
		// See if the shape is selected.
		if(pShape != NULL && pShape->m_bSelected)
			return pos2; // This is the selected shape.
	}
	return NULL;  // There is no selected shape.
}

// Bring the selected shape one place forward in the list
//  (one layer up).
void CMyDrawDoc::OnToolBringFwd() 
{
	// TODO: Add your command handler code here
	// Get the selected shape, if any.
	POSITION pos = GetSelectedShape();
    // This command available only if there	is a selection
	ASSERT(pos != NULL); 
	// It's also unavailable if the shape is already on top.
	POSITION posHead = m_listShapes.GetHeadPosition();
	if(pos == posHead)
		return;
	// Get a pointer to the selected shape.
	CShape* pShapeSel = (CShape*)m_listShapes.GetAt(pos);
	ASSERT(pShapeSel != NULL);
	// Save the selected shape's position in the list.
	POSITION posSel = pos;
	// Start iterating towards head of list.
	//  First GetPrev call points to selected shape still.
	//  But pos becomes position of previous shape.
	CShape* pShapeBefore = (CShape*)m_listShapes.GetPrev(pos);
	// Save the previous shape's position.
	POSITION posBefore = pos;
	// Second GetPrev call points to previous shape.
	//  If pos becomes NULL, we've passed the head.
	pShapeBefore = (CShape*)m_listShapes.GetPrev(pos);
	ASSERT(pShapeSel != pShapeBefore);
	// Is the selected shape already the topmost shape?
	//  If so, don't reorder the list.
	if(pShapeBefore == NULL)
		return;
	// Swap the two shapes.
	m_listShapes.SetAt(posBefore, pShapeSel);
	m_listShapes.SetAt(posSel, pShapeBefore);
	ASSERT_VALID(&m_listShapes);
	UpdateAllViews(NULL);
}

// True if a shape is selected, false if not.
bool CMyDrawDoc::SelectionExists()
{
	CShape* pShape;
	POSITION pos = m_listShapes.GetHeadPosition();
	while(pos != NULL)
	{
		pShape = (CShape*)m_listShapes.GetNext(pos);
		if(pShape != NULL && pShape->m_bSelected)
			return true;
	}
	return false;	
}

void CMyDrawDoc::OnUpdateToolBringFwd(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(SelectionExists());
}

// Bring the selected shape to the front of the list,
//  making it the topmost shape (highest layer).
void CMyDrawDoc::OnToolBringFront() 
{
	// TODO: Add your command handler code here
	// Get position of the selected shape.
	POSITION posSel = GetSelectedShape();
    // This command available only if there	is a selection
	ASSERT(posSel != NULL);
	// Skip the rest if selected shape is already at head.
	POSITION posHead = m_listShapes.GetHeadPosition();
	if(posSel == posHead)
		return;
	// Get a pointer to the selected shape.
	CShape* pShapeSel = (CShape*)m_listShapes.GetAt(posSel);
	ASSERT(pShapeSel != NULL);
	// Add a new element at head of list, containing pointer to
	//  the selected shape.
	posHead = m_listShapes.AddHead(pShapeSel);
	ASSERT(posHead != NULL);
	// Remove the old node for the selected shape.
	m_listShapes.RemoveAt(posSel);
	ASSERT_VALID(&m_listShapes);
	UpdateAllViews(NULL);
}

void CMyDrawDoc::OnUpdateToolBringFront(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(SelectionExists());	
}

// Move the selected shape to the tail of the list,
//  making it the rearmost shape (lowest layer).
void CMyDrawDoc::OnToolSendBack() 
{
	// TODO: Add your command handler code here
	// Get position of the selected shape.
	POSITION posSel = GetSelectedShape();
    // This command available only if there	is a selection
	ASSERT(posSel != NULL);
	// Skip the rest if selected shape is already at tail.
	POSITION posTail = m_listShapes.GetTailPosition();
	if(posSel == posTail)
		return;
	// Get a pointer to the selected shape.
	CShape* pShapeSel = (CShape*)m_listShapes.GetAt(posSel);
	ASSERT(pShapeSel != NULL);
	// Add a new element at tail of list, containing pointer to
	//  the selected shape.
	posTail = m_listShapes.AddTail(pShapeSel);
	ASSERT(posTail != NULL);
	// Remove the old node for the selected shape.
	m_listShapes.RemoveAt(posSel);
	ASSERT_VALID(&m_listShapes);
	UpdateAllViews(NULL);
}

void CMyDrawDoc::OnUpdateToolSendBack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(SelectionExists());
}

// Move the selected shape one place back in the list
//  (one layer lower).
void CMyDrawDoc::OnToolSendBehind() 
{
	// TODO: Add your command handler code here
	// Get the selected shape, if any.
	POSITION pos = GetSelectedShape();
    // This command available only if there	is a selection
	ASSERT(pos != NULL);  
	// It's also unavailable if shape is already on bottom.
	POSITION posTail = m_listShapes.GetTailPosition();
	if(pos == posTail)
		return;
	// Get a pointer to the selected shape.
	CShape* pShapeSel = (CShape*)m_listShapes.GetAt(pos);
	ASSERT(pShapeSel != NULL);
	// Save the selected shape's position in the list.
	POSITION posSel = pos;
	// Start iterating towards tail of list.
	//  First GetNext call points to selected shape still.
	//  But pos becomes position of next shape.
	CShape* pShapeAfter = (CShape*)m_listShapes.GetNext(pos);
	// Save the next shape's position.
	POSITION posAfter = pos;
	// Second GetNext call points to next shape.
	//  If pos becomes NULL, we've passed the tail.
	pShapeAfter = (CShape*)m_listShapes.GetNext(pos);
	ASSERT(pShapeSel != pShapeAfter);
	// Is the selected shape already the bottommost shape?
	//  If so, don't reorder the list.
	if(pShapeAfter == NULL)
		return;
	// Swap the two shapes.
	m_listShapes.SetAt(posAfter, pShapeSel);
	m_listShapes.SetAt(posSel, pShapeAfter);
	ASSERT_VALID(&m_listShapes);
	UpdateAllViews(NULL);
}

void CMyDrawDoc::OnUpdateToolSendBehind(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(SelectionExists());
}
