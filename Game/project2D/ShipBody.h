#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Entity.h"
#include "Matrix3.h"
#include "Ship_SecondLevel.h"
#include "Player.h"
#include "Sail.h"

class ShipBody : public Entity
{
public:
	ShipBody();
	~ShipBody();
	
	void draw(aie::Renderer2D* m_2dRenderer);
	void update(float deltaTime);

	aie::Texture* shipBodyTexture;
	aie::Renderer2D* m_2dRenderer;

	Ship_SecondLevel* shipSecondLevel;
	Player* player;
	Bullet* bullet;
	Sail* sail;

private:
	float speed;
	Vector2 Velocity;
	float rotVel;
	float drag;
	float rotDrag;
	float MoveSpeed;
	float MaxAngle;
	
	float ShipHeight;
	float ShipWidth;

	bool Sailing;

	bool Drive;
};

