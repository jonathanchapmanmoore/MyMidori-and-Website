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
	shpSelecting,   // With selection tool in effect
    shpRectangle,
    shpEllipse
};

static CRect arHandles[8];

static CString arColorNames[11] =
{
    "Black",
    "Blue",
    "Green",
    "Cyan",
    "Red",
    "Magenta",
    "Yellow",
    "White",
    "Dark Gray",
    "Light Gray",
    "Custom Color"
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
		m_bSelected = s.m_bSelected;
    }

    // Overloaded assignment operator
    CShape& operator=(const CShape& s)
    {
        m_boxShape = s.m_boxShape;
        m_bTransparent = s.m_bTransparent;
        m_nColorShape = s.m_nColorShape;
		m_bSelected = s.m_bSelected;
        return *this;
    }

    // Attributes - deliberately left public for easy access
    // Note: no longer need an m_typeShape member.
    CRect m_boxShape;
    bool m_bTransparent;
    UINT m_nColorShape;
	bool m_bSelected;

    // Overridables and operations
    virtual void Draw(CDC* pDC, bool bSelectionModeOn) 
                     { TRACE("My Error: In CShape::Draw.\n");
                         ASSERT(FALSE); };
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	void DrawHandles(CDC *pDC);
	void CreateHandleRects();
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
    void Draw(CDC* pDC, bool bSelectionModeOn);    // Overrides CShape::Draw

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
    void Draw(CDC* pDC, bool bSelectionModeOn);    // Overrides CShape::Draw

// Implementation
public:
	void CreateHandleRects();
};

#endif // !defined(AFX_SHAPE_H__97288485_7254_11D2_991B_00C04FC29F5C__INCLUDED_)
