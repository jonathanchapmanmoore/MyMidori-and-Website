// CRect.h

#include "CPoint.h"

class CRect
{
public:
// Constructors
    CRect() 
        { m_ptTopLeft = CPoint(); m_ptBotRight = CPoint(10,10); };
    CRect(CPoint tl, CPoint br) 
        { m_ptTopLeft = tl; m_ptBotRight = br; };

// Attributes
    CPoint m_ptTopLeft;
    CPoint m_ptBotRight;

    void SetRect(CPoint tl, CPoint br) 
                { m_ptTopLeft = tl; m_ptBotRight = br; };
    void SetRect(int x1, int y1, int x2, int y2) 
                { m_ptTopLeft.x = x1; m_ptTopLeft.y = y1; 
                  m_ptBotRight.x = x2; m_ptBotRight.y = y2; };
};