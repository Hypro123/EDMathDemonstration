#include "Player.h"
#include "Renderer2D.h"
#include "Input.h"
#include <Math.h>
#include "CollisionManager.h"
#include"VectorCast.h"
#include <iostream>

using namespace aie;

Player::Player()
{
	speed = 100.0f;
	rotSpeed = 6.28f;

	OnShip = true;
	CantMove = false;

	PlayerTexture = new Texture("./textures/Player.png");

	float PlayerWidth = PlayerTexture->getWidth() / 2;
	float PlayerHeight = PlayerTexture->getHeight() / 2;

	m_collider.topRight = Vector2(PlayerWidth, PlayerHeight);
	m_collider.botLeft = Vector2(-PlayerWidth, -PlayerHeight);

	collisionManager::GetInstance()->CreateObject(this);

	isCollided = false;

	local_Transform.setPosition(1, -95);
	spawn = local_Transform.getPosition();
}


Player::~Player()
{
	delete PlayerTexture;
}

void Player::draw(Renderer2D* m_2dRenderer)
{
	Input* input = Input::getInstance();
	m_2dRenderer->drawSpriteTransformed3x3(PlayerTexture, global_Transform, 0.0f, 0.0f, -0.91);
}

void Player::update(float deltaTime)
{
	Vector2 PrevPos = global_Transform.getPosition();

	Input* input = Input::getInstance();
	Vector3 PlayerDir;
	Matrix3 temp;
	float rot = 0;
	Matrix3 tempRot;
	Vector2 Velocity;
	if (input->wasKeyPressed(INPUT_KEY_Z))
	{
		CantMove = !CantMove;
		local_Transform.setPosition(global_Transform.getPosition().x, global_Transform.getPosition().y - 5);
	}
	
	if (CantMove == false)
	{
		//INPUT AND GETTING THE DIRECTION
		if (input->isKeyDown(INPUT_KEY_A))
			rot = rotSpeed * deltaTime;

		if (input->isKeyDown(INPUT_KEY_D))
			rot -= rotSpeed * deltaTime;

		if (input->isKeyDown(INPUT_KEY_W))
			PlayerDir = local_Transform[1];

		if (input->isKeyDown(INPUT_KEY_S))
			PlayerDir = -local_Transform[1];
	}
	
		//PLAYER ROTATION
		tempRot.setRotateZ(rot);
		local_Transform = local_Transform * tempRot;

		//PLAYER MOVEMENT
		Vector2 dir = CastTo<Vector2>(PlayerDir);

		Velocity += dir * speed * deltaTime;
		temp.setPosition(Velocity);
		local_Transform = temp * local_Transform;
	updateGlobalTransform();

	//COLLISION
	collisionManager* pCollision = collisionManager::GetInstance();
	Entity* BulletCollider = pCollision->testCollision(this);
	if (BulletCollider && !isCollided)
	{
		float lowest = 99999999.0f;

		global_Transform.setPosition(PrevPos);
		//STORE VARIABLE SIDES
		float Check[4];
		/* Left */ Check[0] = fabs((GetCollider().topRight.x + global_Transform[2][0]) - (BulletCollider->GetCollider().botLeft.x + BulletCollider->global_Transform.getPosition().x));
		/* Right */Check[1] = fabs((GetCollider().botLeft.x + global_Transform[2][0]) - (BulletCollider->GetCollider().topRight.x + BulletCollider->global_Transform.getPosition().x));
		/* Up */ Check[2] = fabs((GetCollider().botLeft.y + global_Transform[2][1]) - (BulletCollider->GetCollider().topRight.y + BulletCollider->global_Transform.getPosition().y));
		/* Down */ Check[3] = fabs((GetCollider().topRight.y + global_Transform[2][1]) - (BulletCollider->GetCollider().botLeft.y + BulletCollider->global_Transform.getPosition().y));
		
		for (int i = 0; i < 4; i++)
		{
			if (lowest > Check[i])
			{
				lowest = Check[i];
			}
		}


		//Left side
		if (Check[0] == lowest)
		{
			Top.y = BulletCollider->GetCollider().topRight.y + BulletCollider->global_Transform.getPosition().y;
			Top.x = BulletCollider->GetCollider().botLeft.x + BulletCollider->global_Transform.getPosition().x;
			Bot = BulletCollider->GetCollider().botLeft + BulletCollider->global_Transform.getPosition();
			//std::cout << "Left" << std::endl;
		}

		//Right side
		if (Check[1] == lowest)
		{
			Top = BulletCollider->GetCollider().topRight + BulletCollider->global_Transform.getPosition();
			Bot.y = BulletCollider->GetCollider().botLeft.y + BulletCollider->global_Transform.getPosition().y;
			Bot.x = BulletCollider->GetCollider().topRight.x + BulletCollider->global_Transform.getPosition().x;
			//std::cout << "Right" << std::endl;
		}

		//Top side
		if (Check[2] == lowest)
		{
			Bot.y = BulletCollider->GetCollider().topRight.y + BulletCollider->global_Transform.getPosition().y;
			Bot.x = BulletCollider->GetCollider().botLeft.x + BulletCollider->global_Transform.getPosition().x;
			Top = BulletCollider->GetCollider().topRight + BulletCollider->global_Transform.getPosition();
			//std::cout << "Top" << std::endl;
		}

		//Bot side
		if (Check[3] == lowest)
		{
			Bot = BulletCollider->GetCollider().botLeft + BulletCollider->global_Transform.getPosition();
			Top.y = BulletCollider->GetCollider().botLeft.y + BulletCollider->global_Transform.getPosition().y;
			Top.x = BulletCollider->GetCollider().topRight.x + BulletCollider->global_Transform.getPosition().x;
			//std::cout << "Bot" << std::endl;
		}
		isCollided = true;
		local_Transform.setPosition(spawn);
		updateGlobalTransform();
	}
	else
	{
		isCollided = false;
	}
}