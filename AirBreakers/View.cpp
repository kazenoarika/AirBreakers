#include "DxLib.h"

#include "view.h"

View::View():
	dnX(0),
	dnY(0),
	exRate(1),
	viewAngle(0)
	{}

View::~View(){}

double View::GetdnX(){ return dnX; }
double View::GetdnY(){ return dnY; }
double View::GetExRate(){ return exRate; }
double View::GetViewAngle(){ return viewAngle; }
