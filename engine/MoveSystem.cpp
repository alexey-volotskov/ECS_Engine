#include "MoveSystem.h"
#include "TransformComponent.h"

void MoveSystem::Start()
{
}

void MoveSystem::Finish()
{
}

void MoveSystem::Update(float time)
{
	for (auto component : _velocityComponents)
	{
		component->GetTransform()->SetPosition(component->GetTransform()->GetPosition() + component->GetPosition() * time);
		component->GetTransform()->SetAngle(component->GetTransform()->GetAngle() + component->GetAngle() * time);
	}
}

bool MoveSystem::AddComponentFromEntity(IEntity * entity)
{
	VelocityComponent* component = entity->GetComponent<VelocityComponent>();
	if (component != nullptr)
	{
		_velocityComponents.push_back(component);
		return true;
	}
	else
	{
		return false;
	}
}

bool MoveSystem::RemoveComponentFromEntity(IEntity * entity)
{
	VelocityComponent* component = entity->GetComponent<VelocityComponent>();
	for (auto node : _velocityComponents)
	{
		if (node == component)
		{
			_velocityComponents.remove(node);
			return true;
		}
	}
	return false;
}

void MoveSystem::AddComponent(VelocityComponent * component)
{
	_velocityComponents.push_back(component);
}

void MoveSystem::RemoveComponent(VelocityComponent * component)
{
	_velocityComponents.remove(component);
}

