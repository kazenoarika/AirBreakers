#pragma once
#include "Object.h"

struct BoardStatus{
	int Time;
	int Score;
	int HiScore;
	int Destroy;
	int Money;
};

class ScoreBoard : public Object{
private:
	int GhFontNumber[30];
	int GhFont[28];
	int GhCircle;
	int GhFrame;
	int AnimeCount;

public:
	ScoreBoard(int* GhBoard, UnitAdmin* unitadmin);
	~ScoreBoard();

	void DrawScore(BoardStatus* boStatus);
	void DrawSubwepon();

	/*==  ================*/
	void Initialize()	override;
	void Finalize()		override{}
	void Update()		override;
	void Draw()			override;
	void Draw(BoardStatus* boStatus);
};
