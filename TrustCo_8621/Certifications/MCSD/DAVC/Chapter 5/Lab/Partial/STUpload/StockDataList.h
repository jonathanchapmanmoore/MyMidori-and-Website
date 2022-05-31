// StockDataList.h: interface for the CStockDataList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKDATALIST_H__5DC7BC17_D63F_11D2_9262_0080C7FA0C3E__INCLUDED_)
#define AFX_STOCKDATALIST_H__5DC7BC17_D63F_11D2_9262_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StockData.h"
#include <afxtempl.h>

class CStockDataList : public CList< CStockData, CStockData & >  
{
public:

	enum errorstatus
	{
		ok,
		duplicate_entry,
		conflicting_entry,
		fail
	};

	POSITION AddSorted( CStockData & sdToAdd, errorstatus & err, POSITION pos = NULL );

	CStockDataList();
	virtual ~CStockDataList();

};

#endif // !defined(AFX_STOCKDATALIST_H__5DC7BC17_D63F_11D2_9262_0080C7FA0C3E__INCLUDED_)
