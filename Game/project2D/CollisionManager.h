#pragma once
#include<vector>
#include"Entity.h"


class collisionManager
{
public:
	static collisionManager* GetInstance();
	static void Create();
	static void Destroy();

	void CreateObject(Entity* pObject);
	void RemoveObject(Entity* pObject);

	Entity* testCollision(Entity* pObject);

private:
	collisionManager();
	~collisionManager();

	static collisionManager* m_instance;

	std::vector<Entity*> m_collisionList;
};

