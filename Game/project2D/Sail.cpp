#include "Sail.h"
#include "Input.h"
#include <iostream>

#define PI  3.14159265358979323846

Sail::Sail()
{
	SailDown = new aie::Texture("./textures/Sail_Folded.png");
	SailUp = new aie::Texture("./textures/Sail_Open.png");
	CurrentTexture = new aie::Texture("./textures/Sail_Folded.png");

	cannon = new Cannon();
	
	setChild(cannon);
	cannon->setParent(this);

	rotSpeed = 1.2f;
	CanChange = false;
}


Sail::~Sail()
{
	delete cannon;
	delete SailDown;
	delete SailUp;
	delete CurrentTexture;
}

void Sail::draw(aie::Renderer2D* m_2dRenderer)
{
	cannon->draw(m_2dRenderer);
	m_2dRenderer->drawSpriteTransformed3x3(CurrentTexture, global_Transform, 0, 0, -0.95);
}

void Sail::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	float rot = 0;
	Matrix3 tempRot;

	if (input->isKeyDown(aie::INPUT_KEY_Q))
		rot = rotSpeed * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_E))
		rot -= rotSpeed * deltaTime;

	tempRot.setRotateZ(rot);
	local_Transform = local_Transform * tempRot;
	cannon->update(deltaTime);
	updateGlobalTransform();
}