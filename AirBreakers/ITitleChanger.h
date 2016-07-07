#pragma once

typedef enum{
	eStateTop,
	eStateMenu,
	eStateLoad,
	eStateOption,

	eStateNone
}eStateTitleMode;


class ITitleChanger
{
public:
	ITitleChanger(void);
	~ITitleChanger(void);

	virtual void ChangeScene(eStateTitleMode NextScene)=0;
};

