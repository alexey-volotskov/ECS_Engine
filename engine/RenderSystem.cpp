#include "RenderSystem.h"
#include "DisplayComponent.h"

void RenderSystem::Start()
{
}

void RenderSystem::Finish()
{
}

void RenderSystem::Update(float time)
{
	for (DisplayComponent* component : _displayComponents)
	{
		if (component->IsVisible())
		{	
			Iw2DSetTransformMatrix(component->GetMatrix());
			Iw2DDrawImage(component->GetImage(), CIwFVec2::g_Zero);
		}
	}
}

bool RenderSystem::AddComponentFromEntity(IEntity * entity)
{
	DisplayComponent* component = entity->GetComponent<DisplayComponent>();
	if (component != nullptr)
	{
		_displayComponents.push_back(component);
		return true;
	}
	else
	{
		return false;
	}
}

bool RenderSystem::RemoveComponentFromEntity(IEntity * entity)
{
	DisplayComponent* component = entity->GetComponent<DisplayComponent>();
	for (auto node : _displayComponents)
	{
		if (node == component)
		{
			_displayComponents.remove(node);
			return true;
		}
	}
	return false;
}

void RenderSystem::AddComponent(DisplayComponent * component)
{
	_displayComponents.push_back(component);
}

void RenderSystem::RemoveComponent(DisplayComponent * component)
{
	_displayComponents.remove(component);
}



