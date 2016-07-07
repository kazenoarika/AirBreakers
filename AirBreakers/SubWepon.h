#pragma once
#include <string>

struct SubweponStatus{
		int Id;				// 固有番号ID
		std::string Name;	// 名前
		int Kind;			// 種類
		int Damage;			// 与えるダメージ
		int HitArea;		// 当たり判定
		int Rappid;			// 連射力
		int Penetoration;	// 貫通力
		int LoadNumber;		// 装填数
		int Price;			// 値段
		double Speed;		// 弾速
};

class Subwepon{
	private:
		enum{NAME_MAX = 64};

		SubweponStatus mStatus;

	public:
		Subwepon();
		~Subwepon();

		/*== Get/Set ================*/
		void SetSubwepon(SubweponStatus status);
		SubweponStatus GetStatus();

};
