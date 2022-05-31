// StockData.cpp: implementation of the CStockData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "STUpload.h"
#include "StockData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CStockData, CObject, 1)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStockData::CStockData()
{

}

CStockData::~CStockData()
{

}


CString CStockData::GetAsString()
{
	CString strTemp;
	CString strRet = m_strFund;
	strRet += "\t";
	strRet += m_date.Format( "%m/%d/%Y" );
	strRet += "\t";

	strTemp.Format( "%.2f", m_dblPrice );
	strRet += strTemp;

	return strRet;
}


// Based on list sort order Fund Name + Date
BOOL CStockData::operator<(const CStockData & sd)
{
	// Uses alphabetic string comparison operators
	if( m_strFund < sd.m_strFund) 
		return TRUE;
	if( m_strFund > sd.m_strFund) 
		return FALSE;
	// They're equal
	if( m_date < sd.m_date )
		return TRUE;
	
	return FALSE;
}

BOOL CStockData::operator>(const CStockData & sd)
{
	// Uses alphabetic string comparison operators
	if( m_strFund > sd.m_strFund) 
		return TRUE;
	if( m_strFund < sd.m_strFund) 
		return FALSE;
	// They're equal
	if( m_date > sd.m_date )
		return TRUE;
	
	return FALSE;
}


void CStockData::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_strFund;
		ar << m_date;
		ar << m_dblPrice;
	}
	else
	{
		ar >> m_strFund;
		ar >> m_date;
		ar >> m_dblPrice;
	}
}
