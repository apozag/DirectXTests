#pragma once

#include "StateBindable.h"

class DepthStencilState : public StateBindable {
public:
	enum DepthStencilAccess {
		DEPTH_WRITE = 0x1,
		DEPTH_READ = 0x2,
		STENCIL_WRITE = 0X4,
		STENCIL_READ = 0x8
	};
public:
	DepthStencilState(int dsst, int refVal=0);
	~DepthStencilState();
	void Bind()const override;
	void Unbind()const override {}
private:
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> m_pDSState;
	unsigned int m_refVal;
};