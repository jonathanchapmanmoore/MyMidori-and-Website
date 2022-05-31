// StockData.h: interface for the CStockData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKDATA_H__731D8608_D586_11D2_9261_0080C7FA0C3E__INCLUDED_)
#define AFX_STOCKDATA_H__731D8608_D586_11D2_9261_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStockData : public CObject  
{
public:
	CString GetAsString();
	CStockData();

	// Construct from values
	CStockData( CString fund, COleDateTime date, double price ) :
		m_strFund( fund ), m_date( date ), m_dblPrice( price )
	{;}

	// Copy Constructor
	CStockData( const CStockData & sd ) :
		m_strFund( sd.m_strFund ), 
		m_date( sd.m_date ), 
		m_dblPrice( sd.m_dblPrice ) 
	{;}

	// Assignment operator
	const CStockData & operator=( const CStockData & sd )
	{
		m_strFund = sd.m_strFund;
		m_date = sd.m_date;
		m_dblPrice = sd.m_dblPrice;
		return *this;
	}

	// Comparison operators
	BOOL operator==( const CStockData & sd )
	{
		return ( m_strFund == sd.m_strFund &&
				 m_date == sd.m_date &&
				 m_dblPrice == sd.m_dblPrice );
	}

	BOOL operator<( const CStockData & );
	BOOL operator>( const CStockData & );


	// Check if fund name and date are the same
	BOOL IsConflictingEntry( const CStockData & sd )
	{
		return ( m_strFund == sd.m_strFund &&
				 m_date == sd.m_date );
	}


	virtual ~CStockData();

	// Accessor functions
	CString GetFund() { return m_strFund; }
	COleDateTime GetDate() { return m_date; }
	double GetPrice() { return m_dblPrice;}

protected:
	double m_dblPrice;
	COleDateTime m_date;
	CString m_strFund;

};

#endif // !defined(AFX_STOCKDATA_H__731D8608_D586_11D2_9261_0080C7FA0C3E__INCLUDED_)
