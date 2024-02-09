#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"

#include"Sprite.h"
#include"SpriteCommon.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    //ポインタ置き場
    Input* input_ = nullptr;
    WinApp* winApp_ = nullptr;
    DirectXCommon* dxCommon_ = nullptr;

    winApp_ = new WinApp();
    winApp_->Initialize();

    dxCommon_ = new DirectXCommon();
    dxCommon_->Initialize(winApp_);

    //スプライトコモン
    SpriteCommon* spriteCommon_ = new SpriteCommon();
    spriteCommon_->Initialize(dxCommon_);
    //スプライト
    Sprite* sprite_ = new Sprite();
    sprite_->Initialize();



    //Input生成、初期化
    input_ = new Input();
    input_->Initialize(winApp_);

    // ゲームループ
    while (true) {
        //更新
        if (winApp_->Update() == true) {
            break;
        }

        //input入力
        input_->Update();


        //更新前処理
        dxCommon_->PreDraw();

        //更新後処理
        dxCommon_->PostDraw();

        // DirectX毎フレーム処理　ここまで

    }

    delete input_;
    delete dxCommon_;
    delete spriteCommon_;
    delete sprite_;

    winApp_->Finalize();
    delete winApp_;

    return 0;
}
