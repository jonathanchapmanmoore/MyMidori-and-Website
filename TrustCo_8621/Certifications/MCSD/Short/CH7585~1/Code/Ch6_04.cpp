template <> void AFXAPI SerializeElements <CStockData> 
( CArchive& ar, CStockData* pNewSD, int nCount )
{    
	for ( int i = 0; i < nCount; i++, pNewSD++ )    
	{
        // Serialize each CStockData object        
		pNewSD->Serialize( ar );
    }
}
