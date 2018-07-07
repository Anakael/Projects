// MyGraf.cpp: файл реализации
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MyGraf.h"
#include "afxdialogex.h"
#include "MyCalc.h"
#include "MFCApplication2Dlg.h"
#include <string>
#define _USE_MATH_DEFINES
#include "math.h"

// диалоговое окно CMyGraf

IMPLEMENT_DYNAMIC(CMyGraf, CStatic)

CMyGraf::CMyGraf(CWnd* pParent /*=NULL*/)
	: CStatic()
	, m_curPt(0)
	, m_nPoints(0)
{

}

CMyGraf::~CMyGraf()
{
}

void CMyGraf::DoDataExchange(CDataExchange* pDX)
{
	CStatic::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyGraf, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// обработчики сообщений CMyGraf


void CMyGraf::OnPaint()
{
	CMFCApplication2Dlg *pDlg = (CMFCApplication2Dlg *)AfxGetMainWnd();
	CPaintDC dcO(this); // device context for painting
					   // TODO: добавьте свой код обработчика сообщений
					   // Не вызывать CDialogEx::OnPaint() для сообщений рисования
	CRect rc;
	GetClientRect(rc);

	delete(pDlg->bitmap);
	pDlg->bitmap = new CBitmap();


	pDlg->bitmap->CreateCompatibleBitmap(&dcO, rc.Width(), rc.Height());
	CDC dc;
	dc.CreateCompatibleDC(&dcO);
	CBitmap* pOldBitmap = dc.SelectObject(pDlg->bitmap);
	
	dc.FillSolidRect(&rc, RGB(35, 35, 35));

	

	CPen pn;
	CFont h;
	h.CreateFontW(15, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));
	dc.SelectObject(h);

	


	pn.CreatePen(PS_SOLID, 1, RGB(0xCC, 0xCC, 0xCC));
	dc.SetTextColor(RGB(0xCC, 0xCC, 0xCC));
	dc.TextOut(70, (rc.top + rc.bottom) / 2 - 5, _T("0"));


	HGDIOBJ pOld =  dc.SelectObject(pn);
	dc.MoveTo(rc.left + 80, (rc.top + rc.bottom) / 2);
	dc.LineTo(rc.right, (rc.top + rc.bottom) / 2);
	
	dc.SelectObject(pOld);

	CPen pl;
	pl.CreatePen(PS_SOLID, 1, RGB(75, 75, 75));
	dc.SelectObject(pl);
	dc.MoveTo(rc.left + 80, rc.top + 20);
	dc.LineTo(rc.left + 80, rc.bottom - 20);
	dc.MoveTo(rc.left + 80, rc.bottom - 20);
	dc.LineTo(rc.right, rc.bottom - 20);

	dc.MoveTo(rc.left + 75, rc.top + 25);
	dc.LineTo(rc.left + 85, rc.top + 25);
	dc.MoveTo(rc.left + 75, (rc.top + rc.bottom) / 4 + 15);
	dc.LineTo(rc.left + 85, (rc.top + rc.bottom) / 4 + 15);

	dc.MoveTo(rc.left + 75, (rc.top + rc.bottom) / 1.5 + 15);
	dc.LineTo(rc.left + 85, (rc.top + rc.bottom) / 1.5 + 15);
	dc.MoveTo(rc.left + 75, rc.bottom - 25);
	dc.LineTo(rc.left + 85, rc.bottom - 25);
	for (int i = (rc.right - rc.left + 80) / 4 + 15; i <= rc.right; i+= (rc.right - rc.left - 80) / 4)
	{
		dc.MoveTo(i, rc.bottom - 15);
		dc.LineTo(i, rc.bottom - 25);
	}
	dc.SelectObject(pOld);

	std::vector<CPoint> vecA;
	std::vector<CPoint> vecF;
	CMyCalc clc;
	Params params;
	clc.GetPoints( vecA , vecF, params);
	
	if (pDlg->wasButtonPressed)
	{
		int yGlobalOffset = (rc.top + rc.bottom) / 2;
		CPen pnA;
		pnA.CreatePen(PS_SOLID, 1, RGB(255, 100, 100));
		dc.SelectObject(pnA);
		bool wasDrawn = false;
		for (int i = 0; i < vecA.size(); i++)
		{
			CPoint ptU = vecA[i];
			ptU.Offset(0, pDlg->m_PicDy);
			ptU.Offset(0, yGlobalOffset);
			ptU.Offset(80, 20); // ДЛЯ ОСЕЙ
			if (ptU.y > rc.top && ptU.y < rc.bottom) 
			{
				if(!wasDrawn)
				{
					wasDrawn = true;
					dc.MoveTo(ptU);
				}
				else
				{
					dc.LineTo(ptU);
				}
			}
			else
			{
				wasDrawn = false;
			}
		}

		
		CPen pnF;
		pnF.CreatePen(PS_SOLID, 1, RGB(255, 255, 125));
		dc.SelectObject(pnF);

		wasDrawn = false;
		for (int i = 0; i < vecF.size(); i++)
		{
			CPoint ptU = vecF[i];
			ptU.Offset(0, pDlg->m_PicDy);
			ptU.Offset(0, yGlobalOffset);
			ptU.Offset(80, -20); // ДЛЯ ОСЕЙ
			if (ptU.y > rc.top && ptU.y < rc.bottom)
			{
				if (!wasDrawn)
				{
					wasDrawn = true;
					dc.MoveTo(ptU);
				}
				else
				{
					dc.LineTo(ptU);
				}
			}
			else
			{
				wasDrawn = false;
			}

		}
		dc.SetTextColor(RGB(255, 100, 100));

		CString str;

		str.Format(L"%.1lf ", params.scaleA); // CONVERT
		dc.TextOut(5, 20, str);
		str.Format(L"%.1lf ", params.scaleA/2); // CONVERT
		dc.TextOut(5, (rc.top + rc.bottom) / 4 + 10, str);
		str.Format(L"-%.1lf ", params.scaleA / 2); // CONVERT
		dc.TextOut(5, (rc.top + rc.bottom) / 1.5 + 10, str);
		str.Format(L"-%.1lf ", params.scaleA); // CONVERT
		dc.TextOut(5, rc.bottom - 30, str);
		
		dc.TextOut((rc.left + rc.right) / 3, 0, _T("█ -- a (ускорение), м/с^2"));

		dc.SetTextColor(RGB(255, 255, 125));
		str.Format(L"%.1lf ", params.scaleF); // CONVERT
		dc.TextOut(40, 20, str);
		str.Format(L"%.1lf ", params.scaleF/2); // CONVERT
		dc.TextOut(40, (rc.top + rc.bottom) / 4 + 10, str);
		str.Format(L"-%.1lf ", params.scaleF/2); // CONVERT
		dc.TextOut(40, (rc.top + rc.bottom) / 1.5 + 10, str);
		str.Format(L"-%.1lf ", params.scaleF); // CONVERT
		dc.TextOut(40, rc.bottom - 30, str);

		dc.TextOut((rc.left + rc.right) / 1.5, 0, _T("█ -- F (сила), Н"));
		dc.SetTextColor(RGB(0xCC, 0xCC, 0xCC));
		for (int i = 1; i < 5; i++)
		{
			int offsetForX = (rc.right - rc.left + 80) / 5;
			str.Format(L"%s= %.1lf%s",
				params.isRadians ? _T("α") : _T("μ"),
				(params.isRadians ? params.maxValueX/M_PI*180 : params.maxValueX)/4*i,
				params.isRadians ? _T("°") : _T("")
			);
			dc.TextOut(i * offsetForX +5, rc.bottom - 15, str);
		}
	}


	dcO.BitBlt(0, 0, rc.Width(), rc.Height(), &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBitmap);
}


void CMyGraf::SetDrawAll(bool ball)
{
	if (ball)
		m_curPt = m_nPoints;
	else
		m_curPt = 0;
}
