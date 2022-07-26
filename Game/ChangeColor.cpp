#include "ChangeColor.h"
#include "Node.h"
#include "Material.h"
#include "Drawable.h"

void ChangeColor::Run(Node* node) {
	Drawable* drawable = node->GetEntity<Drawable>();
	m_material = drawable->m_material;
}

void ChangeColor::Update(Node* node) {
	
	m_color[0] += Engine::GetDeltaTime()*0.1f;
	m_color[1] += Engine::GetDeltaTime()*0.1f;
	m_color[2] += Engine::GetDeltaTime()*0.1f;
	
	m_material->SetVector4("color", m_color);
}