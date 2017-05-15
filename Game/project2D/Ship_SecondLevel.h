#pragma once
#include "Entity.h"
#include "CollisionManager.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "Matrix3.h"
#include "Ship_Wheel.h"

class Ship_SecondLevel : public Entity
{
public:
	Ship_SecondLevel();
	~Ship_SecondLevel();

	void draw(aie::Renderer2D* m_2dRenderer);
	void update(float deltaTime);

	Ship_Wheel* shipWheel;

	aie::Texture* SecondFloorTexture;
	aie::Renderer2D* m_2dRenderer;
};

