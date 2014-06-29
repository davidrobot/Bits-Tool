// Bits ToolDlg.h : header file
//

#include "CLabel\Label.h" 
#include "CHBDconv\HBDconv.h"


#if !defined(AFX_BITSTOOLDLG_H__A6AC4DCD_723B_4EA8_ACC8_CD4EA06AB55A__INCLUDED_)
#define AFX_BITSTOOLDLG_H__A6AC4DCD_723B_4EA8_ACC8_CD4EA06AB55A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



/////////////////////////////////////////////////////////////////////////////
// CBitsToolDlg dialog

class CBitsToolDlg : public CDialog
{
// Construction
public:
	CBitsToolDlg(CWnd* pParent = NULL);	// standard constructor

	bool bBit[32];
	bool bAxis[32];
	CLabel	m_bit[32];
	CLabel	m_axis[25];
	bool bSigned;

// Dialog Data
	//{{AFX_DATA(CBitsToolDlg)
	enum { IDD = IDD_BITSTOOL_DIALOG };
	CString	m_HEX;
	CString	m_BIN;
	CString	m_DEC;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitsToolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	void BinMapBits(); //添加一个函数 二进制对应bits
	void BitsMapBin(); //添加一个函数 bits对应二进制
	void up_bit_bk();	 //更新bit背景颜色
	void up_axis_bk();	 //更新axis背景颜色

	// Generated message map functions
	//{{AFX_MSG(CBitsToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonReset();
	afx_msg void OnButtonInvert();
	afx_msg void OnCheck33();
	afx_msg void OnCheck34();
	afx_msg void OnCheck35();
	afx_msg void OnCheck36();
	afx_msg void OnChangeEditHex();
	afx_msg void OnChangeEditBin();
	afx_msg void OnCheckRange(UINT nID);
	afx_msg void OnChangeEditDec();
	afx_msg void OnCHECKSigned();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITSTOOLDLG_H__A6AC4DCD_723B_4EA8_ACC8_CD4EA06AB55A__INCLUDED_)
 
