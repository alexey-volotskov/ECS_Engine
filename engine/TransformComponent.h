#pragma once
#include "IComponent.h"
#include "Iw2D.h"

class TransformComponent : public IComponent 
{
private:
	const TransformComponent* _parentTransform;

	float _positionX, _positionY;
	float _scaleX, _scaleY;
	float _angle;

	CIwFVec2	_anchorOffset;
	CIwFMat2D	_localMatrix;
	CIwFMat2D	_absoluteMatrix;

	void CalculateLocalMatrix();
	void CalculateAbsoluteMatrix();

	void CalculateAnchorMatrix();
	void CalculatePositionMatrix();
	void CalculateScaleRotationMatrix();

public:
	/* ctor, dtor */
	TransformComponent();

	/* transform position */
	void SetPosition(CIwFVec2 position);
	void SetPosition(float x, float y);

	CIwFVec2 GetPosition() const;
	float GetPositionX() const;
	float GetPositionY() const;

	/* transform scale */
	void SetScale(float scale);
	void SetScale(float x, float y);

	CIwFVec2 GetScale() const;
	float GetScaleX() const;
	float GetScaleY() const;

	/* transform angle */
	void SetAngle(float angle);
	float GetAngle() const;

	const TransformComponent* GetParentTransform() const;
	void SetParentTransform(const TransformComponent* transform);

	const CIwFMat2D& GetAbsoluteMatrix() const;
	CIwFMat2D& GetAbsoluteMatrix();

	const CIwFMat2D& GetLocalMatrix() const;
	CIwFMat2D& GetLocalMatrix();

	void SetAnchorOffset(const CIwFVec2& offset);
	const CIwFVec2& GetAnchorOffet() const;
	CIwFVec2& GetAnchorOffet();

};