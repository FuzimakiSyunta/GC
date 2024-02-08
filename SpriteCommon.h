#pragma once
#include<wrl.h>
#include <string>
#include <dxcapi.h>

#include"DirectXcommon.h"
//共通
class SpriteCommon
{
public:
	//初期化
	void Initialize(DirectXCommon*dxCommon);
private:
		static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils*dxcUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
	);
private:
	DirectXCommon* dxCommon_ = nullptr;
};

