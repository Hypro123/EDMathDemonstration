#include "ShipBody.h"
#include "Renderer2D.h"
#include "Input.h"
#include <Math.h>
#include "Ship_SecondLevel.h"
#include "CollisionManager.h"
#include"VectorCast.h"
#include <iostream>


using namespace aie;

ShipBody::ShipBody()
{
	shipBodyTexture = new Texture("./textures/ShipDeck.png");
	
	shipSecondLevel = new Ship_SecondLevel();
	player = new Player();
	bullet = new Bullet();
	sail = new Sail();

	ShipWidth = shipBodyTexture->getWidth()/2;
	ShipHeight = shipBodyTexture->getHeight()/2;

	m_collider.topRight = Vector2(ShipWidth, ShipHeight);
	m_collider.botLeft = Vector2(-ShipWidth, -ShipHeight);

	speed = 300.0f;
	mass = 1.0f;
	drag = 3.0f;
	rotDrag = 2.0f;
	rotSpeed = 1.57f;
	rotVel = 0.0f;
	//MaxAngle = 30;
	
	Drive = false;
	Sailing = false;

	setChild(sail);
	sail->setParent(this);

	setChild(shipSecondLevel);
	shipSecondLevel->setParent(this);
	
	setChild(player);
	player->setParent(this);

	collisionManager::GetInstance()->CreateObject(this);
}


ShipBody::~ShipBody()
{
	delete shipSecondLevel;
	delete player;
	delete bullet;
	delete sail;
	delete shipBodyTexture;
}

void ShipBody::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setCameraPos(global_Transform[2][0] - 640, global_Transform[2][1] - 360);
	m_2dRenderer->begin();

	shipSecondLevel->draw(m_2dRenderer);
	player->draw(m_2dRenderer);
	sail->draw(m_2dRenderer);
	m_2dRenderer->drawSpriteTransformed3x3(shipBodyTexture, global_Transform, 0.0f, 0.0f, -0.09);
}

void ShipBody::update(float deltaTime)
{
	Input* input = Input::getInstance();
	Vector3 direction;
	Matrix3 temp;
	float rot = 0;
	Matrix3 tempRot;
	
	sail->update(deltaTime);
	player->update(deltaTime);

	MoveSpeed = fabs(Velocity.Magnitude());
	
	if (input->wasKeyPressed(INPUT_KEY_Z))
	{
		Drive = !Drive;
	}


	if (Drive == true)
	{
		//Checking the ships Direction
		if (input->wasKeyPressed(INPUT_KEY_W))
		{
			Sailing = true;
			sail->CurrentTexture = sail->SailUp;
		}
		if (input->wasKeyPressed(INPUT_KEY_S))
		{
			Sailing = false;
			sail->CurrentTexture = sail->SailDown;
		}
		
		if (input->isKeyDown(INPUT_KEY_A) && MoveSpeed > 0.001)
		{
			rot = 1;
		}

		if (input->isKeyDown(INPUT_KEY_D) && MoveSpeed > 0.001)
		{
			rot = -1;
		}
	}
	if (Sailing == true)
	{
		direction = global_Transform[1];
	}

	if (Sailing == false)
	{
		//Does nothing to slow down the ship
	}
	if (input->wasKeyPressed(INPUT_KEY_SPACE))
	{
		if (sail->cannon->timer >= 3)
		{
			sail->cannon->bullet->local_Transform.setPosition(global_Transform.getPosition());
			sail->cannon->bullet->direction = global_Transform[1];
			sail->cannon->timer = 0;
		}
	}
		
		Vector2 dirV2 = CastTo<Vector2>(direction);
		//Acceleration and Drag - movement
		Vector2 ForceSum = dirV2 * speed;
		Vector2 Acceleration = ForceSum / mass;
		Vector2 Dampening = -(Velocity * drag);
		Velocity += (Acceleration + Dampening) * deltaTime;

		//Acceleration and Drag - rotation
		float forces = rot * rotSpeed;
		float rotAccel = forces / mass;
		float rotDamp = -(rotVel * rotDrag);
		rotVel += (rotAccel + rotDamp) * deltaTime;

		//Rotation
		tempRot.setRotateZ(rotVel * deltaTime);
		local_Transform = local_Transform * tempRot;
		//Movement
		temp.setPosition(Velocity * deltaTime);
		local_Transform = temp * local_Transform;

	updateGlobalTransform();
}
