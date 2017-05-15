#include "Entity.h"



Entity::Entity()
{
	m_parent = nullptr;

	m_collider.topRight = Vector2(-60, -60);
	m_collider.botLeft = Vector2(60, 60);
}


Entity::~Entity()
{
}

void Entity::setParent(Entity* sParent)
{
	m_parent = sParent;
}

void Entity::setChild(Entity* sChild)
{
	m_children.push_back(sChild);
}

void Entity::updateGlobalTransform()
{
	if (m_parent != nullptr)
	{
		global_Transform = m_parent->global_Transform * local_Transform;
	}
	else
	{
		global_Transform = local_Transform;
	}
	for (int i = 0; i < m_children.size(); i++)
	{
		m_children[i]->updateGlobalTransform();
	}
}

Collider& Entity::GetCollider()
{
	return m_collider;
}
