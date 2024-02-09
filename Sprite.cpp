#include "Sprite.h"
#include <d3d12.h>
#include <DirectXMath.h>


using namespace Microsoft::WRL;
using namespace DirectX;

void Sprite::Initialize(DirectXCommon* dxCommon)
{
	dxCommon_ = dxCommon;

	//VertexResource
	D3D12_HEAP_PROPERTIES uploadHeapProperties{};
	uploadHeapProperties.Type = D3D12_HEAP_TYPE_UPLOAD;
	D3D12_RESOURCE_DESC vertexResourceDesc{};
	vertexResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	vertexResourceDesc.Width = sizeof(XMFLOAT4) * 3;
	vertexResourceDesc.Height = 1;
	vertexResourceDesc.DepthOrArraySize = 1;
	vertexResourceDesc.MipLevels = 1;
	vertexResourceDesc.SampleDesc.Count = 1;
	vertexResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

	ComPtr<ID3D12Resource>vertexResource;
	HRESULT result = dxCommon_->GetDevice()->CreateCommittedResource(&uploadHeapProperties,D3D12_HEAP_FLAG_NONE,
		&vertexResourceDesc,D3D12_RESOURCE_STATE_GENERIC_READ,nullptr,
		IID_PPV_ARGS(&vertexResource));
	assert(SUCCEEDED(result));
	
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};
}