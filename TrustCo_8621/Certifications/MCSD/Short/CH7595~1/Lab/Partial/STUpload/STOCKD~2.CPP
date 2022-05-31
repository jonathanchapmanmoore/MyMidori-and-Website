// StockDataList.cpp: implementation of the CStockDataList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "STUpload.h"
#include "StockDataList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStockDataList::CStockDataList()
{

}

CStockDataList::~CStockDataList()
{

}

POSITION CStockDataList::AddSorted(CStockData &sdToAdd, errorstatus &err, POSITION pos)
{
	err = ok;

	if( !pos )
	{
		pos = GetHeadPosition();

		if (!pos) // empty list
			return AddHead( sdToAdd );
	}

	while( pos )
	{
		POSITION insertPos = pos;

		CStockData sdCurrent = GetNext( pos );

		if( sdToAdd == sdCurrent)
		{ err = duplicate_entry; return NULL; }

		if( sdToAdd.IsConflictingEntry( sdCurrent ))
		{ err = conflicting_entry; return insertPos; }
		
		if( sdToAdd < sdCurrent)
		{
			POSITION posTemp =
				InsertBefore( insertPos, sdToAdd );
			if( !posTemp ) err = fail;
			return posTemp;
		}
	} 
	
	// If we got here then add to the end of the list
	return AddTail( sdToAdd );

}


template <> void AFXAPI SerializeElements <CStockData> 
( CArchive& ar, CStockData* pNewSD, int nCount )
{    
	for ( int i = 0; i < nCount; i++, pNewSD++ )    
	{
        // Serialize each CStockData object        
		pNewSD->Serialize( ar );
    }
}
