#pragma once
#include <memory>
#include "ITitleChanger.h"
#include "BaseTitle.h"

class CTitleMgr : public ITitleChanger, Task{
private:
	std::unique_ptr<BaseTitle> spTitle;
	eStateTitleMode mNextTitle;
	std::shared_ptr<ITitleChanger> changer;

public:
	CTitleMgr(void);
	~CTitleMgr(void);

	virtual void Initialize() override {}
	virtual void Finalize() override;
	virtual void Draw() override;
	virtual void Update() override {}

	void ChangeScene(eStateTitleMode NextTitel);
};

