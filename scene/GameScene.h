#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <DirectXMath.h>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

  public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	
	Model* model_ = nullptr;

	//world transform
	WorldTransform worldTransform_;
	//View Projection
	ViewProjection viewProjection_;

	//sprite
	/*Sprite* sprite_ = nullptr;*/
  private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;
	//image
	uint32_t textureHandle_ = 0;
	//sound
	uint32_t soundDataHandle_ = 0;
	uint32_t voiceHundle_ = 0;
	//value
	int32_t value_ = 0;
	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
