#pragma once
#include "CommonInclude.h"
#include "JjamBoxCollider2D.h"
#include "JjamCircleCollider2D.h"

namespace Jjam {
	union CollisionID {
		struct {
			UINT32 left;
			UINT32 right;
		};
		UINT64 id;
	};

	class ColliderManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, enums::eLayerType left, enums::eLayerType right);
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);

	private:
		static bitset<(UINT)enums::eLayerType::Max> mCollisionLayerMatrix[(UINT)enums::eLayerType::Max];
		static unordered_map<UINT64, bool> mCollisionMap;
	};
}