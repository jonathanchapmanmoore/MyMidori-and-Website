////////////////////////////////////
//
// crect.h
//
////////////////////////////////////

#include "cpoint.h"

class CRect
{
public:
// Constructors
	CRect() { topLeft = CPoint(0,0); botRight = CPoint(10,10); };
	CRect(CPoint tl, CPoint br) { topLeft = tl; botRight = br; };

// Attributes
	CPoint topLeft;
	CPoint botRight;

	void SetRect(CPoint tl, CPoint br) { topLeft = tl; botRight = br; };
	void SetRect(int x1, int y1, int x2, int y2) { topLeft.x = x1; topLeft.y = y1; 
											  botRight.x = x2; botRight.y = y2; };
};
