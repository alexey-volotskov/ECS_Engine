#pragma once
#include "TransformComponent.h"


class DisplayComponent : public IComponent
{
private:
	TransformComponent* _transform;
	CIw2DImage* _image;
	
	float		_anchorX, _anchorY;
	bool		_isVisible;

public:
	DisplayComponent();

	void SetVisible(bool visible);
	bool IsVisible() const;

	void SetImage(CIw2DImage* image);
	CIw2DImage* GetImage() const;

	/* anchor */
	void SetAnchor(float x, float y);
	void SetAnchor(CIwFVec2 anchor);
	void SetAnchorX(float x);
	void SetAnchorY(float y);

	CIwFVec2 GetAnchor() const;
	float GetAnchorX() const;
	float GetAnchorY() const;

	CIwFVec2 GetSize() const;
	float GetSizeWidth() const;
	float GetSizeHeight() const;

	const CIwFMat2D& GetMatrix() const;

	void SetTransform(TransformComponent* transform);
};