// Bits ToolDlg.cpp : implementation file
//
#include "CLabel\Label.h"
#include "CHBDconv\HBDconv.h"
#include "stdafx.h"
#include "Bits Tool.h"
#include "Bits ToolDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CLabel	m_link;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_STATIC_LINK, m_link);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitsToolDlg dialog

CBitsToolDlg::CBitsToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBitsToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBitsToolDlg)
	m_HEX = _T("");
	m_BIN = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBitsToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BIT0, m_bit[0]);
	DDX_Control(pDX, IDC_STATIC_BIT1, m_bit[1]);
	DDX_Control(pDX, IDC_STATIC_BIT2, m_bit[2]);
	DDX_Control(pDX, IDC_STATIC_BIT3, m_bit[3]);
	DDX_Control(pDX, IDC_STATIC_BIT4, m_bit[4]);
	DDX_Control(pDX, IDC_STATIC_BIT5, m_bit[5]);
	DDX_Control(pDX, IDC_STATIC_BIT6, m_bit[6]);
	DDX_Control(pDX, IDC_STATIC_BIT7, m_bit[7]);
	DDX_Control(pDX, IDC_STATIC_BIT8, m_bit[8]);
	DDX_Control(pDX, IDC_STATIC_BIT9, m_bit[9]);
	DDX_Control(pDX, IDC_STATIC_BIT10, m_bit[10]);
	DDX_Control(pDX, IDC_STATIC_BIT11, m_bit[11]);
	DDX_Control(pDX, IDC_STATIC_BIT12, m_bit[12]);
	DDX_Control(pDX, IDC_STATIC_BIT13, m_bit[13]);
	DDX_Control(pDX, IDC_STATIC_BIT14, m_bit[14]);
	DDX_Control(pDX, IDC_STATIC_BIT15, m_bit[15]);
	DDX_Control(pDX, IDC_STATIC_BIT16, m_bit[16]);
	DDX_Control(pDX, IDC_STATIC_BIT17, m_bit[17]);
	DDX_Control(pDX, IDC_STATIC_BIT18, m_bit[18]);
	DDX_Control(pDX, IDC_STATIC_BIT19, m_bit[19]);
	DDX_Control(pDX, IDC_STATIC_BIT20, m_bit[20]);
	DDX_Control(pDX, IDC_STATIC_BIT21, m_bit[21]);
	DDX_Control(pDX, IDC_STATIC_BIT22, m_bit[22]);
	DDX_Control(pDX, IDC_STATIC_BIT23, m_bit[23]);
	DDX_Control(pDX, IDC_STATIC_BIT24, m_bit[24]);
	DDX_Control(pDX, IDC_STATIC_BIT25, m_bit[25]);
	DDX_Control(pDX, IDC_STATIC_BIT26, m_bit[26]);
	DDX_Control(pDX, IDC_STATIC_BIT27, m_bit[27]);
	DDX_Control(pDX, IDC_STATIC_BIT28, m_bit[28]);
	DDX_Control(pDX, IDC_STATIC_BIT29, m_bit[29]);
	DDX_Control(pDX, IDC_STATIC_BIT30, m_bit[30]);
	DDX_Control(pDX, IDC_STATIC_BIT31, m_bit[31]);

	DDX_Control(pDX, IDC_STATIC_AXIS1, m_axis[1]);
	DDX_Control(pDX, IDC_STATIC_AXIS2, m_axis[2]);
	DDX_Control(pDX, IDC_STATIC_AXIS3, m_axis[3]);
	DDX_Control(pDX, IDC_STATIC_AXIS4, m_axis[4]);
	DDX_Control(pDX, IDC_STATIC_AXIS5, m_axis[5]);
	DDX_Control(pDX, IDC_STATIC_AXIS6, m_axis[6]);
	DDX_Control(pDX, IDC_STATIC_AXIS7, m_axis[7]);
	DDX_Control(pDX, IDC_STATIC_AXIS8, m_axis[8]);
	DDX_Control(pDX, IDC_STATIC_AXIS9, m_axis[9]);
	DDX_Control(pDX, IDC_STATIC_AXIS10, m_axis[10]);
	DDX_Control(pDX, IDC_STATIC_AXIS11, m_axis[11]);
	DDX_Control(pDX, IDC_STATIC_AXIS12, m_axis[12]);
	DDX_Control(pDX, IDC_STATIC_AXIS13, m_axis[13]);
	DDX_Control(pDX, IDC_STATIC_AXIS14, m_axis[14]);
	DDX_Control(pDX, IDC_STATIC_AXIS15, m_axis[15]);
	DDX_Control(pDX, IDC_STATIC_AXIS16, m_axis[16]);
	DDX_Control(pDX, IDC_STATIC_AXIS17, m_axis[17]);
	DDX_Control(pDX, IDC_STATIC_AXIS18, m_axis[18]);
	DDX_Control(pDX, IDC_STATIC_AXIS19, m_axis[19]);
	DDX_Control(pDX, IDC_STATIC_AXIS20, m_axis[20]);
	DDX_Control(pDX, IDC_STATIC_AXIS21, m_axis[21]);
	DDX_Control(pDX, IDC_STATIC_AXIS22, m_axis[22]);
	DDX_Control(pDX, IDC_STATIC_AXIS23, m_axis[23]);
	DDX_Control(pDX, IDC_STATIC_AXIS24, m_axis[24]);
	//{{AFX_DATA_MAP(CBitsToolDlg)
	DDX_Text(pDX, IDC_EDIT_HEX, m_HEX);
	DDV_MaxChars(pDX, m_HEX, 8);
	DDX_Text(pDX, IDC_EDIT_BIN, m_BIN);
	DDV_MaxChars(pDX, m_BIN, 32);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBitsToolDlg, CDialog)
	//{{AFX_MSG_MAP(CBitsToolDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_RESET, OnButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_INVERT, OnButtonInvert)
	ON_BN_CLICKED(IDC_CHECK33, OnCheck33)
	ON_BN_CLICKED(IDC_CHECK34, OnCheck34)
	ON_BN_CLICKED(IDC_CHECK35, OnCheck35)
	ON_BN_CLICKED(IDC_CHECK36, OnCheck36)
	ON_EN_CHANGE(IDC_EDIT_HEX, OnChangeEditHex)
	ON_EN_CHANGE(IDC_EDIT_BIN, OnChangeEditBin)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck)
	ON_BN_CLICKED(IDC_CHECK10, OnCheck)
	ON_BN_CLICKED(IDC_CHECK11, OnCheck)
	ON_BN_CLICKED(IDC_CHECK12, OnCheck)
	ON_BN_CLICKED(IDC_CHECK13, OnCheck)
	ON_BN_CLICKED(IDC_CHECK14, OnCheck)
	ON_BN_CLICKED(IDC_CHECK15, OnCheck)
	ON_BN_CLICKED(IDC_CHECK16, OnCheck)
	ON_BN_CLICKED(IDC_CHECK17, OnCheck)
	ON_BN_CLICKED(IDC_CHECK18, OnCheck)
	ON_BN_CLICKED(IDC_CHECK19, OnCheck)
	ON_BN_CLICKED(IDC_CHECK20, OnCheck)
	ON_BN_CLICKED(IDC_CHECK21, OnCheck)
	ON_BN_CLICKED(IDC_CHECK22, OnCheck)
	ON_BN_CLICKED(IDC_CHECK23, OnCheck)
	ON_BN_CLICKED(IDC_CHECK24, OnCheck)
	ON_BN_CLICKED(IDC_CHECK25, OnCheck)
	ON_BN_CLICKED(IDC_CHECK26, OnCheck)
	ON_BN_CLICKED(IDC_CHECK27, OnCheck)
	ON_BN_CLICKED(IDC_CHECK28, OnCheck)
	ON_BN_CLICKED(IDC_CHECK29, OnCheck)
	ON_BN_CLICKED(IDC_CHECK30, OnCheck)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck)
	ON_BN_CLICKED(IDC_CHECK32, OnCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitsToolDlg message handlers

BOOL CBitsToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	for(int i=0;i<32;i++)          //初始化状态
	{
		bBit[i]=false;
		bAxis[i]=false;
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBitsToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBitsToolDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBitsToolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


////////////////////////////////////////////////////////////////////////////////////////////


void CBitsToolDlg::OnButtonReset() 
{
	// TODO: Add your control notification handler code here

	int i_IDC_CHECK=IDC_CHECK1; //从IDC_CHECK1 1000开始计数

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK36;i_IDC_CHECK++) ////计数到 IDC_CHECK36
	{
		((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);
	}

	BitsMapBin();
	UpdateData(FALSE); 
	OnChangeEditBin();
	
}

void CBitsToolDlg::OnButtonInvert() 
{
	// TODO: Add your control notification handler code here

	/////////////////////// 取反操作 /////////////////////////////////////////////////////

	int i_IDC_CHECK=IDC_CHECK1;  //从IDC_CHECK1 1000开始计数

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK36;i_IDC_CHECK++) //计数到 IDC_CHECK36
	{

		if (((CButton*)GetDlgItem(i_IDC_CHECK))->GetCheck()) // 如果状态是选中
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);  //将状态设置为取消

		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);   //将状态设置为选中
			
		}
	}


	BitsMapBin();
	UpdateData(FALSE); 
	OnChangeEditBin();


}

/////////////////////////////       群选的功能   （暂未使用）///////////////////////////

void CBitsToolDlg::OnCheck33() 
{
	// TODO: Add your control notification handler code here

	int i_IDC_CHECK=IDC_CHECK1;  //从IDC_CHECK1 1000开始计数

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK8;i_IDC_CHECK++) //计数到 IDC_CHECK8 
	{

		if (((CButton*)GetDlgItem(IDC_CHECK33))->GetCheck()) // 如果状态是选中
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);  //将状态设置为选中

		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);   //将状态设置为取消
			
		}
	}
	
}

void CBitsToolDlg::OnCheck34() 
{
	// TODO: Add your control notification handler code here
	
	int i_IDC_CHECK=IDC_CHECK9;  //从IDC_CHECK9 1009开始计数

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK16;i_IDC_CHECK++)  //计数到 IDC_CHECK16
	{

		if (((CButton*)GetDlgItem(IDC_CHECK34))->GetCheck()) // 如果状态是选中
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);  //将状态设置为选中

		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);   //将状态设置为取消
			
		}
	}
	
	
}

void CBitsToolDlg::OnCheck35() 
{
	// TODO: Add your control notification handler code here
	
	int i_IDC_CHECK=IDC_CHECK17;  //从IDC_CHECK1 1017开始计数

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK24;i_IDC_CHECK++) //计数到 IDC_CHECK24
	{

		if (((CButton*)GetDlgItem(IDC_CHECK35))->GetCheck()) // 如果状态是选中
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);  //将状态设置为选中
		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);   //将状态设置为取消
			
		}
	}
	
	
}

void CBitsToolDlg::OnCheck36() 
{
	// TODO: Add your control notification handler code here
	
	int i_IDC_CHECK=IDC_CHECK25;  //从IDC_CHECK1 1025开始计数

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK32;i_IDC_CHECK++)  //计数到 IDC_CHECK32
	{

		if (((CButton*)GetDlgItem(IDC_CHECK36))->GetCheck()) // 如果状态是选中
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);  //将状态设置为选中

		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);   //将状态设置为取消
			
		}
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////

void CBitsToolDlg::BinMapBits()  //将二进制字符串与Bits对应
{
	INT iI;
	INT intLen;
	INT i_IDC_CHECK=1000;
	CString v_m_BIN;

	UpdateData(TRUE);          //获取控件的值

	intLen=m_BIN.GetLength();  //获取字符串长度
	v_m_BIN=m_BIN;
	v_m_BIN.MakeReverse();

	for (iI=0; iI<intLen; iI++) //赋值已有的BIN对应的bits
	{
		if (v_m_BIN[iI]=='1')
			{	((CButton*)GetDlgItem(i_IDC_CHECK+iI))->SetCheck(TRUE);
				bAxis[iI]=true;
				bBit[iI]=true;
		}
		if (v_m_BIN[iI]=='0')
			{	((CButton*)GetDlgItem(i_IDC_CHECK+iI))->SetCheck(FALSE);
				bAxis[iI]=false;
				bBit[iI]=false;
			}
	}

	for (; iI<32;iI++)   //赋值剩余的BIN状态（为空）到对应的bits 
	{	
		((CButton*)GetDlgItem(i_IDC_CHECK+iI))->SetCheck(FALSE);
		bAxis[iI]=false;
		bBit[iI]=false;
	}

	up_bit_bk(); //更新bit背景颜色
	up_axis_bk(); //更新axis背景颜色

}

////////////////////////////////////////////////////////////////////////////////////////

void CBitsToolDlg::BitsMapBin()  //将Bits与二进制字符串对应
{

	int iI;
	INT i_IDC_CHECK=1000;
	CString s_Bits;
	
	s_Bits.Empty();

	for (iI=0;iI<32;iI++)
	{
			if (((CButton*)GetDlgItem(i_IDC_CHECK+iI))->GetCheck()) // 如果状态是选中
			{
				s_Bits=s_Bits+"1";
				bAxis[iI]=true;
				bBit[iI]=true;
			}
			else
			{
				s_Bits=s_Bits+"0";
				bAxis[iI]=false;
				bBit[iI]=false;

			}
	}
	s_Bits.MakeReverse();
	m_BIN=s_Bits;
	m_BIN.TrimLeft("0"); //05.30.13 Changed : 显示字符串消去左边的0
	up_bit_bk(); //更新bit背景颜色
	up_axis_bk(); //更新axis背景颜色

}


////////////////////////////////////////////////////////////////////////////////////////


void CBitsToolDlg::OnChangeEditHex() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	CHBDconv m;

	UpdateData(TRUE);       //获取控件的值
	m_BIN=m.HEX2BIN(m_HEX);   //十六进制转二进制
	UpdateData(FALSE);      //更新控件的值
	BinMapBits();

	
}



void CBitsToolDlg::OnChangeEditBin() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	CHBDconv m;
	
	UpdateData(TRUE);       //获取控件的值
	m_HEX=m.BIN2HEX(m_BIN);   //十六进制转二进制
	UpdateData(FALSE);      //更新控件的值
	BinMapBits();



}



void CBitsToolDlg::OnCheck() 
{
	// TODO: Add your control notification handler code here
	BitsMapBin();
	UpdateData(FALSE); //更新控件的值
	OnChangeEditBin();


}

/////////////////////////////// 更新背景颜色  ///////////////////////////////////
void CBitsToolDlg::up_bit_bk() 
{
	COLORREF   clr = RGB(0,255,0);  

	for(int i=0;i<32;i++)
	{
		if (bBit[i]==true)
		{
			m_bit[i].SetTransparent(false);  // 背景不透明
			m_bit[i].SetBkColor(clr);        //设置背景颜色
		}
		else
		{
			m_bit[i].SetTransparent(true);   //背景透明

		}
	}

}


void CBitsToolDlg::up_axis_bk() 
{
	COLORREF   clr = RGB(0,255,255);  

	for(int i=1;i<25;i++)
	{
		if (bBit[i-1]==true)
		{
			m_axis[i].SetTransparent(false);   // 背景不透明
			m_axis[i].SetBkColor(clr);         //设置背景颜色
		}
		else
		{
			m_axis[i].SetTransparent(true);  //背景透明


		}
	}

}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_link.SetLink(TRUE,FALSE)  //设置网址超链接
		.SetTextColor(RGB(0,0,255))
		.SetFontUnderline(TRUE)
		.SetLinkCursor(LoadCursor(NULL,MAKEINTRESOURCE(32649)));

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
