#include "JjamTransform.h"
#include "JjamInput.h"
#include "JjamTime.h"

namespace Jjam
{
	Transform::Transform()
		:Component(enums::eComponentType::Transform)
		, mScale(Vector2::One),
		mRotation(0.0f)
	{

	}

	Transform::~Transform()
	{

	}

	void Transform::Initialize()
	{

	}

	void Transform::Update()
	{

	}

	void Transform::LateUpdate()
	{

	}

	void Transform::Render(HDC hdc)
	{

	}
}