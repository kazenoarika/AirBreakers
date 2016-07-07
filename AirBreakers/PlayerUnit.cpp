#include <string>
#include "DxLib.h"

#include "PlayerUnit.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"

#include "UnitAdmin.h"
#include "Audio.h"

PlayerUnit::PlayerUnit(UnitAdmin* unitadmin):Unit(unitadmin){
	pUnitAdmin = unitadmin;
	mObjKind = eObjKindPlayer;

	Shooter[0] = &PlayerUnit::ShooterTwinStrike;
	Shooter[1] = &PlayerUnit::ShooterLanceShot;
	Shooter[2] = &PlayerUnit::ShooterRazr;
	Shooter[3] = &PlayerUnit::ShooterDrill;
	Shooter[4] = &PlayerUnit::ShooterParticle;
}

PlayerUnit::~PlayerUnit(){
}
void PlayerUnit::Initialize(){
	pInput = Game::Instance()->GetInput();	// �Q�[���N���X�C���X�^���X������͏��̋��L��

	/*== �O���t�B�b�N ================*/
	LoadDivGraph("dat/image/play/player/jiki.png",3,3,1,32,32,GhPlayer);	// ���@�摜
	GhBooster = LoadGraph("dat/image/play/player/boost01.png");				// ���@�u�[�X�^�[�摜
	GhBullet = LoadGraph("dat/image/play/bullet/bul00.png");				// ���@�̒e�摜

	/*==  ================*/
	mObjMoveSpeed = 5;						// ��{�ړ����x
	flgSlow = false;						// �X���E���[�u�t���O
	flgShot = false;						// �V���b�g�t���O
	mObjHitArea = (double)DefaultHitArea;		// �����蔻��
	mObjHostility = false;					// �G�Δ���
	mHP = Player::Instance()->GetMaxHP();	// HP�̓v���C���[��񂩂�擾
	mSelectSW = 0;							// �X���b�g1
	mObjImg = &GhPlayer[0];						// �ŏ��ɕ`�悷��摜�̓j���[�g�����̂���
	mRappid = 3;							// �A�˗��Ⴍ�Ȃ�قǑ���

	int tmp[2];
	tmp[0] = Player::Instance()->GetSubweponbox()->GetEquipSW(0);
	tmp[1] = Player::Instance()->GetSubweponbox()->GetEquipSW(1);
	mSubwepon[0] = *Player::Instance()->GetSubweponbox()->GetSubwepon(tmp[0]);
	mSubwepon[1] = *Player::Instance()->GetSubweponbox()->GetSubwepon(tmp[1]);

}
void PlayerUnit::Finalize(){
}

/*==  ================*/
void PlayerUnit::Spawn(float m_x, float m_y, float m_angle){
// �o��
	mObjTransform.SetX(m_x);
	mObjTransform.SetY(m_y);
	mObjTransform.SetZ(0);
	mObjTransform.SetAngle(m_angle);

	mObjFlag = true;
	mHP = Player::Instance()->GetMaxHP();
}
void PlayerUnit::Spawn(Transform* transform){
	mObjTransform = *transform;
	
	mHP =  Player::Instance()->GetMaxHP();
	flgDestroyed = false;
	mObjFlag = true;
}

//�T�u�E�F�|���؂�ւ�
void PlayerUnit::ToggleSW(){
	mSelectSW = (mSelectSW == 0) ? 1 : 0;
}

void PlayerUnit::TurnShotFlg(){
	flgShot = true;
}
void PlayerUnit::TurnSlowFlg(){
	flgSlow = true;
}

// �T�u�E�F�|������
void PlayerUnit::ShotSubWepon(){
	Subwepon* tmpSW = &mSubwepon[mSelectSW];

	if(tmpSW->GetStatus().Id != -1){					// �T�u�E�F�|����"�����Ȃ�"�ł͂Ȃ�
		if(	tmpSW->GetStatus().Rappid !=0 &&			// �A�˃^�C�v�łȂ�
			mObjCount % tmpSW->GetStatus().Rappid ==0)	// �A�˃^�C�~���O
		{
			// �T�u�E�F�|���̃V���b�g�̎�ނŕ�����
			(this->*(this->Shooter[tmpSW->GetStatus().Id]))(tmpSW);
		}
	}
}
void PlayerUnit::Shot(){
	/*== �V���b�g ================*/
	if(flgShot){
		if(mRappid!=0 && mObjCount % mRappid==0){
			BulletStatus tmpState;
			tmpState.Kind			=eKindNomal;
			tmpState.Speed			=Bullet::DefSpeed;
			tmpState.Damage			=1;
			tmpState.Penetoration	=0;
			tmpState.AfterImage		=false;
			tmpState.HitArea		=(double)DefaultHitArea;
			tmpState.Homing			=false;

			int i=0;
			int spaceX = 7;
			for(int j=0;j<2;j++){
				if((i = pUnitAdmin->SearchEmptyBullet()) != -1){
					spaceX *= -1;
					const float defX = mObjTransform.GetX() + spaceX;
					pUnitAdmin->GetBullet(i)->Shot(defX, mObjTransform.GetY(), mObjTransform.GetAngle(), mObjHostility, &tmpState);
					pUnitAdmin->GetSE(0)->Play();
				}
			}
		}

		ShotSubWepon();
	}//if(flgShot)
}

void PlayerUnit::InputAccept(){
/*== ���͏��� ================*/
// ������Unitadmin�N���X���瑀��ł���悤�ɂ���
		// ���l������
		UpdataInit();

		/*== ����n ================*/
		// �`�F���W
		if(pInput->IsPushChange()==1){
			ToggleSW();
		}
		// �X���E
		if(pInput->IsPushSlow()>0){
			TurnSlowFlg();
		}
		// �V���b�g
		if(pInput->IsPushShot()>0){
			TurnShotFlg();
		}
		// �{��
		if(pInput->IsPushBom()==1){
		}


		const float lastSpd = flgSlow ? mObjMoveSpeed/2 : mObjMoveSpeed;
		VECTOR force={0,0,0};

		// ��
		if(pInput->IsPushLeft()>=1){
			force.x = -lastSpd;
		}
		// �E
		if(pInput->IsPushRight()>=1){
			force.x = lastSpd;
		}
		// ��
		if(pInput->IsPushUp()>=1){
			force.y = -lastSpd;
		}
		// ��
		if(pInput->IsPushDown()>=1){
			force.y = lastSpd;
		}
		AddForce(&force);
}
void PlayerUnit::UpdataInit(){
	flgSlow = false;
	flgShot = false;
	mForce.x = 0;
	mForce.y = 0;

	mObjImg = &GhPlayer[0];
}
void PlayerUnit::Move(){
	/*== �ړ� ================*/
	float bx = mObjTransform.GetX() + mForce.x;
	float by = mObjTransform.GetY() + mForce.y;
	if(!(bx<5|| bx>FeeldMaxX  -5))	mObjTransform.SetX(bx);	// �ړ��\�͈͓��ł���Έړ�
	if(!(by<5|| by>FeeldMaxY -5))	mObjTransform.SetY(by);	// Y�Ɋւ��Ă��ꏏ

	if(mForce.x  < 0){ mObjImg = &GhPlayer[2]; }		// �����x�̒l�ŕ\������O���t�B�b�N��ύX
	if(mForce.x == 0){ mObjImg = &GhPlayer[0]; }
	if(mForce.x  > 0){ mObjImg = &GhPlayer[1]; }
}

/*== ���C�� ================*/
void PlayerUnit::Draw(){
	if(mObjFlag){
		// 2D�O���t�B�b�N�\��
		DrawRotaGraphFdF();
		DrawRotaGraphFdF(mObjTransform.GetX(), mObjTransform.GetY()+16, 0, 0.0, GhBooster, 0, 0);
	}
}
void PlayerUnit::Update(){
	/*== ���@�X�V ================*/
	UpdataInit();	// ���@���̒��������
	if(mObjFlag && !flgDestroyed){
		InputAccept();	// ���͏���
		Shot();			// ���e�̔���
		Move();			// ���@�̈ړ�

		if(mUniInvisible>0){ mUniInvisible--; }
		mObjCount++;		// �J�E���g�A�b�v
	}
}
