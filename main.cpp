#include <d3d12.h>
#include <cassert>
#include <vector>
#include <string>
#include <DirectXMath.h>
#include <DirectXTex.h>
#include <d3dcompiler.h>
#include <wrl.h>

#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"


#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "d3dcompiler.lib")

using namespace DirectX;
using namespace Microsoft::WRL;


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    //ポインタ置き場
    Input* input_ = nullptr;
    WinApp* winApp_ = nullptr;
    DirectXCommon* dxCommon_ = nullptr;

#pragma region WindowsAPI初期化処理
    winApp_ = new WinApp();
    winApp_->initialize();
#pragma endregion

#pragma region DirectX初期化処理

    dxCommon_ = new DirectXCommon();
    dxCommon_->Initialize(winApp_);

#pragma endregion

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

    winApp_->Finalize();
    delete winApp_;

    return 0;
}
