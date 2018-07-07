
// MFCApplication2Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define IDT_TIMER1		50001

// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMFCApplication2Dlg



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, m_Const(1)
	, m_dx(0)
	, m_dy(0)
	, m_Scale(1.)
	, m_PicDy(0)
	, mass(1)
	, m_nLEDType(0)
	, wasButtonPressed(false)
	, bitmap(nullptr)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CONSTINPUT, m_EditConst);
	DDX_Control(pDX, IDC_EDIT_MASS, m_EditMass);
	DDX_Radio(pDX, IDC_RADIO_F, m_nLEDType);
	
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CMFCApplication2Dlg::OnBnClickedButtonStart)
	ON_EN_CHANGE(IDC_EDIT_CONSTINPUT, &CMFCApplication2Dlg::OnEnChangeEditConstInput)
	ON_EN_CHANGE(IDC_EDIT_MASS, &CMFCApplication2Dlg::OnEnChangeEditMass)
	//ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_SCIN, &CMFCApplication2Dlg::OnBnClickedButtonScin)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMFCApplication2Dlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SCOUT, &CMFCApplication2Dlg::OnBnClickedButtonScout)
	ON_BN_CLICKED(IDC_RADIO_F, &CMFCApplication2Dlg::OnFRadioButtonClicked)
	ON_BN_CLICKED(IDC_RADIO_K, &CMFCApplication2Dlg::OnKRadioButtonClicked)
END_MESSAGE_MAP()


// ����������� ��������� CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	m_graf.SubclassDlgItem(IDC_STATIC_P, this);
	CRect rc;
	m_graf.GetWindowRect(rc);

	m_dx = rc.Width();
	m_dy = rc.Height();

	

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedButtonStart()
{
	// TODO: �������� ���� ��� ����������� �����������
	//SetTimer(IDT_TIMER1, 50, NULL);
	this->wasButtonPressed = true;
	GetDlgItem(IDC_STATIC_P)->Invalidate();
}


void CMFCApplication2Dlg::OnEnChangeEditConstInput()
{
	CString str;
	m_EditConst.GetWindowText(str);
	m_Const = atof(CW2A(str));
}
void CMFCApplication2Dlg::OnEnChangeEditMass()
{
	CString str;
	m_EditMass.GetWindowText(str);
	mass = atof(CW2A(str));
}





BOOL CMFCApplication2Dlg::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: �������� ������������������ ��� ��� ����� �������� ������
	if (MY_MSG1 == message)
		KillTimer(IDT_TIMER1);
	return CDialogEx::OnWndMsg(message, wParam, lParam, pResult);
}


void CMFCApplication2Dlg::OnBnClickedButtonScin()
{
	m_Scale *= 2.;
	m_graf.SetDrawAll(true);
	GetDlgItem(IDC_STATIC_P)->Invalidate();
}


void CMFCApplication2Dlg::OnBnClickedButtonScout()
{
	m_Scale /= 2.;
	m_graf.SetDrawAll(true);
	GetDlgItem(IDC_STATIC_P)->Invalidate();
}

void CMFCApplication2Dlg::OnFRadioButtonClicked()
{
	if (m_nLEDType == 1)
	{
		((CButton*)GetDlgItem(IDC_RADIO_F))->SetCheck(true);
		((CButton*)GetDlgItem(IDC_RADIO_K))->SetCheck(false);
		m_nLEDType = 0;
	}


}

void CMFCApplication2Dlg::OnKRadioButtonClicked()
{
	if (m_nLEDType == 0)
	{
		((CButton*)GetDlgItem(IDC_RADIO_F))->SetCheck(false);
		((CButton*)GetDlgItem(IDC_RADIO_K))->SetCheck(true);
		m_nLEDType = 1;
	}

}

void CMFCApplication2Dlg::OnBnClickedButtonSave()
{
	if (this->wasButtonPressed) {
		CImage img;
		img.Attach(*this->bitmap);
		img.Save(L"TheGraph.bmp", Gdiplus::ImageFormatBMP);

		MessageBox(_T("������ ������� ������� � ������� ���������� ��� ��������� TheGraph.bmp"), _T("���������� �������"),
			MB_ICONINFORMATION | MB_OK);
	}else
	{
		MessageBox(_T("����� ��������� ������ � �������� �����������, ������� ������� ���������� � ������� ��� � ������� ������ \"��������� ������\". ����������� �� ���� ������������."), _T("���������� �������"),
			MB_ICONEXCLAMATION | MB_OK);
	}
}

