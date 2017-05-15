#include "collisionManager.h"
#include "Collider.h"

collisionManager* collisionManager::m_instance = nullptr;

collisionManager::collisionManager()
{
}


collisionManager::~collisionManager()
{
}

collisionManager* collisionManager::GetInstance()
{
	return m_instance;
}

void collisionManager::Create()
{
	if (m_instance == nullptr)
		m_instance = new collisionManager();
}

void collisionManager::Destroy()
{
	delete m_instance;
}

void collisionManager::CreateObject(Entity* pObject)
{
	m_collisionList.push_back(pObject);
}

void collisionManager::RemoveObject(Entity* pObject)
{
	auto iter = std::find(m_collisionList.begin(), m_collisionList.end(), pObject);
	if (iter != m_collisionList.end())
		m_collisionList.erase(iter);
}

Entity* collisionManager::testCollision(Entity* pObject)
{
	for (int i = 0; i < m_collisionList.size(); ++i)
	{
		//Dont collide with self
		if (pObject == m_collisionList[i])
			continue;
		
		//calc AABB of two objects
		Collider collider1 = pObject->GetCollider();
		collider1.topRight = collider1.topRight + pObject->local_Transform.getPosition();
		collider1.botLeft = collider1.botLeft + pObject->local_Transform.getPosition();

		Collider collider2 = m_collisionList[i]->GetCollider();
		collider2.topRight = collider2.topRight + m_collisionList[i]->local_Transform.getPosition();
		collider2.botLeft = collider2.botLeft + m_collisionList[i]->local_Transform.getPosition();

		//AABBs overlapping
		if (collider1.botLeft < collider2.topRight&&
			collider2.botLeft < collider1.topRight)
		{
			return m_collisionList[i];
		}
	}
	return nullptr;
}