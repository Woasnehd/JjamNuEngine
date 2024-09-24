#pragma once
#include "JjamComponent.h"

namespace Jjam {
	class Camera : public Component
	{
	public:
		math::Vector2 CaluatePosition(math::Vector2 pos) { return pos - mDistance; }

		Camera();
		~Camera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
		class GameObject* mTarget;

		math::Vector2 mDistance;
		math::Vector2 mResolution;
		math::Vector2 mLookPosition;
	};
}
