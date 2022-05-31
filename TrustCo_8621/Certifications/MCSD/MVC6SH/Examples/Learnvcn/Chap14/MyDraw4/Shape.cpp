// Shape.cpp: implementation of the CShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyDraw.h"
#include "Shape.h"
#include "Resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

////////////////////////////////////
// Class CShape implementation

IMPLEMENT_SERIAL(CShape, CObject, 1)

CShape::CShape()
{
	m_boxShape.SetRect(0, 0, 0, 0);
    m_bTransparent = true;
    m_nColorShape = ID_COLOR_BLACK;
}

CShape::~CShape()
{

}


////////////////////////////////////
// Class CShpRectangle implementation

IMPLEMENT_SERIAL(CShpRectangle, CShape, 1)

void CShpRectangle::Draw(CDC* pDC)  // Virtual override
{
    pDC->Rectangle(m_boxShape);
}

////////////////////////////////////
// Class CShpEllipse implementation

IMPLEMENT_SERIAL(CShpEllipse, CShape, 1)

void CShpEllipse::Draw(CDC* pDC)  // Virtual override
{
    pDC->Ellipse(m_boxShape);
}


