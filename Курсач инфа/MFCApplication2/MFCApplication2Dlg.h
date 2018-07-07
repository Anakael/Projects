
// MFCApplication2Dlg.h : ���� ���������
//

#pragma once
#include "MyGraf.h"
#include "afxwin.h"

enum { MY_MSG1 = WM_USER+1, MY_MSG2 };

// ���������� ���� CMFCApplication2Dlg
class CMFCApplication2Dlg : public CDialogEx
{
// ��������
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStart();
	CMyGraf m_graf;
	// amplitude
	int m_dx;
	int m_dy;
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	double m_Scale; // user defined scale
	afx_msg void OnBnClickedButtonScin();
	afx_msg void OnBnClickedButtonScout();
	int m_PicDy;

	afx_msg void OnFRadioButtonClicked();
	afx_msg void OnKRadioButtonClicked();

	int m_nLEDType;
	bool wasButtonPressed;
	double m_Const;
	double mass;
	CEdit m_EditConst;
	CEdit m_EditMass;
	afx_msg void OnEnChangeEditConstInput();
	afx_msg void OnEnChangeEditMass();
	afx_msg void OnBnClickedButtonSave();
	CBitmap* bitmap;
};
