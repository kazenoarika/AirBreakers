#pragma once
class Record
{
private:
	int mScore;
	int mDestroyed;
	int mTime;

public:
	Record(void);
	~Record(void);

	int GetScore()		const { return mScore;		}
	int GetDestroyed()	const { return mDestroyed;	}
	int GetTime()		const { return mTime;		}
};

