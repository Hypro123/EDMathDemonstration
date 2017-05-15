#include "Ship_Wheel.h"
#include "Input.h"
#include <iostream>

using namespace aie;

Ship_Wheel::Ship_Wheel()
{
	Ship_WheelTexture = new Texture("./textures/Wheel.png");
}


Ship_Wheel::~Ship_Wheel()
{
	delete Ship_WheelTexture;
}

void Ship_Wheel::draw(Renderer2D* m_2dRenderer)
{
	local_Transform.setScale(0.75f, 0.75f);
	updateGlobalTransform();

	m_2dRenderer->drawSpriteTransformed3x3(Ship_WheelTexture, global_Transform, 0.0f, 0.0f, -0.3, 0.5f, 2.25f);
}

void Ship_Wheel::update(float deltaTime)
{
	updateGlobalTransform();
}