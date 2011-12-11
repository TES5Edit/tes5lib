/*===========================================================================
 *
 * File:		SrLvlirecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrLvliRecord class.
 *
 *=========================================================================*/
#ifndef __SRLVLIRECORD_H
#define __SRLVLIRECORD_H


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
 * Begin Class CSrLvliRecord Definition
 *
 *=========================================================================*/
class CSrLvliRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrLvliRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pLvldData;
	CSrSubrecord*		m_pLvlfData;
	CSrSubrecord*		m_pLlctData;
	CSrSubrecord*		m_pLvloData;
	CSrSubrecord*		m_pLvlgData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrLvliRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrLvliRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrLvliRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrLvliRecord.H
 *=========================================================================*/
