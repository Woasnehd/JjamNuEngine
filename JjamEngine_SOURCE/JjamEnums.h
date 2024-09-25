#pragma once

namespace Jjam::enums {
	enum class eComponentType {
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End
	};

	enum class eLayerType {
		None,
		Background,
		OtherObjects,
		Player,
		FlyingMonsters,
		HeavyMonsters,
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
}