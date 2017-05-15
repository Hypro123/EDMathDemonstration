#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Cannon.h"

class Sail : public Entity
{
public:
	Sail();
	~Sail();
	
	aie::Renderer2D* m_2dRenderer;
	aie::Texture* SailDown;
	aie::Texture* SailUp;
	aie::Texture* CurrentTexture;

	Cannon* cannon;

	void draw(aie::Renderer2D* m_2dRenderer);

	void update(float deltaTime);

	float rotSpeed;

	bool CanChange;
};

