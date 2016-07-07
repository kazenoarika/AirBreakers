#pragma once
/*============================================================ システム ================*/
class FPS{
	int mCount;					// カウンタ
	int count0t;				// 60フレームに1回基準となる時刻を記録する変数
	static const int N = 60;	// 平均をとるサンプル数
	static const int fps = 60;	// 設定したFPS
	int f[fps];					// 平均を計算するため60回の1臭時間を記録
	double ave;					// 平均値
public:
	FPS();
	~FPS();
	double retFPS();
	void Draw();
	void Wait();
};