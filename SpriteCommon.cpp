#include "SpriteCommon.h"
#include<wrl.h>
#include<cassert>

#pragma comment(lib,"dxcompiler.lib")

using namespace Microsoft::WRL;

void SpriteCommon::Initialize()
{
	HRESULT result{};

	ComPtr<IDxcUtils>dxcUils;
	ComPtr<IDxcCompiler3>dxcCompiler = nullptr;
	result = DxcCreateInstance(CLSID_DxcUtils, IID_PPV_ARGS(&dxUtils));
	assert(SUCCEEDED(result));
	result = DxcCreateInstance(CLSID_DxcCompiler,IID_PPV_ARGS(&dxcCompiler));
	assert(SUCCEEDED(result));

	IDxcIncludeHandler* includeHandler = nullptr;
	result = dxcUils->CreateDefaultIncludeHandler(&includeHandler);
	assert(SUCCEEDED(result));
}
IDxcBlob*SpriteCommon::CompileShader(const std::wstring)
{

}
