/*===========================================================================
 *
 * File:		Srenitalchsubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	12 December 2011
 *
 * Description
 *
 *=========================================================================*/
#ifndef __SRENITALCHSUBRECORD_H
#define __SRENITALCHSUBRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "srsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/

	/* Standard ENIT subrecord size in bytes */
  #define SRENITALCH_SUBRECORD_SIZE	20

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/
#pragma pack(push, 1)

	/* Alchemy ENIT data structure */
  struct srenitalchdata_t 
  {
	dword		Value;
	int			Type;
	dword		Padding1;
	dword		Padding2;
	dword		UseSoundID;
  };

#pragma pack(pop)
/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrEnitAlchSubrecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrEnitAlchSubrecord : public CSrSubrecord 
{
  DECLARE_SRCLASS(CSrEnitAlchSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  srenitalchdata_t	m_Data;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

	/* Input/output the subrecord data */
  virtual bool ReadData  (CSrFile& File) { if (m_RecordSize > SRENITALCH_SUBRECORD_SIZE) return false; return File.Read(&m_Data,  m_RecordSize); }
  virtual bool WriteData (CSrFile& File) { if (m_RecordSize > SRENITALCH_SUBRECORD_SIZE) return false; return File.Write(&m_Data, m_RecordSize); }


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
	CSrEnitAlchSubrecord() {  }
	virtual void Destroy (void) { CSrSubrecord::Destroy(); }

			/* Change any matching formid in the subrecord */
  virtual dword ChangeFormID (const srformid_t NewID, const srformid_t OldID) 
  {
	if (m_Data.UseSoundID == OldID) 
	{
	  m_Data.UseSoundID = NewID;
	  return (1);
	}

	return (0); 
  }

  virtual dword CountUses (const srformid_t FormID) 
  {
	  if (FormID == m_Data.UseSoundID) return 1;
	  return 0; 
  }

		/* Fixup the modindex of formids */
  virtual bool FixupFormID (CSrFormidFixupArray& FixupArray) 
  {
	return SrFixupFormid(m_Data.UseSoundID, m_Data.UseSoundID, FixupArray);
  }

  	/* Copy the content from an existing subrecord */
  virtual bool Copy (CSrSubrecord* pSubrecord) {
	CSrEnitAlchSubrecord* pSubrecord1 = SrCastClassNull(CSrEnitAlchSubrecord, pSubrecord);
	m_RecordSize = SRENITALCH_SUBRECORD_SIZE;

	if (pSubrecord1 != NULL) 
	{
	  m_Data = pSubrecord1->GetAlchData();
	}
	else 
	{
	  memset(&m_Data, 0, sizeof(m_Data));
	}
	return (true);
  }

  	/* Create a class instance */
  static CSrSubrecord* Create (void) { return (new CSrEnitAlchSubrecord); }

	/* Get class members */
  srenitalchdata_t& GetAlchData	(void) { return (m_Data); }
  virtual byte*	    GetData		(void) { return (byte *)(&m_Data); }
 	
	/* Initialize a new record */
  void InitializeNew (void)
  {
	  CSrSubrecord::InitializeNew(); 
	  memset(&m_Data, 0, sizeof(m_Data)); 
	  m_RecordSize = SRENITALCH_SUBRECORD_SIZE;
  }

	/* Set class members */
  

};
/*===========================================================================
 *		End of Class CSrEnitAlchSubrecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrEnitAlchsubrecord.H
 *=========================================================================*/
