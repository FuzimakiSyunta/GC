#include "Input.h"
#include <cassert>

#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

using namespace Microsoft::WRL;

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
    HRESULT result;

    // DirectInputの初期化
    result = DirectInput8Create(
        hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));

    // キーボードデバイスの生成
   
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // 入力データ形式のセット
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
    assert(SUCCEEDED(result));
    // 排他制御レベルのセット
    result = keyboard->SetCooperativeLevel(
        hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::Update()
{
    //前回のキー入力を保存
    memcpy(keyPre,key,sizeof(key));

    // キーボード情報の取得開始
    keyboard->Acquire();
  
    keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
    //指定キーを押していればtrueを返す
    if (key[keyNumber])
    {
        
        return true;
    }
    return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
    if (key[keyNumber] && !keyPre[keyNumber]) {

        return true;
    }

    return false;
}