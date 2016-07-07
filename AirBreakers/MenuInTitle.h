#pragma once
#include <memory>
#include "basetitle.h"
#include "MenuMgr.h"

class Input;
class CMenuInTitle : public BaseTitle{
private:
	MenuMgr mMenuMgr;
	std::shared_ptr<Input>	mInput;

public:
	CMenuInTitle(const std::shared_ptr<ITitleChanger> changer);
	~CMenuInTitle(void);

	virtual void Initialize()	override;
	virtual void Finalize()		override;
	virtual void Draw()			override;
	virtual void Update()		override;

};

