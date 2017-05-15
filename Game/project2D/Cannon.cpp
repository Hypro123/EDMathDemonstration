#include "Cannon.h"
#include "Input.h"


Cannon::Cannon()
{
	CannonTexture = new aie::Texture("./textures/Cannon.png");
	bullet = new Bullet();
	rotSpeed = 3.14f;
	timer = 0;
}


Cannon::~Cannon()
{
	delete CannonTexture;
	delete bullet;
}

void Cannon::draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(CannonTexture, global_Transform, 0, 0, -0.97);
	bullet->draw(m_2dRenderer);
}

void Cannon::update(float deltaTime)
{
	
	Matrix3 tempRot;
	float rot = 0;
	aie::Input* input = aie::Input::getInstance();
	timer += deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		rot = rotSpeed * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		rot -= rotSpeed * deltaTime;

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		if (timer >= 3)
		{
			bullet->local_Transform.setPosition(global_Transform.getPosition());
			bullet->direction = global_Transform[1];
			timer = 0;
		}
	}

	tempRot.setRotateZ(rot);
	local_Transform = local_Transform * tempRot;
	bullet->update(deltaTime);
	updateGlobalTransform();
}