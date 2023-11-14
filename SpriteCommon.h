#include<dxcapi.h>
#include<string>
//共通
class SpriteCommon
{
public:
	//初期化
	void Initialize();
private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
	);
};

