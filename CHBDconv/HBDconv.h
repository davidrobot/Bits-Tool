// HBDconv.h: interface for the CHBDconv class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HBDCONV_H__E426CD72_3AFF_4EE9_ADA6_6BC3B07D9914__INCLUDED_)
#define AFX_HBDCONV_H__E426CD72_3AFF_4EE9_ADA6_6BC3B07D9914__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHBDconv  
{
public:
	CString HEX2BIN(CString sHEX_INPUT);
	CString BIN2HEX(CString sBIN_INPUT);
	CHBDconv();
	virtual ~CHBDconv();

};

#endif // !defined(AFX_HBDCONV_H__E426CD72_3AFF_4EE9_ADA6_6BC3B07D9914__INCLUDED_)
