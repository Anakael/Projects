#pragma once
#include <vector>

struct Params
{
	double scaleA;
	double scaleF;
	double maxValueX;
	bool isRadians;
};
class CMyCalc
{
public:
	CMyCalc();
	~CMyCalc();
	
	void GetPoints( std::vector<CPoint>&, std::vector<CPoint>&, Params&);
};

