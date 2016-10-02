#pragma once
#include "TransformComponent.h"

class VelocityComponent : public IComponent
{
private:
	TransformComponent* _transform;

	float _positionX, _positionY;
	float _angle;

public:
	/* ctor, dtor */
	VelocityComponent();

	/* velocity position */
	void SetPosition(CIwFVec2 position);
	void SetPosition(float x, float y);

	CIwFVec2 GetPosition() const;
	float GetPositionX() const;
	float GetPositionY() const;

	/* velocity angle */
	void SetAngle(float angle);
	float GetAngle() const;

	void SetTransform(TransformComponent* transform);
	TransformComponent* GetTransform();
	const TransformComponent* GetTransform() const;
};