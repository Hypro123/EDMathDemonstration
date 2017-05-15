#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Bullet.h"

class Cannon : public Entity
{
public:
	Cannon();
	~Cannon();

	aie::Renderer2D* m_2dRenderer;
	aie::Texture* CannonTexture;

	Bullet* bullet;

	void draw(aie::Renderer2D* m_2dRenderer);

	void update(float deltaTime);

	float rotSpeed;
	float timer;
};

