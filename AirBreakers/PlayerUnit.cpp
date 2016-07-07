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
	pInput = Game::Instance()->GetInput();	// ゲームクラスインスタンスから入力情報の共有化

	/*== グラフィック ================*/
	LoadDivGraph("dat/image/play/player/jiki.png",3,3,1,32,32,GhPlayer);	// 自機画像
	GhBooster = LoadGraph("dat/image/play/player/boost01.png");				// 自機ブースター画像
	GhBullet = LoadGraph("dat/image/play/bullet/bul00.png");				// 自機の弾画像

	/*==  ================*/
	mObjMoveSpeed = 5;						// 基本移動速度
	flgSlow = false;						// スロウムーブフラグ
	flgShot = false;						// ショットフラグ
	mObjHitArea = (double)DefaultHitArea;		// 当たり判定
	mObjHostility = false;					// 敵対判定
	mHP = Player::Instance()->GetMaxHP();	// HPはプレイヤー情報から取得
	mSelectSW = 0;							// スロット1
	mObjImg = &GhPlayer[0];						// 最初に描画する画像はニュートラルのもの
	mRappid = 3;							// 連射率低くなるほど早い

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
// 出現
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

//サブウェポン切り替え
void PlayerUnit::ToggleSW(){
	mSelectSW = (mSelectSW == 0) ? 1 : 0;
}

void PlayerUnit::TurnShotFlg(){
	flgShot = true;
}
void PlayerUnit::TurnSlowFlg(){
	flgSlow = true;
}

// サブウェポン発射
void PlayerUnit::ShotSubWepon(){
	Subwepon* tmpSW = &mSubwepon[mSelectSW];

	if(tmpSW->GetStatus().Id != -1){					// サブウェポンが"装備なし"ではない
		if(	tmpSW->GetStatus().Rappid !=0 &&			// 連射タイプでない
			mObjCount % tmpSW->GetStatus().Rappid ==0)	// 連射タイミング
		{
			// サブウェポンのショットの種類で分ける
			(this->*(this->Shooter[tmpSW->GetStatus().Id]))(tmpSW);
		}
	}
}
void PlayerUnit::Shot(){
	/*== ショット ================*/
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
/*== 入力処理 ================*/
// 将来はUnitadminクラスから操作できるようにする
		// 数値初期化
		UpdataInit();

		/*== 操作系 ================*/
		// チェンジ
		if(pInput->IsPushChange()==1){
			ToggleSW();
		}
		// スロウ
		if(pInput->IsPushSlow()>0){
			TurnSlowFlg();
		}
		// ショット
		if(pInput->IsPushShot()>0){
			TurnShotFlg();
		}
		// ボム
		if(pInput->IsPushBom()==1){
		}


		const float lastSpd = flgSlow ? mObjMoveSpeed/2 : mObjMoveSpeed;
		VECTOR force={0,0,0};

		// 左
		if(pInput->IsPushLeft()>=1){
			force.x = -lastSpd;
		}
		// 右
		if(pInput->IsPushRight()>=1){
			force.x = lastSpd;
		}
		// 上
		if(pInput->IsPushUp()>=1){
			force.y = -lastSpd;
		}
		// 下
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
	/*== 移動 ================*/
	float bx = mObjTransform.GetX() + mForce.x;
	float by = mObjTransform.GetY() + mForce.y;
	if(!(bx<5|| bx>FeeldMaxX  -5))	mObjTransform.SetX(bx);	// 移動可能範囲内であれば移動
	if(!(by<5|| by>FeeldMaxY -5))	mObjTransform.SetY(by);	// Yに関しても一緒

	if(mForce.x  < 0){ mObjImg = &GhPlayer[2]; }		// 加速度の値で表示するグラフィックを変更
	if(mForce.x == 0){ mObjImg = &GhPlayer[0]; }
	if(mForce.x  > 0){ mObjImg = &GhPlayer[1]; }
}

/*== メイン ================*/
void PlayerUnit::Draw(){
	if(mObjFlag){
		// 2Dグラフィック表示
		DrawRotaGraphFdF();
		DrawRotaGraphFdF(mObjTransform.GetX(), mObjTransform.GetY()+16, 0, 0.0, GhBooster, 0, 0);
	}
}
void PlayerUnit::Update(){
	/*== 自機更新 ================*/
	UpdataInit();	// 自機情報の定期初期化
	if(mObjFlag && !flgDestroyed){
		InputAccept();	// 入力処理
		Shot();			// 自弾の発射
		Move();			// 自機の移動

		if(mUniInvisible>0){ mUniInvisible--; }
		mObjCount++;		// カウントアップ
	}
}
