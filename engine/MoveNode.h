#pragma once
#include "TransformComponent.h"
#include "VelocityComponent.h"
#include "IEntity.h"


struct MoveNode 
{
	TransformComponent* Transform;
	VelocityComponent* Velocity;


	MoveNode() :
		Transform(nullptr),
		Velocity(nullptr)
	{
	}

	bool InitByEntity(IEntity* entity)
	{
		Transform = entity->GetComponent<TransformComponent>();
		Velocity = entity->GetComponent<VelocityComponent>();

		if (Velocity != nullptr && Transform != nullptr)
			return true;

		return false;
	}
};
