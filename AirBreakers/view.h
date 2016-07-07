#pragma once

class View{
	private:
		double dnX, dnY, exRate, viewAngle;

	public:
		View();
		~View();

		double GetdnX();
		double GetdnY();
		double GetExRate();
		double GetViewAngle();
};
