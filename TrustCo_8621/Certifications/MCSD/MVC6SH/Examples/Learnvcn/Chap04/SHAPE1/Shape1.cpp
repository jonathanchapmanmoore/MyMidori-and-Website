// Shape1.cpp : Defines the entry point for the console application.
//

#include "Stdafx.h"
#include "Shape.h"
#include <Stdio.h>    // For printf, sprintf
#include <Assert.h>   // For assert
#include <Stdlib.h>   // For rand, srand, abs
#include <Time.h>     // For time
#include <String.h>   // For strcpy

// Global function prototypes
void DrawShape(Shape* pS);
void MoveShape(Shape* pS, Point p);
int RandomCoord();
ShpType RandomType();

const int COORD_MAX = 1000;

///////////////////////////////////
// main
int main(int argc, char* argv[])
{
    // Create a shape on the stack.
    Shape shp1;
    shp1.m_rectShape = Rect(Point(20, 20), Point(50, 50));
    shp1.m_typeShape = shpRectangle;
    DrawShape(&shp1);

    // Move a shape in coordinate space.
    MoveShape(&shp1, Point(25, 25));
    DrawShape(&shp1);

    // Create a shape on the heap.
    Shape* pShp2 = new Shape;
    assert(pShp2 != NULL);
    pShp2->m_rectShape = Rect(Point(100, 100), Point(150, 150));
    pShp2->m_typeShape = shpEllipse;
    DrawShape(pShp2);

    delete pShp2;

    // Create 20 random shapes in an array.
    Point pt1, pt2;
    Shape* arShps[20];              // Declare array of Shape pointers
    srand((unsigned)time(NULL));    // Seed random number generator
    for(int i = 0; i < 20; i++)
    {
        // Create next shape.
        Shape* pShp = new Shape;    // Create Shape, get pointer to it
        assert(pShp != NULL);
        // Give it some coordinates.
        pt1 = Point(RandomCoord(), RandomCoord());
        pt2 = Point(RandomCoord(), RandomCoord());
        pShp->m_rectShape = Rect(pt1, pt2);
        // Specify whether it's a rectangle or an ellipse.
        pShp->m_typeShape = RandomType();
        // Add it to the array.
        arShps[i] = pShp;           // Assign pointer to array element
        // "Draw" the shape (as a string).
        DrawShape(arShps[i]);
    }

    // Move a shape.
    MoveShape(arShps[0], Point(20,20));
    DrawShape(arShps[0]);

    // Delete all shapes.
    for(int j = 0; j < 20; j++)
    {
        delete arShps[j];
    }

    return 0;
}

////////////////////////////////////
// Global function definitions

// "Draw" the shape.
void DrawShape(Shape* pS)
{
    Rect rect = pS->m_rectShape;
    int x1 = rect.m_ptTopLeft.x;
    int y1 = rect.m_ptTopLeft.y;
    int x2 = rect.m_ptBotRight.x;
    int y2 = rect.m_ptBotRight.y;

    // Determine shape type, represented as a string.
    char szType[20];
    switch(pS->m_typeShape)
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
void MoveShape(Shape* pS, Point p /* New m_ptTopLeft */)
{
    Rect rect = pS->m_rectShape;
    int width = abs(rect.m_ptBotRight.x - rect.m_ptTopLeft.x);
    int height = abs(rect.m_ptBotRight.y - rect.m_ptTopLeft.y);

    // New m_ptTopLeft corner is p.
    pS->m_rectShape.m_ptTopLeft = p;
    // New m_ptBotRight corner calculated from p using size of shape.
    pS->m_rectShape.m_ptBotRight = Point(p.x + width, p.y + height);
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
    int nFudge = rand() % 100;  // Generate a fudge factor: 0 to 99
    // Use (larger of new number and old number) + fudge factor.
    nLastCoord = (nNextCoord > nLastCoord ? nNextCoord : 
                                            nLastCoord);
    // Restrict the number to a value between
    //  0 and COORD_MAX - 1 (inclusive).
    nLastCoord = (nLastCoord + nFudge) % COORD_MAX;
    return nLastCoord;
}

// Pseudorandomly generate a rectangle or ellipse shape type.
ShpType RandomType()
{
    // 0 to 1 (= shpRectangle to shpEllipse)
    return (ShpType)(rand() % NUM_TYPES);
}