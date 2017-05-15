#include "Arena.h"

using namespace aie;

Arena::Arena()
{
	arenaTexture = new Texture("./textures/Arena.png");
	
	//float arenaWidth = arenaTexture->getWidth() / 2;
	//float arenaHeight = arenaTexture->getHeight() / 2;

	//m_collider.topRight = Vector2(arenaWidth, arenaHeight);
	//m_collider.botLeft = Vector2(-arenaWidth, -arenaHeight);

	//collisionManager::GetInstance()->CreateObject(this);
}


Arena::~Arena()
{
	delete arenaTexture;
}

void Arena::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(arenaTexture, global_Transform);
}

void Arena::update(float deltaTime)
{
	updateGlobalTransform();
}