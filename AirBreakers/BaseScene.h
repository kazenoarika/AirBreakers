#pragma once
#include <memory>
#include "Task.h"
#include "ISceneChanger.h"

class Input;
class BaseScene : public Task
{
protected:
	ISceneChanger* mSceneChanger;	// シーン通達用インターフェース
	int stdCount;
	std::shared_ptr<Input> pInput;	// キー入力情報

public:
	BaseScene(ISceneChanger* changer);
	~BaseScene(void);

	virtual void Initialize() override {}
	virtual void Finalize() override;
	virtual void Draw() override;
	virtual void Update() override {}

	/*== Get/Set ================*/
	int GetCount(){ return stdCount; }
};

