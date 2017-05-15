#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Input.h"
#include "Texture.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void draw(aie::Renderer2D* m_2dRenderer);
	void update(float deltaTime);

	aie::Texture* PlayerTexture;
	aie::Renderer2D* m_2dRenderer;

private:
	float speed;
	float rotSpeed;

	Vector2 spawn;

	Vector2 Top;
	Vector2 Bot;

	bool CantMove;

	bool isCollided;

	bool OnShip;
};