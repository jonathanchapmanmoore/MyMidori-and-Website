// Shape.h: interface for the CShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPE_H__97288485_7254_11D2_991B_00C04FC29F5C__INCLUDED_)
#define AFX_SHAPE_H__97288485_7254_11D2_991B_00C04FC29F5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum ShpType
{
    shpRectangle,
    shpEllipse
};

class CShape : public CObject  
{
public:
	// Enable MFC serialization (file storage for class objects)
	DECLARE_SERIAL(CShape)

    // Constructors and operators
    // Default constructor 
	CShape();
	// Copy constructor
    CShape(const CShape& s)
    {
        m_boxShape = s.m_boxShape;
        m_bTransparent = s.m_bTransparent;
        m_nColorShape = s.m_nColorShape;
    }

    // Overloaded assignment operator
    CShape& operator=(const CShape& s)
    {
        m_boxShape = s.m_boxShape;
        m_bTransparent = s.m_bTransparent;
        m_nColorShape = s.m_nColorShape;
        return *this;
    }

    // Attributes - deliberately left public for easy access
    // Note: no longer need an m_typeShape member.
    CRect m_boxShape;
    bool m_bTransparent;
    UINT m_nColorShape;

    // Overridables and operations
    virtual void Draw(CDC* pDC) 
                     { TRACE("My Error: In CShape::Draw.\n");
                         ASSERT(FALSE); };
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CShape();

};

// Concrete subclass of abstract base class CShape
class CShpRectangle : public CShape
{
public:
    DECLARE_SERIAL(CShpRectangle)

    // Constructors are inherited from CShape.
    // Attributes inherited include:
    //  m_boxShape, m_bTransparent, m_nColorShape

    // Operations
    void Draw(CDC* pDC);    // Overrides CShape::Draw

// Implementation
public:
};

// Concrete subclass of abstract base class CShape
class CShpEllipse : public CShape
{
public:
    DECLARE_SERIAL(CShpEllipse)

    // Constructors are inherited from CShape.
    // Attributes inherited include: 
    //  m_boxShape, m_bTransparent, m_nColorShape

    // Operations
    void Draw(CDC* pDC);    // Overrides CShape::Draw

// Implementation
public:
};

#endif // !defined(AFX_SHAPE_H__97288485_7254_11D2_991B_00C04FC29F5C__INCLUDED_)
