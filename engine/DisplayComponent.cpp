#include "DisplayComponent.h"

DisplayComponent::DisplayComponent() :
	_isVisible(true),
	_image(nullptr),
	_transform(nullptr),
	_anchorX(0.5f),
	_anchorY(0.5f)
{
}

void DisplayComponent::SetVisible(bool visible)
{
	_isVisible = visible; 
}

bool DisplayComponent::IsVisible() const 
{ 
	return _isVisible; 
}

void DisplayComponent::SetImage(CIw2DImage* image) 
{ 
	_image = image;
}

CIw2DImage* DisplayComponent::GetImage() const 
{ 
	return _image; 
}

void DisplayComponent::SetAnchor(float x, float y)
{
	_anchorX = x;
	_anchorY = y;
	_transform->SetAnchorOffset(CIwFVec2(_anchorX, _anchorY));
}

void DisplayComponent::SetAnchor(CIwFVec2 anchor)
{
	SetAnchor(anchor.x, anchor.y);
}

inline void DisplayComponent::SetAnchorX(float x)
{
	SetAnchor(x, _anchorY);
}

inline void DisplayComponent::SetAnchorY(float y)
{
	SetAnchor(_anchorX, y);
}

CIwFVec2 DisplayComponent::GetAnchor() const
{
	return CIwFVec2(_anchorX, _anchorY);
}

float DisplayComponent::GetAnchorX() const
{
	return _anchorX;
}

float DisplayComponent::GetAnchorY() const
{
	return _anchorY;
}

CIwFVec2 DisplayComponent::GetSize() const
{
	if (_image != nullptr)
		return CIwFVec2(_image->GetWidth(), _image->GetHeight());

	return CIwFVec2::g_Zero;
}

float DisplayComponent::GetSizeWidth() const
{
	if(_image != nullptr)
		return _image->GetWidth();

	return 0.0f;
}

float DisplayComponent::GetSizeHeight() const
{
	if (_image != nullptr)
		return _image->GetHeight();

	return 0.0f;
}

const CIwFMat2D& DisplayComponent::GetMatrix() const
{
	return _transform->GetAbsoluteMatrix();
}

void DisplayComponent::SetTransform(TransformComponent * transform)
{
	_transform = transform;
}

