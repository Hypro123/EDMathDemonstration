#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"

class Bullet : public Entity
{
public:
	Bullet();
	~Bullet();
	
	aie::Texture* bulletTexture;
	aie::Renderer2D m_2dRenderer;

	void update(float deltaTime);
	void draw(aie::Renderer2D* m_2dRenderer);

	float speed;
	float speedDefault;
	Vector3 direction;
	
	bool IsThrown;
	bool IsPickedUp;
};

