#pragma once
#include <memory>
#include "Task.h"
#include "ISceneChanger.h"

class Input;
class BaseScene : public Task
{
protected:
	ISceneChanger* mSceneChanger;	// �V�[���ʒB�p�C���^�[�t�F�[�X
	int stdCount;
	std::shared_ptr<Input> pInput;	// �L�[���͏��

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

