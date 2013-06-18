// Bits Tool.h : main header file for the BITS TOOL application
//

#if !defined(AFX_BITSTOOL_H__C26109E6_D8D7_4BBE_A9F4_0D6A5DCC6996__INCLUDED_)
#define AFX_BITSTOOL_H__C26109E6_D8D7_4BBE_A9F4_0D6A5DCC6996__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBitsToolApp:
// See Bits Tool.cpp for the implementation of this class
//

class CBitsToolApp : public CWinApp
{
public:
	CBitsToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitsToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBitsToolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITSTOOL_H__C26109E6_D8D7_4BBE_A9F4_0D6A5DCC6996__INCLUDED_)
