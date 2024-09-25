#include "JjamCamera.h"
#include "JjamGameObject.h"
#include "JjamTransform.h"
#include "JjamApplication.h"

extern Jjam::Application application;

namespace Jjam {
	Camera::Camera()
		:Component(enums::eComponentType::Camera),
		mDistance(math::Vector2::Zero),
		mResolution(math::Vector2::Zero),
		mLookPosition(math::Vector2::Zero),
		mTarget(nullptr)
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}

	void Camera::Update()
	{
		if (mTarget) {
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::LateUpdate()
	{

	}

	void Camera::Render(HDC hdc)
	{

	}
}