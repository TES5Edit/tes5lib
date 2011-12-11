/*===========================================================================
 *
 * File:		SrSmqnrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrSmqnRecord class.
 *
 *=========================================================================*/
#ifndef __SRSMQNRECORD_H
#define __SRSMQNRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "srrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrSmqnRecord Definition
 *
 *=========================================================================*/
class CSrSmqnRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrSmqnRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pNnamData;
	CSrSubrecord*		m_pFnamData;
	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pXnamData;
	CSrSubrecord*		m_pPnamData;
	CSrSubrecord*		m_pCis2Data;
	CSrSubrecord*		m_pSnamData;
	CSrSubrecord*		m_pCitcData;
	CSrSubrecord*		m_pQnamData;
	CSrSubrecord*		m_pCtdaData;
	CSrSubrecord*		m_pDnamData;
	CSrSubrecord*		m_pRnamData;
	CSrSubrecord*		m_pMnamData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrSmqnRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrSmqnRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrSmqnRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrSmqnRecord.H
 *=========================================================================*/
