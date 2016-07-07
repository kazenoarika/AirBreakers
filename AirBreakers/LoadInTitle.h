#pragma once
#include <memory>
#include "basetitle.h"

class Input;
class CLoadInTitle : public BaseTitle{
private:
	std::shared_ptr<Input> mInput;

public:
	CLoadInTitle(const std::shared_ptr<ITitleChanger> changer);
	~CLoadInTitle(void);

	virtual void Initialize()	override;
	virtual void Finalize()		override;
	virtual void Draw()			override;
	virtual void Update()		override;
};

