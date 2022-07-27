#pragma once

#include <vector>

#include "Node.h"

class Graphics;
class Renderer;
class Entity;

class Scene {
public:
	Scene() = default;
	~Scene() = default;
	void LoadScene(Graphics& gfx);

	void RenderTraverse(Graphics& gfx, Renderer& renderer);

	Node* AddNode(Entity* entity, const Transform& transform, Node* parent = nullptr);

	Node* GetMainCameraNode() { return m_mainCamera; }
private:
	void RenderTraverseNode(Node* node, Graphics& gfx, Renderer& renderer, bool dirty);

private:
	Node* m_mainCamera;
	Node m_transformHierarchy;
	//std::vector<Node> m_nodes;
};
