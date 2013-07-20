// Bits ToolDlg.cpp : implementation file
//
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

	// һ�㻯���� DDX_Control(pDX,IDC_STATIC_BIT(0:31),m_bit(0:31))
	for(int i=0;i<32;i++)
	{
		DDX_Control(pDX,IDC_STATIC_BIT0+i,m_bit[i]);
	}

	//һ�㻯���� DDX_Control(pDX,IDC_STATIC_AXIS(1:24),m_axis(1:24))
	for(int j=1;j<25;j++)
	{
		DDX_Control(pDX,IDC_STATIC_AXIS1+j-1,m_axis[j]);
	}
	
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
	//
	ON_BN_CLICKED(IDC_CHECK33, OnCheck33)
	ON_BN_CLICKED(IDC_CHECK34, OnCheck34)
	ON_BN_CLICKED(IDC_CHECK35, OnCheck35)
	ON_BN_CLICKED(IDC_CHECK36, OnCheck36)
	//
	ON_EN_CHANGE(IDC_EDIT_HEX, OnChangeEditHex)
	ON_EN_CHANGE(IDC_EDIT_BIN, OnChangeEditBin)
	//
	//ʹ�� ON_CONTROL_RANGE ��Ӧһ���¼�
	ON_CONTROL_RANGE(BN_CLICKED,IDC_CHECK1,IDC_CHECK32,OnCheckRange)
	//
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
	for(int i=0;i<32;i++)          //��ʼ��״̬
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

	int i_IDC_CHECK=IDC_CHECK1; //��IDC_CHECK1 1000��ʼ����

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK36;i_IDC_CHECK++) ////������ IDC_CHECK36
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

	/////////////////////// ȡ������ /////////////////////////////////////////////////////

	int i_IDC_CHECK=IDC_CHECK1;  //��IDC_CHECK1 1000��ʼ����

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK36;i_IDC_CHECK++) //������ IDC_CHECK36
	{

		if (((CButton*)GetDlgItem(i_IDC_CHECK))->GetCheck()) // ���״̬��ѡ��
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);  //��״̬����Ϊȡ��

		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);   //��״̬����Ϊѡ��
			
		}
	}


	BitsMapBin();
	UpdateData(FALSE); 
	OnChangeEditBin();


}

/////////////////////////////       Ⱥѡ�Ĺ���   ����δʹ�ã�///////////////////////////

void CBitsToolDlg::OnCheck33() 
{
	// TODO: Add your control notification handler code here

	int i_IDC_CHECK=IDC_CHECK1;  //��IDC_CHECK1 1000��ʼ����

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK8;i_IDC_CHECK++) //������ IDC_CHECK8 
	{

		if (((CButton*)GetDlgItem(IDC_CHECK33))->GetCheck()) // ���״̬��ѡ��
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);  //��״̬����Ϊѡ��

		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);   //��״̬����Ϊȡ��
			
		}
	}
	
}

void CBitsToolDlg::OnCheck34() 
{
	// TODO: Add your control notification handler code here
	
	int i_IDC_CHECK=IDC_CHECK9;  //��IDC_CHECK9 1009��ʼ����

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK16;i_IDC_CHECK++)  //������ IDC_CHECK16
	{

		if (((CButton*)GetDlgItem(IDC_CHECK34))->GetCheck()) // ���״̬��ѡ��
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);  //��״̬����Ϊѡ��

		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);   //��״̬����Ϊȡ��
			
		}
	}
	
	
}

void CBitsToolDlg::OnCheck35() 
{
	// TODO: Add your control notification handler code here
	
	int i_IDC_CHECK=IDC_CHECK17;  //��IDC_CHECK1 1017��ʼ����

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK24;i_IDC_CHECK++) //������ IDC_CHECK24
	{

		if (((CButton*)GetDlgItem(IDC_CHECK35))->GetCheck()) // ���״̬��ѡ��
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);  //��״̬����Ϊѡ��
		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);   //��״̬����Ϊȡ��
			
		}
	}
	
	
}

void CBitsToolDlg::OnCheck36() 
{
	// TODO: Add your control notification handler code here
	
	int i_IDC_CHECK=IDC_CHECK25;  //��IDC_CHECK1 1025��ʼ����

	for (IDC_CHECK1;i_IDC_CHECK<=IDC_CHECK32;i_IDC_CHECK++)  //������ IDC_CHECK32
	{

		if (((CButton*)GetDlgItem(IDC_CHECK36))->GetCheck()) // ���״̬��ѡ��
		{

			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(TRUE);  //��״̬����Ϊѡ��

		}
		else
		{
			((CButton*)GetDlgItem(i_IDC_CHECK))->SetCheck(FALSE);   //��״̬����Ϊȡ��
			
		}
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////

void CBitsToolDlg::BinMapBits()  //���������ַ�����Bits��Ӧ
{
	INT iI;
	INT intLen;
	INT i_IDC_CHECK=1000;
	CString v_m_BIN;

	UpdateData(TRUE);          //��ȡ�ؼ���ֵ

	intLen=m_BIN.GetLength();  //��ȡ�ַ�������
	v_m_BIN=m_BIN;
	v_m_BIN.MakeReverse();

	for (iI=0; iI<intLen; iI++) //��ֵ���е�BIN��Ӧ��bits
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

	for (; iI<32;iI++)   //��ֵʣ���BIN״̬��Ϊ�գ�����Ӧ��bits 
	{	
		((CButton*)GetDlgItem(i_IDC_CHECK+iI))->SetCheck(FALSE);
		bAxis[iI]=false;
		bBit[iI]=false;
	}

	up_bit_bk(); //����bit������ɫ
	up_axis_bk(); //����axis������ɫ

}

////////////////////////////////////////////////////////////////////////////////////////

void CBitsToolDlg::BitsMapBin()  //��Bits��������ַ�����Ӧ
{

	int iI;
	INT i_IDC_CHECK=1000;
	CString s_Bits;
	
	s_Bits.Empty();

	for (iI=0;iI<32;iI++)
	{
			if (((CButton*)GetDlgItem(i_IDC_CHECK+iI))->GetCheck()) // ���״̬��ѡ��
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
	m_BIN.TrimLeft("0"); //05.30.13 Changed : ��ʾ�ַ�����ȥ��ߵ�0
	up_bit_bk(); //����bit������ɫ
	up_axis_bk(); //����axis������ɫ

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

	UpdateData(TRUE);       //��ȡ�ؼ���ֵ
	m_BIN=m.HEX2BIN(m_HEX);   //ʮ������ת������
	UpdateData(FALSE);      //���¿ؼ���ֵ
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
	
	UpdateData(TRUE);       //��ȡ�ؼ���ֵ
	m_HEX=m.BIN2HEX(m_BIN);   //ʮ������ת������
	UpdateData(FALSE);      //���¿ؼ���ֵ
	BinMapBits();



}



void CBitsToolDlg::OnCheckRange(UINT nID) 
{
	// TODO: Add your control notification handler code here
	BitsMapBin();
	UpdateData(FALSE); //���¿ؼ���ֵ
	OnChangeEditBin();


}

/////////////////////////////// ���±�����ɫ  ///////////////////////////////////
void CBitsToolDlg::up_bit_bk() 
{
	COLORREF   clr = RGB(0,255,0);  

	for(int i=0;i<32;i++)
	{
		if (bBit[i]==true)
		{
			m_bit[i].SetTransparent(false);  // ������͸��
			m_bit[i].SetBkColor(clr);        //���ñ�����ɫ
		}
		else
		{
			m_bit[i].SetTransparent(true);   //����͸��

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
			m_axis[i].SetTransparent(false);   // ������͸��
			m_axis[i].SetBkColor(clr);         //���ñ�����ɫ
		}
		else
		{
			m_axis[i].SetTransparent(true);  //����͸��


		}
	}

}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_link.SetLink(TRUE,FALSE)  //������ַ������
		.SetTextColor(RGB(0,0,255))
		.SetFontUnderline(TRUE)
		.SetLinkCursor(LoadCursor(NULL,MAKEINTRESOURCE(32649)));

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
