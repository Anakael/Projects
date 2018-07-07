#include "stdafx.h"
#include "MyCalc.h"
#include "MFCApplication2Dlg.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <fstream>

CMyCalc::CMyCalc()
{
}


CMyCalc::~CMyCalc()
{
}


void CMyCalc::GetPoints(std::vector<CPoint> &vecForce, std::vector<CPoint> &vecAcceleration, Params& params)
{
	CMFCApplication2Dlg *pDlg = (CMFCApplication2Dlg *)AfxGetMainWnd();
	if (pDlg)
	{
		double xFirstCoord = 0;
		double xLastCoord = pDlg->m_nLEDType ? 5 : M_PI / 2;

		double scaleA = 0;
		double scaleF = 0; 

		std::vector<double> vecAy;
		std::vector<double> vecFy;

		for( int n= 0; n < 565; n++)
		{
			CPoint ptA;
			CPoint ptF;
			ptA.x = n+5;
			ptF.x = n+5;
			double arg = xFirstCoord + (n*(xLastCoord - xFirstCoord) / (565. * pDlg->m_Scale));
			double angle = pDlg->m_nLEDType ? pDlg->m_Const : arg;
			double coef = pDlg->m_nLEDType ? arg : pDlg->m_Const / 180 * M_PI;


			//ÇÄÅÑÜ ÇÀÄÀ¨ÒÑß ÔÎÐÌÓËÀ ÄËß ÓÑÊÎÐÅÍÈß È ÄËß ÑÈËÛ
			vecAy.push_back(2*9.8*((0.5-sin(angle)-coef*cos(angle))/3) + arg);
			vecFy.push_back(2*pDlg->mass*9.8*((3*sin(angle) + 3*coef*cos(angle) - 1)/3));

			scaleA = max(scaleA, abs(vecAy[n]));
			scaleF = max(scaleF, abs(vecFy[n]));

			vecAcceleration.push_back(ptA);
			vecForce.push_back(ptF);
		}
		for (int n = 0; n < 565; n++)
		{
			vecAy[n] *= -105 / scaleA;
			vecFy[n] *= -105 / scaleF;

			vecAcceleration[n].y = vecAy[n];
			vecForce[n].y = vecFy[n];
		}

		params.isRadians = pDlg->m_nLEDType ? false : true;
		params.maxValueX = xFirstCoord + xLastCoord / pDlg->m_Scale;
		params.scaleA = scaleA;
		params.scaleF = scaleF;
	}
}
