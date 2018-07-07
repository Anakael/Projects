
// MFCApplication2Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define IDT_TIMER1		50001

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно CMFCApplication2Dlg



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


// обработчики сообщений CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_graf.SubclassDlgItem(IDC_STATIC_P, this);
	CRect rc;
	m_graf.GetWindowRect(rc);

	m_dx = rc.Width();
	m_dy = rc.Height();

	

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedButtonStart()
{
	// TODO: добавьте свой код обработчика уведомлений
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
	// TODO: добавьте специализированный код или вызов базового класса
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

		MessageBox(_T("График успешно сохранён в рабочей директории под названием TheGraph.bmp"), _T("Сохранение графика"),
			MB_ICONINFORMATION | MB_OK);
	}else
	{
		MessageBox(_T("Чтобы сохранить график в качестве изображения, сначала введите информацию о системе тел и нажмите кнопку \"Построить график\". Изображение не было перезаписано."), _T("Сохранение графика"),
			MB_ICONEXCLAMATION | MB_OK);
	}
}

