#pragma once
#include <memory>
#include "Task.h"
#include "ITitleChanger.h"

class BaseTitle : public Task{
protected:
	std::shared_ptr<ITitleChanger> spTitleChanger;	// タイトルナイシーケンス制御用

public:
	BaseTitle(const std::shared_ptr<ITitleChanger> changer);
	~BaseTitle(void);

	virtual void Initialize() override {}
	virtual void Finalize() override;
	virtual void Draw() override;
	virtual void Update() override {}

};

