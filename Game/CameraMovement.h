#pragma once

#include "Script.h"

class CameraMovement : public Script {
public:
	REFLECT()
private:
	void Run(Node* node) override;
	void Update(Node * node) override;
};