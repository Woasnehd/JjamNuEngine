#pragma once

namespace Jjam::enums {
	enum class eComponentType {
		Transform,
		Collider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End
	};

	enum class eLayerType {
		None,
		Background,
		OtherObjects,
		Player,
		Monsters,
		Particle,
		Max = 16
	};

	enum class eResourceType {
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End
	};

	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};
}