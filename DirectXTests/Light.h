#pragma once

#include "Entity.h"
#include "Camera.h"
#include "RenderTarget.h"
#include "MathWrappers.h"

class Transform;
class Graphics;

class DirectionalLight : public Entity {
public:
  DirectionalLight(DirectX::SimpleMath::Vector3 m_color) : m_color(m_color) {};

  virtual void Setup() override;

  void Insert(Node* node, const Transform& worldTransform) override;
  DirectX::SimpleMath::Vector3 GetColor() const { return m_color; }
  const Camera* GetCamera() const { return m_camera; }
  Texture2D* GetShadowMap() const { return m_rt->GetTextures2D()[0]; }
  REFLECT()
private:
  math::Vector3 m_color;
  Camera* m_camera;
  RenderTarget* m_rt;
};

class PointLight : public Entity {
public:
  PointLight(DirectX::SimpleMath::Vector3 m_color) :
    m_color(m_color)
  {}

  virtual void Setup() override;

  void Insert(Node* node, const Transform& worldTransform) override;
  DirectX::SimpleMath::Vector3 GetColor() const { return m_color; }
  REFLECT()
private:
  math::Vector3 m_color;
  Camera m_cameras[6];
  RenderTarget m_rts[6];
};

class SpotLight : public Entity {
public:
  SpotLight(DirectX::SimpleMath::Vector3 m_color, float m_phi, float m_theta) :
    m_color(m_color),
    m_phi(m_phi),
    m_theta(m_theta)
  {}

  virtual void Setup() override;

  void Insert(Node* node, const Transform& worldTransform) override;
  DirectX::SimpleMath::Vector3 GetColor() const { return m_color; }
  REFLECT()
private:
  math::Vector3 m_color;
  float m_phi, m_theta;
  Camera* m_camera;
  RenderTarget* m_rt;
};
