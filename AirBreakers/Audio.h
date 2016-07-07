#pragma once
class Audio
{
private:
	int mAudio;		// �Đ��n���h��
	int mVolume;	// �{�����[��
	bool flgPlay;	// �Đ��t���O
	bool flgLoop;	// ���[�v�t���O

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

