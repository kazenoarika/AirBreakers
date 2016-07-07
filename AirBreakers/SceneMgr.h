#pragma once
#include <memory>
#include "iscenechanger.h"
#include "BaseScene.h"

class SceneMgr : public ISceneChanger, Task{
private:
	std::unique_ptr<BaseScene> mScene;
	eScene mNextScene;

public:
	SceneMgr(void);
	~SceneMgr(void);

	void Initialize();
	void Finalize();
	void Update();
	void Draw();

	void ChangeScene(eScene NextScene);
};

