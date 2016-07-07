#pragma once
class Audio
{
private:
	int mAudio;		// 再生ハンドル
	int mVolume;	// ボリューム
	bool flgPlay;	// 再生フラグ
	bool flgLoop;	// ループフラグ

public:
	Audio(void);
	~Audio(void);
	void Play(){ flgPlay = true; }
	void Stop();
	void Initialize();
	void Update();

	void SetAudio(int audio){ mAudio = audio; }
	void SetLoopFlag(bool flag){ flgLoop = flag; }
	void SetVolume(int volume){ mVolume = volume; }
};

