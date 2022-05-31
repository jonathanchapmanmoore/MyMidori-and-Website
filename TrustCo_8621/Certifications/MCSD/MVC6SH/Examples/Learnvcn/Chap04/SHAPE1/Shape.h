// Shape.h

#include "CRect.h"

// Constant for use in generating random shape types
const int NUM_TYPES = 2;

// Possible shape types
enum ShpType                
{
    shpRectangle,
    shpEllipse
    // Could add others here
};

// The Shape class
struct Shape
{
    Rect m_rectShape;       // Bounding rectangle of shape
    ShpType m_typeShape;    // Rectangle, ellipse, and so on
};