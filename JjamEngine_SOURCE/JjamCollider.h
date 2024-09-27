#pragma once
#include "JjamComponent.h"

namespace Jjam {
	class Collider : public Component
	{
	public:
		Collider(enums::eColliderType type);
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		math::Vector2 GetOffSet() { return mOffset; }
		void SetOffSet(math::Vector2 offset) { mOffset = offset; }
		UINT32 GetID() { return mID; }
		math::Vector2 GetSize() { return mSize; }
		void SetSize(math::Vector2 size) { mSize = size; }
		enums::eColliderType GetColliderType() { return mType; }

	private:
		static UINT32 mCollisionID;
		UINT32 mID;
		enums::eColliderType mType;

		math::Vector2 mOffset;
		math::Vector2 mSize;
	};
}