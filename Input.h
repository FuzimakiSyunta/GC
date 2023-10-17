#include<Windows.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include<wrl.h>

//using namespace Microsoft::WRL;

class Input
{
public:
	//初期化
	void Initialize(HINSTANCE hInstance,HWND hwnd);
	//更新
	void Update();
	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

	//全キーの状態
	BYTE key[256] = {};

	//DirectInputのインスタンス
	ComPtr<IDirectInput8>directInput;

private:
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
	//前回の全キー状態
	BYTE keyPre[256] = {};
};


