#pragma once
#include "Entity.h"
#include "ShipBody.h"
#include "Renderer2D.h"
#include "Texture.h"

class Arena : public Entity
{
public:
	Arena();
	~Arena();

	ShipBody* ship;

	aie::Renderer2D* m_2dRenderer;
	aie::Texture* arenaTexture;

	void draw(aie::Renderer2D* m_2dRenderer);
	void update(float deltaTime);
};

