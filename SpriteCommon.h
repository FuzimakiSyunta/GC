#include<dxcapi.h>
#include<string>
//ã§í 
class SpriteCommon
{
public:
	//èâä˙âª
	void Initialize();
private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
	);
};

