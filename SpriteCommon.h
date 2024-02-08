#pragma once
#include<wrl.h>
#include <string>
#include <dxcapi.h>

#include"DirectXcommon.h"
//ã§í 
class SpriteCommon
{
public:
	//èâä˙âª
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

