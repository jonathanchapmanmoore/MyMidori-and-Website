// SrvrItem.h : interface of the CSTUploadSrvrItem class
//

#if !defined(AFX_SRVRITEM_H__968EF0DF_7824_11D3_936D_0080C7FA0C3E__INCLUDED_)
#define AFX_SRVRITEM_H__968EF0DF_7824_11D3_936D_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSTUploadSrvrItem : public CDocObjectServerItem
{
	DECLARE_DYNAMIC(CSTUploadSrvrItem)

// Constructors
public:
	CSTUploadSrvrItem(CSTUploadDoc* pContainerDoc);

// Attributes
	CSTUploadDoc* GetDocument() const
		{ return (CSTUploadDoc*)CDocObjectServerItem::GetDocument(); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSTUploadSrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CSTUploadSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRVRITEM_H__968EF0DF_7824_11D3_936D_0080C7FA0C3E__INCLUDED_)
