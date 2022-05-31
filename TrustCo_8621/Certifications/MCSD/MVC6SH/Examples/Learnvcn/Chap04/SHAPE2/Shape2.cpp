// Shape2.cpp : Defines the entry point for the console application.
//

#include "Stdafx.h"
#include "Shape.h"
#include <Stdio.h>    // For printf, sprintf
#include <Assert.h>   // For assert
#include <Stdlib.h>   // For rand, srand, abs
#include <Time.h>     // For time
#include <String.h>   // For strcpy

// Global function prototypes
int RandomCoord();
CShape::ShpType RandomType();

const int COORD_MAX = 1000;

///////////////////////////////////
// main
int main(int argc, char* argv[])
{
    // Create a shape on the stack.
    CShape shp1;
    shp1.SetRect(CRect(CPoint(20, 20), CPoint(50, 50)));
    shp1.SetType(CShape::shpRectangle);
    shp1.Draw();

    // Move a shape in coordinate space.
    shp1.Move(CPoint(25, 25));
    shp1.Draw();

    // Create a shape on the heap.
    CShape* pShp2 = new CShape
                        (CRect(CPoint(100, 100), CPoint(150, 150)),
                         CShape::shpEllipse);
    assert(pShp2 != NULL);
    pShp2->Draw();

    delete pShp2;

    // Create 20 random shapes in an array.
    CPoint pt1, pt2;
    CRect rect;
    CShape* arShps[20];
    srand((unsigned)time(NULL));
    for(int i = 0; i < 20; i++)
    {
        CShape* pShp = new CShape();
        assert(pShp != NULL);
        pt1 = CPoint(RandomCoord(), RandomCoord());
        pt2 = CPoint(RandomCoord(), RandomCoord());
        rect = CRect(pt1, pt2);
        pShp->SetRect(rect);
        pShp->SetType(RandomType());
        arShps[i] = pShp;
        arShps[i]->Draw();
    }

    // Move a shape.
    arShps[0]->Move(CPoint(20,20));
    arShps[0]->Draw();

    // Delete all shapes.
    for(int j = 0; j < 20; j++)
    {
        delete arShps[j];
    }

    return 0;
}

////////////////////////////////////
// CShape definitions

void CShape::Draw()
{
    int x1 = m_rectShape.m_ptTopLeft.x;
    int y1 = m_rectShape.m_ptTopLeft.y;
    int x2 = m_rectShape.m_ptBotRight.x;
    int y2 = m_rectShape.m_ptBotRight.y;

    // Determine shape type, represented as a string.
    char szType[20];
    switch(m_typeShape)
    {
    case shpRectangle: strcpy(szType, "rectangle");
        break;
    case shpEllipse: sprintf(szType, "%s", "ellipse");
        break;
    default: strcpy(szType, "errorShapeType");
    };

    // "Draw" shape as a string.
    //  Example: "rectangle at (34, 76, 987, 800)"
    printf("%s at (%d,%d,%d,%d)\n", szType, x1, y1, x2, y2);
}

// Shift shape to new position p.
void CShape::Move(CPoint p /* New m_ptTopLeft */)
{
    int width = abs(m_rectShape.m_ptBotRight.x - 
                    m_rectShape.m_ptTopLeft.x);
    int height = abs(m_rectShape.m_ptBotRight.y - 
                     m_rectShape.m_ptTopLeft.y);

    m_rectShape.m_ptTopLeft = p;
    m_rectShape.m_ptBotRight = CPoint(p.x + width, p.y + height);
}

////////////////////////////////////
// Global Helper functions

// Generate a random positive coordinate
//  within a COORD_MAX by COORD_MAX drawing area.
int RandomCoord()
{
    // Base new coordinate loosely on last coordinate.
    static int nLastCoord;    // Automatically initialized to 0, 
                              //  then altered on each call.

    // Get a pseudorandom number between 0 and RAND_MAX (32,767).
    int nNextCoord = rand();
    int nFudge = rand() % 100;  // Generate a fudge factor: 0 to 99.
    // Use (larger of new number and old number) + fudge factor.
    // Restrict the number to a value between 
    //  0 and COORD_MAX - 1 (inclusive).
    nLastCoord = abs((nNextCoord > nLastCoord ? nNextCoord : 
                     (nLastCoord + nFudge)) % COORD_MAX);
    return nLastCoord;
}

// Pseudorandomly generate a rectangle or ellipse shape type.
CShape::ShpType RandomType()
{
    // 0 to 1 (= shpRectangle to shpEllipse)
    return (CShape::ShpType)(rand() % NUM_TYPES);
}