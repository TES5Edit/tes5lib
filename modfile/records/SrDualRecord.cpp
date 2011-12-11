/*===========================================================================
 *
 * File:		SrDualRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srDualrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrDualRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
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
BEGIN_SRFIELDMAP(CSrDualRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrDualRecord Constructor
 *
 *=========================================================================*/
CSrDualRecord::CSrDualRecord () 
{
}
/*===========================================================================
 *		End of Class CSrDualRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrDualRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrDualRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrDualRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrDualRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrDualRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrDualRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrDualRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrDualRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrDualRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrDualRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrDualRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrDualRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrDualRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrDualRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrDualRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrDualRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrDualRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrDualRecord Set Field Methods
 *=========================================================================*/
