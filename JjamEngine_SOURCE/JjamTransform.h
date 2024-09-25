#pragma once
#include "JjamEntity.h"
#include "JjamComponent.h"

namespace Jjam
{
	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		void SetRotation(float rotate) { mRotation = rotate; }
		void SetScale(Vector2 scale) { mScale = scale; }

		Vector2 GetPosition() { return mPosition; }
		float GetRotation() { return mRotation; }
		Vector2 GetScale() { return mScale; }

	private:
		Vector2 mPosition;
		Vector2 mScale;

		float mRotation;
	};
}