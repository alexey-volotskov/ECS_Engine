#include "TransformComponent.h"

TransformComponent::TransformComponent() :
	_positionX(0.0f), _positionY(0.0f),
	_scaleX(1.0f), _scaleY(1.0f),
	_angle(0.0f),
	_anchorOffset(CIwFVec2::g_Zero),
	_localMatrix(CIwFMat2D::g_Identity),
	_absoluteMatrix(CIwFMat2D::g_Identity),
	_parentTransform(nullptr)
{

}

/* calculate matrix */
void TransformComponent::CalculateLocalMatrix()
{
	// Get pointer to parent matrix
	CalculatePositionMatrix();
	CalculateScaleRotationMatrix();
	CalculateAnchorMatrix();
}

void TransformComponent::CalculateAnchorMatrix()
{
	_localMatrix.t -= _anchorOffset;
}

void TransformComponent::CalculatePositionMatrix()
{
	_localMatrix.t = CIwFVec2(_positionX, _positionY);
	//CalculateLocalMatrix();
	//CalculateAbsoluteMatrix();
}

void TransformComponent::CalculateScaleRotationMatrix()
{
	double angr = _angle * 2 * PI / 360;
	_localMatrix.m[0][0] = (float)cos(angr) * _scaleX;
	_localMatrix.m[0][1] = -(float)sin(angr) * _scaleY;
	_localMatrix.m[1][0] = (float)sin(angr) * _scaleX;
	_localMatrix.m[1][1] = (float)cos(angr) * _scaleY;
}

void TransformComponent::CalculateAbsoluteMatrix()
{
	if(_parentTransform != nullptr)
		_absoluteMatrix = _localMatrix * _parentTransform->GetAbsoluteMatrix();
}


/* transform position */
void TransformComponent::SetPosition(CIwFVec2 position)
{
	SetPosition(position.x, position.y);
}

void TransformComponent::SetPosition(float x, float y)
{
	_positionX = x; 
	_positionY = y;
	CalculateLocalMatrix();
	CalculateAbsoluteMatrix();
}

CIwFVec2 TransformComponent::GetPosition() const
{ 
	return CIwFVec2(_positionX, _positionY); 
}

float TransformComponent::GetPositionX() const
{ 
	return _positionX; 
}

float TransformComponent::GetPositionY()  const
{ 
	return _positionY; 
}

/* transform scale */
void TransformComponent::SetScale(float scale) 
{ 
	SetScale(scale, scale); 
}

void TransformComponent::SetScale(float x, float y) 
{ 
	_scaleX = x; 
	_scaleY = y; 
	CalculateLocalMatrix();
	CalculateAbsoluteMatrix();
}

CIwFVec2 TransformComponent::GetScale() const
{ 
	return CIwFVec2(_scaleX, _scaleY); 
}

float TransformComponent::GetScaleX() const
{ 
	return _scaleX; 
}

float TransformComponent::GetScaleY() const
{ 
	return _scaleY; 
}

/* transform angle */
void TransformComponent::SetAngle(float angle)
{ 
	_angle = angle; 
	CalculateLocalMatrix();
	CalculateAbsoluteMatrix();
}

float TransformComponent::GetAngle() const
{ 
	return _angle; 
}

const TransformComponent * TransformComponent::GetParentTransform() const
{
	return _parentTransform;
}

void TransformComponent::SetParentTransform(const TransformComponent * transform)
{
	_parentTransform = transform;
}


const CIwFMat2D& TransformComponent::GetAbsoluteMatrix() const
{
	return _absoluteMatrix;
}

CIwFMat2D& TransformComponent::GetAbsoluteMatrix()
{
	CalculateLocalMatrix();
	CalculateAbsoluteMatrix();
	return _absoluteMatrix;
}

const CIwFMat2D& TransformComponent::GetLocalMatrix() const
{
	return _localMatrix;
}

CIwFMat2D& TransformComponent::GetLocalMatrix()
{
	return _localMatrix;
}

void TransformComponent::SetAnchorOffset(const CIwFVec2& offset)
{
	_anchorOffset = offset;
	CalculateLocalMatrix();
	CalculateAbsoluteMatrix();
}

CIwFVec2& TransformComponent::GetAnchorOffet()
{
	return _anchorOffset;
}

const CIwFVec2& TransformComponent::GetAnchorOffet() const
{
	return _anchorOffset;
}



