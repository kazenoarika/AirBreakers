#pragma once

typedef enum{
	eInterMenu,
	eInterStageSelect,
	eInterSW,
	eInterMaterial,
	eInterSave,
	eInterGoToScenePlay,

	eInterNone
}eInter;

class IIntervalChanger
{
public:
	virtual ~IIntervalChanger(void)=0;
	virtual void ChangeInterval(eInter nextInterval)=0;
};

