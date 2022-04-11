#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

using namespace DirectX;

GameScene::GameScene() {}

GameScene::~GameScene() {
	/*delete sprite_;*/
	delete model_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	soundDataHandle_ = audio_->LoadWave("fanfare.wav");
	audio_->PlayWave(soundDataHandle_);
	voiceHundle_ = audio_->PlayWave(soundDataHandle_, true);

	worldTransform_.Initialize();

	viewProjection_.Initialize();

	/*textureHandle_ = TextureManager::Load("mario.png");*/
	textureHandle_ = TextureManager::Load("mario.png");
	//sprite
	/*sprite_ = Sprite::Create(textureHandle_,{100, 50});*/
	//3D model
	model_ = Model::Create();


	
}


void GameScene::Update() {
	////sprite
	//	XMFLOAT2 position = sprite_->GetPosition();
	//
	//	position.x += 2.0f;
	//	position.y += 1.0f;
	//
	//	sprite_->SetPosition(position);
	//sound
	if (input_->TriggerKey(DIK_SPACE)) {
		audio_->StopWave(voiceHundle_);
	}
	//text
	debugText_->Print("Some Text For Test", 50, 50, 1.0f);

	debugText_->SetPos(50, 70);
	debugText_->Printf("And More Text:%d", 2001);
	//value
	value_++;

	std::string strDebug = std::string("Value:") + 
	std::to_string(value_);

	debugText_->Print(strDebug, 50, 90, 1.0f);
}


void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//3d model print
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	/*sprite_->Draw();*/

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
