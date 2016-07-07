#pragma once

typedef enum{
	eSceneTitle,
	eScenePlay,
	eSceneInterval,
	eSceneClear,

	eSceneNone
}eScene;

class ISceneChanger
{
public:
	ISceneChanger(void);
	~ISceneChanger(void);

	virtual void ChangeScene(eScene NextScene)=0;
};

