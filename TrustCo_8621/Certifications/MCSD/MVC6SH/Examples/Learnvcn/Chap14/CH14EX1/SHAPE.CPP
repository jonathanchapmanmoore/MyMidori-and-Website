// Shape.cpp: implementation of the CShape class and subclasses.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyDraw.h"
#include "Shape.h"
#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// Class CShape
IMPLEMENT_SERIAL(CShape, CObject, 1)

CShape::CShape()
{

}

CShape::~CShape()
{

}

// Class CShpRectangle
IMPLEMENT_SERIAL(CShpRectangle, CShape, 1)

void CShpRectangle::Draw(CDC* pDC)  // Virtual override
{
    pDC->Rectangle(m_boxShape);
}

// Class CShpEllipse
IMPLEMENT_SERIAL(CShpEllipse, CShape, 1)

void CShpEllipse::Draw(CDC* pDC)  // Virtual override
{
    pDC->Ellipse(m_boxShape);
}
