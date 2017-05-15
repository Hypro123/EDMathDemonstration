#pragma once
#include "Matrix3.h"
#include"Collider.h"
#include<vector>

class Entity
{
public:
	Entity();
	~Entity();

	Entity* m_parent;
	std::vector<Entity*> m_children;

	Matrix3 global_Transform;
	Matrix3 local_Transform;

	Collider m_collider;
	Collider& GetCollider();

	void updateGlobalTransform();
	void setParent(Entity* sParent);
	void setChild(Entity* sChild);

protected:
	unsigned int health;
	unsigned int MaxHealth;
	float mass;
	float rotSpeed;
};

