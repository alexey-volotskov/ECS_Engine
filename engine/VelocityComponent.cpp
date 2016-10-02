#include "VelocityComponent.h"

VelocityComponent::VelocityComponent() :
	_positionX(0.0f), _positionY(0.0f),
	_angle(0.0f),
	_transform(nullptr)
{

}

/* velocity position */
void VelocityComponent::SetPosition(CIwFVec2 position) 
{ 
	SetPosition(position.x, position.y); 
}

void VelocityComponent::SetPosition(float x, float y) 
{ 
	_positionX = x; _positionY = y; 
}

CIwFVec2 VelocityComponent::GetPosition() const
{ 
	return CIwFVec2(_positionX, _positionY); 
}

float VelocityComponent::GetPositionX() const
{ 
	return _positionX; 
}

float VelocityComponent::GetPositionY() const
{ 
	return _positionY; 
}

/* velocity angle */
void VelocityComponent::SetAngle(float angle) 
{ 
	_angle = angle; 
}

float VelocityComponent::GetAngle() const
{ 
	return _angle; 
}

void VelocityComponent::SetTransform(TransformComponent * transform)
{
	_transform = transform;
}

TransformComponent * VelocityComponent::GetTransform()
{
	return _transform;
}

const TransformComponent * VelocityComponent::GetTransform() const
{
	return _transform;
}
