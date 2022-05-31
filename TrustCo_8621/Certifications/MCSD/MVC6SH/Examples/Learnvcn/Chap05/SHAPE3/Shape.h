////////////////////////////////////
// Shape.h

#include "crect.h"

// Constant for use in generating random types
const int NUM_TYPES = 3;

// Abstract base class: can't construct CShape objects,
//  only objects of its derived classes
class CShape
{
public:
    // Possible shape types
    enum ShpType            // Nested enum: qualify outside
                            //  mentions with CShape::
    {
        shpRectangle,
        shpEllipse
    };

// Constructors
    CShape() { m_rectShape = CRect(CPoint(0,0), CPoint(10,10)); 
                m_typeShape = shpRectangle; };
        
// Attributes
    void SetRect(CRect r) { m_rectShape = r; };

    CRect GetRect() const { return m_rectShape; };
    ShpType GetType() const { return m_typeShape; };
    // No SetType: type now determined by subclass

    virtual void Draw() = 0;    // Class is abstract; must override
    void Move(CPoint p);
               
// Implementation
protected:
    CRect m_rectShape;         // Bounding rectangle of shape
    ShpType m_typeShape;       // Rectangle, ellipse, ...

public:
    virtual ~CShape();
};

// Concrete subclass of abstract base class CShape
class CShpRectangle : public CShape
{
public:
// Constructors: initialize class, including instance counter
    CShpRectangle() { m_rectShape = CRect(CPoint(0,0), CPoint(10,10)); 
                      m_typeShape = shpRectangle; nCountShpRects++; };
    
    CShpRectangle(CRect r)
                { m_rectShape = r; m_typeShape = shpRectangle; 
                  nCountShpRects++; };

// Attributes inherited (SetType, GetRect, GetType)


// Operations (Move is inherited)

    void Draw();        // Overrides CShape::Draw

// Implementation
public:    
    // The static data member must be public so we can access
    //  it from outside objects of the class. The destructor 
    //  must be public so we can explicitly call delete on objects 
    //  of the class from outside objects of the class.

    // Data members inherited
    // Add
    static int nCountShpRects;    // Initialized at file scope
	                              //  in shape3.cpp

    ~CShpRectangle();    // Destructor: virtual because base 
	                     //  class destructor is
};

// Concrete subclass of abstract base class CShape
class CShpEllipse : public CShape
{
public:
// Constructors
    CShpEllipse() { m_rectShape = CRect(CPoint(0,0), CPoint(10,10)); 
                m_typeShape = shpEllipse; nCountShpElls++; };
    
    CShpEllipse(CRect r)
                { m_rectShape = r; m_typeShape = shpEllipse; nCountShpElls++; };

// Attributes inherited

// Operations (Move is inherited)

    void Draw();                // Overrides CShape::Draw

// Implementation
public:
    // Data members inherited
    // Add
    static int nCountShpElls;  // Initialized to zero automatically

    ~CShpEllipse();            // Destructor: virtual because base
                               // class destructor is
};



