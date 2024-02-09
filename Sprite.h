#pragma once
#include"DirectXcommon.h"
#include <d3d12.h>

class Sprite
{
private:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

	//èâä˙âª
	void Initialize(DirectXCommon*dxCommon);
private:
	DirectXCommon* dxCommon_ = nullptr;

	ComPtr<ID3D12Resource>vertexresource;
};

