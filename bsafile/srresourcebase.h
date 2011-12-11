/*===========================================================================
 *	
 * File:		Srresourcebase.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Defines the CSrResourceBase base abstract class.
 *
 *=========================================================================*/
#ifndef __SRRESOURCEBASE_H
#define __SRRESOURCEBASE_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "../common/srerrorhandler.h"
  #include "../common/srptrarray.h"
  #include "../common/sstring.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrResourceBase Definition
 *
 *=========================================================================*/
class CSrResourceBase {

  /*---------- Begin Protected Class Members --------------------*/
protected:
  CSString	m_Name;

  long		m_UserData;
  void*		m_pUserData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrResourceBase() { m_UserData = 0; m_pUserData = NULL; }
  virtual ~CSrResourceBase() { Destroy();  }
  virtual void Destroy (void) { m_Name.Empty();  }

	/* Abstract methods */
  virtual bool IsFolder (void) const = 0;

  	/* Check the resource name */
  bool IsName (const char* pString) { return stricmp(m_Name, pString) == 0; }  

  long	      GetUserData     (void) { return (m_UserData); }
  void*	      GetUserDataPtr  (void) { return (m_pUserData); }
  const char* GetName         (void) { return (m_Name); }

	/* Get the full filename with path for the resource */
  virtual const char* GetFullName (void) = 0;

	/* Set class members */
  void SetUserData    (const long    Value) { m_UserData  = Value; }
  void SetUserDataPtr (void*        pValue) { m_pUserData = pValue; }
  void SetName        (const char* pString) { m_Name      = pString; }

};

	/* Arrays of resources */
  typedef CSrPtrArray<CSrResourceBase>    CSrResourceArray;
  typedef CSrRefPtrArray<CSrResourceBase> CSrRefResourceArray;

/*===========================================================================
 *		End of Class CSrResourceBase Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File Srresourcebase.H
 *=========================================================================*/
