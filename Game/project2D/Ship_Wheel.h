#pragma once
#include "Entity.h"
#include "CollisionManager.h"
#include "Texture.h"
#include "Renderer2D.h"

class Ship_Wheel : public Entity
{
public:
	Ship_Wheel();
	~Ship_Wheel();

	void draw(aie::Renderer2D* m_2dRenderer);
	void update(float deltaTime);

	aie::Texture* Ship_WheelTexture;
	aie::Renderer2D* m_2dRenderer;
};

