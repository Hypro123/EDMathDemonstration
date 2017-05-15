#include "Ship_SecondLevel.h"
#include "Input.h"
#include "Ship_Wheel.h"


using namespace aie;

Ship_SecondLevel::Ship_SecondLevel()
{
	SecondFloorTexture = new Texture("./textures/Second Floor.png");

	shipWheel = new Ship_Wheel();

	setChild(shipWheel);
	shipWheel->setParent(this);
}


Ship_SecondLevel::~Ship_SecondLevel()
{
	delete SecondFloorTexture;
	delete shipWheel;
}

void Ship_SecondLevel::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->begin();
	shipWheel->draw(m_2dRenderer);
	m_2dRenderer->drawSpriteTransformed3x3(SecondFloorTexture, global_Transform, 0.0f, 0.0f, -0.2, 0.5f, 1.255f);
}

void Ship_SecondLevel::update(float deltaTime)
{
	updateGlobalTransform();
}
