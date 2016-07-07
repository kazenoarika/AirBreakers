#pragma once
#include <string>

struct SubweponStatus{
		int Id;				// �ŗL�ԍ�ID
		std::string Name;	// ���O
		int Kind;			// ���
		int Damage;			// �^����_���[�W
		int HitArea;		// �����蔻��
		int Rappid;			// �A�˗�
		int Penetoration;	// �ђʗ�
		int LoadNumber;		// ���U��
		int Price;			// �l�i
		double Speed;		// �e��
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
