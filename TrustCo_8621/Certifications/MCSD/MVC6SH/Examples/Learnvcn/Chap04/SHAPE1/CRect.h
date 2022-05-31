// CRect.h

#include "CPoint.h"

struct Rect
{
// Constructors
    Rect() { m_ptTopLeft = Point(); m_ptBotRight = Point(10,10); };
    Rect(Point tl, Point br) { m_ptTopLeft = tl; m_ptBotRight = br; };

// Attributes
    Point m_ptTopLeft;
    Point m_ptBotRight;

    void SetRect(Point tl, Point br)
                { m_ptTopLeft = tl; m_ptBotRight = br; };
    void SetRect(int x1, int y1, int x2, int y2)
                { m_ptTopLeft.x = x1; m_ptTopLeft.y = y1;
                  m_ptBotRight.x = x2; m_ptBotRight.y = y2; };
};