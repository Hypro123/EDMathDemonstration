#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	collisionManager::Create();
	
	m_2dRenderer = new Renderer2D();

	m_shipTexture = new Texture("./textures/ship.png");

	m_font = new Font("./font/consolas.ttf", 32);

	m_audio = new Audio("./audio/powerup.wav");

	ship = new ShipBody();
	
	arena = new Arena();

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete arena;
	delete ship;
	delete m_audio;
	delete m_font;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	ship->update(deltaTime);
	arena->update(deltaTime);
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();
	setBackgroundColour(0, 0, 255, 0.1);
	m_2dRenderer->begin();
	ship->draw(m_2dRenderer);
	arena->draw(m_2dRenderer);
	//THESE BOXES NEED TO FOLLOW TH PLAYER
	//Left
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(-60, 0, 10, 275, 0, -1);
	//Right
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(60, 0, 10, 275, 0, -1);
	//Up
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(0, 137, 130, 10, 0, -1);
	//Down
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(0, -137, 130, 10, 0, -1);

	m_2dRenderer->end();
}