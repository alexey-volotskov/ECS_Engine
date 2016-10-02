#pragma once
#include "ISystem.h"
#include "DisplayComponent.h"
#include <list>


class RenderSystem : public ISystem
{
private:
	std::list<DisplayComponent*> _displayComponents;

public:
	virtual void Start() override;
	virtual void Finish() override;

	virtual void Update(float time) override;

	void AddComponent(DisplayComponent* component);
	void RemoveComponent(DisplayComponent* component);

	virtual bool AddComponentFromEntity(IEntity* entity) override;
	virtual bool RemoveComponentFromEntity(IEntity* entity) override;
};