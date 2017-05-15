#include "Bullet.h"
#include "VectorCast.h"
#include "Input.h"
#include "CollisionManager.h"


using namespace aie;

Bullet::Bullet()
{
	speed = 200;
	speedDefault = 200;
	bulletTexture = new Texture("./textures/CannonBall.png");
	local_Transform.setPosition(2000, 2000);
	
	float BulletWidth = bulletTexture->getWidth() / 2;
	float BulletHeight = bulletTexture->getHeight() / 2;

	m_collider.topRight = Vector2(BulletWidth, BulletHeight);
	m_collider.botLeft = Vector2(-BulletWidth, -BulletHeight);

	collisionManager::GetInstance()->CreateObject(this);
	
	IsThrown = false;
	IsPickedUp = false;
}


Bullet::~Bullet()
{
	delete bulletTexture;
}

void Bullet::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(bulletTexture, local_Transform, 0.0f, 0.0f, -0.96); // , -direction.x, -direction.y);
}

void Bullet::update(float deltaTime)
{
	Matrix3 temp;
	Vector2 dir = CastTo<Vector2>(direction);
	temp.setPosition(dir * speed * deltaTime);
	local_Transform = temp * local_Transform;

	updateGlobalTransform();
}
