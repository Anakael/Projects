#pragma once


// ���������� ���� CMyGraf

class CMyGraf : public CStatic
{
	DECLARE_DYNAMIC(CMyGraf)

public:
	CMyGraf(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CMyGraf();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	int m_curPt;//current vector position to stop draw
	void SetDrawAll(bool ball);
	int m_nPoints;
};
