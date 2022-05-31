// Shape.cpp

#include <stdafx.h>
#include "Shape.h"
#include <stdio.h>        // For printf
#include <stdlib.h>       // For abs

////////////////////////////////////
// CShape definitions

// Shift shape to new position.
void CShape::Move(CPoint p /* New topLeft */)
{
    // Get shape's size.
    int width = abs(m_rectShape.botRight.x - m_rectShape.topLeft.x);
    int height = abs(m_rectShape.botRight.y - m_rectShape.topLeft.y);

    // Set its new coordinates (move it).
    m_rectShape.topLeft = p;
    m_rectShape.botRight = CPoint(p.x + width, p.y + height);
}

// Empty destructor
CShape::~CShape()
{
}

////////////////////////////////
// CShpRectangle definitions

// Draw overrides base class version.
void CShpRectangle::Draw()
{
    // Get coordinates in shortened forms for ease of use in printf.
    int x1 = m_rectShape.topLeft.x;
    int y1 = m_rectShape.topLeft.y;
    int x2 = m_rectShape.botRight.x;
    int y2 = m_rectShape.botRight.y;

    // "Draw" the shape as a string like 
    //  "rectangle at (34, 76, 987, 800)".
    printf("rectangle at (%d,%d,%d,%d)\n", x1, y1, x2, y2);
}

// Virtual destructor: removes current rectangle object 
//  from total of such objects.
CShpRectangle::~CShpRectangle()
{
    nCountShpRects--;    // Decrement: we're destroying one.
}


/////////////////////////////////
// CShpEllipse definitions
void CShpEllipse::Draw()
{
    int x1 = m_rectShape.topLeft.x;
    int y1 = m_rectShape.topLeft.y;
    int x2 = m_rectShape.botRight.x;
    int y2 = m_rectShape.botRight.y;

    // "Draw" the shape as a string like 
    //  "ellipse at (34, 76, 987, 800)"
    printf("ellipse at (%d,%d,%d,%d)\n", x1, y1, x2, y2);
}

// Virtual destructor: removes current ellipse object from
//  total of such objects.
CShpEllipse::~CShpEllipse()
{
    nCountShpElls--;    // Decrement: we're destroying one.
}




