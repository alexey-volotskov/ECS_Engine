#if !defined(_ENGINE_H)
#define _ENGINE_H

#include "ISystem.h"
#include "IEntity.h"
#include <list>

class Engine 
{
private:
	std::list<ISystem*> _systems;
	std::list<IEntity*> _entities;

public:
	void Update(float time);

	void AddSystem(ISystem* system);
	void RemoveSystem(ISystem* system);

	void AddEntity(IEntity* entity);
	void RemoveEntity(IEntity* entity);
};

#endif  //_ENGINE_H
