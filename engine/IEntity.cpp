//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : IEntity.cpp
//  @ Date : 05.06.2016
//  @ Author : 
//
//


#include "IEntity.h"
#include <algorithm>
#include <assert.h>

IEntity::IEntity()
{
}

IEntity::~IEntity()
{
	_components.clear();
}

void IEntity::AddComponent(IComponent* component) 
{
	assert(std::find(_components.begin(), _components.end(), component) == _components.end());

	_components.push_back(component);
}

void IEntity::RemoveComponent(IComponent * component)
{
	assert(std::find(_components.begin(), _components.end(), component) != _components.end());

	_components.remove(component);
}

bool IEntity::HasComponent(IComponent * component) const
{
	if(std::find(_components.begin(), _components.end(), component) != _components.end())
	{
		return true;
	}
	return false;
}
