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
