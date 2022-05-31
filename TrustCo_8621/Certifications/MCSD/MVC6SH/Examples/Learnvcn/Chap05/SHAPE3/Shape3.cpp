// Shape3.cpp : Defines the entry point for the console application.
//


#include <stdafx.h>
#include "Shape.h"
#include <stdio.h>       // For printf
#include <assert.h>      // For assert
#include <stdlib.h>      // For rand, srand, abs
#include <time.h>        // For time

// Global function prototypes

int RandomCoord();
CShape::ShpType RandomType();

// Initialize static class members at file scope.
int CShpRectangle::nCountShpRects = 0;
int CShpEllipse::nCountShpElls = 0;

///////////////////////////////////
// main
int main(int argc, char* argv[])
{
    // Create a rectangle shape on the stack.
    CShpRectangle shp1;
    shp1.SetRect(CRect(CPoint(20, 20), CPoint(50, 50)));
    shp1.Draw();

    // Move a shape in coordinate space.
    shp1.Move(CPoint(25, 25));
    shp1.Draw();

    // Create an ellipse shape on the heap.
    CShape* pShp2 = new CShpEllipse(CRect(CPoint(100, 100),
        CPoint(150, 150)));
    assert(pShp2 != NULL);
    pShp2->Draw();

    delete pShp2;

    // Create 10 random shapes in an array.
    CPoint pt1, pt2;             // Declare these outside 
	                             //  the for loop!
    CRect rect;
    CShape* arShps[10];          // Array of CShape pointers
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; i++)
    {
        // Prepare a randomly located bounding rectangle.
        pt1 = CPoint(RandomCoord(), RandomCoord());
        pt2 = CPoint(RandomCoord(), RandomCoord());
        rect = CRect(pt1, pt2);

        // Generate a random shape type.
        if(CShape::shpRectangle == RandomType())
        {
            // Construct a rectangle shape and add to array.
            CShpRectangle* pShp = new CShpRectangle(rect);
            assert(pShp != NULL);   // Must check when 
			                        //  pShp is in scope.
            arShps[i] = pShp;       // Must add to array when pShp is
                                    //  in scope.
            // Print new total of objects of this type.
            printf("Number of rectangles: %d\n",
                CShpRectangle::nCountShpRects);
        }
        else
        {
            // Construct an ellipse shape and add to array.
            CShpEllipse* pShp = new CShpEllipse(rect);
            assert(pShp != NULL);
            arShps[i] = pShp;
            // Print new total of objects of this type.
            printf("Number of ellipses: %d\n", 
                CShpEllipse::nCountShpElls);
        }
        arShps[i]->Draw();              // Polymorphic function call
    }

    // Move a shape
    arShps[0]->Move(CPoint(20,20));     // Call inherited function.
    arShps[0]->Draw();                  // Polymorphic function call

    // Delete all shapes
    for(int j = 0; j < 10; j++)
    {
        delete arShps[j];    // Invoke virtual destructors.
    }

    return 0;
}

////////////////////////////////////
// Global Helper functions

// Generate a random positive coordinate within a 1000-by- 
//  1000-unit drawing area.
int RandomCoord()
{
    // Base new coordinate loosely on last coordinate.
    static int nLastCoord;    // Automatically initialized to 0,
                              //  then altered on each call

    // Get a pseudorandom number between 0 and RAND_MAX (=32,767).
    int nNextCoord = rand();
    int nFudge = rand() % 100;  // Generate a fudge factor between 
                                //  0 and 99.
    // Use the larger of new number and old number (+ fudge factor).
    // Constrain the number to a value between 0 and 999 (inclusive).
    nLastCoord = abs((nNextCoord > nLastCoord ? nNextCoord : 
        (nLastCoord + nFudge)) % 1000);
    return nLastCoord;
}

// Pseudorandomly generate a rectangle or ellipse shape type.
CShape::ShpType RandomType()
{
    // 0 to 1 (= shpRectangle to shpEllipse)
    return (CShape::ShpType)(rand() % NUM_TYPES);      
}
