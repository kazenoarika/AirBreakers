#pragma once
#include <vector>
#include <memory>
#include "basetitle.h"
#include "Images.h"
#include "Audio.h"

class Input;
class CTopInTitle : public BaseTitle{
private:
	int mTimer;
	std::vector<std::shared_ptr<CImages>>	mGraphics;
	std::vector<std::shared_ptr<Audio>>		mAudios;
	std::shared_ptr<Input>					mInput;

	void LoadGraphicsToScript();

public:
	CTopInTitle(const std::shared_ptr<ITitleChanger> changer);
	~CTopInTitle(void);

	virtual void Initialize()	override;
	virtual void Finalize()		override;
	virtual void Draw()			override;
	virtual void Update()		override;
};

