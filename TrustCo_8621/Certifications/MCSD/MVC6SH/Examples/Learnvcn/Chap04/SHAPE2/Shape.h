// Shape.h

#include "CRect.h"

// Constant for use in generating random types
const int NUM_TYPES = 2;

class CShape
{
public:
    // Possible shape types
    enum ShpType    // Nested enum
    {
        shpRectangle,
        shpEllipse
    };

// Constructors
    CShape() { m_rectShape = CRect(CPoint(), CPoint(10,10));
               m_typeShape = shpRectangle; };

    CShape(CRect r, ShpType t) { m_rectShape = r; m_typeShape = t; };

// Attributes
    void SetRect(CRect r) { m_rectShape = r; };
    void SetType(ShpType t) { m_typeShape = t; };

    CRect GetRect() const { return m_rectShape; };
    ShpType GetType() const { return m_typeShape; };

// Operations
    void Draw();
    void Move(CPoint p);
 
// Implementation
private:
    CRect m_rectShape;     // Bounding rectangle of shape
    ShpType m_typeShape;   // Rectangle, ellipse, and so on
};