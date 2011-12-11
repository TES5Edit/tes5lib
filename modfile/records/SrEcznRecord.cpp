/*===========================================================================
 *
 * File:		SrEcznRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srEcznrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrEcznRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrEcznRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEcznRecord Constructor
 *
 *=========================================================================*/
CSrEcznRecord::CSrEcznRecord () 
{
}
/*===========================================================================
 *		End of Class CSrEcznRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEcznRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrEcznRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrEcznRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEcznRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrEcznRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrEcznRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEcznRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrEcznRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrEcznRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEcznRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrEcznRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrEcznRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrEcznRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrEcznRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrEcznRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrEcznRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrEcznRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrEcznRecord Set Field Methods
 *=========================================================================*/
