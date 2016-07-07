#pragma once
#include "basetitle.h"
class COptionInTitle :
	public BaseTitle
{
public:
	COptionInTitle(const std::shared_ptr<ITitleChanger> changer);
	~COptionInTitle(void);

	virtual void Initialize()	override;
	virtual void Finalize()		override;
	virtual void Draw()			override;
	virtual void Update()		override;
};

