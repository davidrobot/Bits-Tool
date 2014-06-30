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
	bool Hex2Bin(CString sHex_input, CString &sBin_Output);
	bool Bin2Hex(CString sBin_Input, CString &sHex_Output);
	bool Dec2Bin(CString sDec_Input, CString &sBin_Output, bool bSigned = true);
	bool Bin2Dec(CString sBin_Input, CString &sDec_Output, bool bSigned = true);
	//下面函数是组合而来
	bool Hex2Dec(CString sHex_Input, CString &sDec_Output, bool bSigned = true);
	bool Dec2Hex(CString sDec_Input, CString &sHex_Output, bool bSigned = true);
	//

};

#endif // !defined(AFX_HBDCONV_H__E426CD72_3AFF_4EE9_ADA6_6BC3B07D9914__INCLUDED_)
