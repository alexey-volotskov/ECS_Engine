#if !defined(_IENTITY_H)
#define _IENTITY_H

#include "IComponent.h"

#include <list>


class IEntity 
{
protected:
	std::list <IComponent*> _components;

public:
	IEntity();
	virtual ~IEntity();

	void AddComponent(IComponent* component);
	void RemoveComponent(IComponent* component);
	bool HasComponent(IComponent* component) const;

	template <typename TypeComponent>
	bool RemoveComponent();

	template <typename TypeComponent>
	TypeComponent* GetComponent();

	template <typename TypeComponent>
	const TypeComponent* GetComponent() const;

	template <typename TypeComponent>
	bool HasComponent() const;

};


template<typename TypeComponent>
inline bool IEntity::RemoveComponent()
{
	//static_assert(std::is_base_of<IComponent, TypeComponent>::value, "Template argument does not inherit from IComponent");

	auto component = dynamic_cast<TypeComponent*>(iterator);
	assert(std::find(_components.begin(), _components.end(), component) == _components.end());

	if (component != nullptr)
	{
		_components.remove(component);
		return true;
	}
	return false;
}

template <typename TypeComponent>
TypeComponent* IEntity::GetComponent()
{
	//static_assert(std::is_base_of<IComponent, TypeComponent>::value, "Template argument does not inherit from IComponent");

	for (auto iterator : _components)
	{
		auto component = dynamic_cast<TypeComponent*>(iterator);
		if (component != nullptr)
		{
			return component;
		}
	}
	return nullptr;
}

template <typename TypeComponent>
const TypeComponent* IEntity::GetComponent() const
{
	//static_assert(std::is_base_of<IComponent, TypeComponent>::value, "Template argument does not inherit from IComponent");

	for (auto iterator : _components)
	{
		auto component = dynamic_cast<TypeComponent*>(iterator);
		if (component != nullptr)
		{
			return component;
		}
	}
	return nullptr;
}

template<typename TypeComponent>
inline bool IEntity::HasComponent() const
{
	//static_assert(std::is_base_of<IComponent, TypeComponent>::value, "Template argument does not inherit from IComponent");

	for (auto iterator : _components)
	{
		auto component = dynamic_cast<TypeComponent*>(iterator);
		if (component != nullptr)
		{
			return true;
		}
	}
	return false;
}

#endif  //_IENTITY_H
