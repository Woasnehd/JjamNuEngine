#pragma once

namespace Jjam::enums {
	enum class eComponentType {
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End
	};

	enum class eLayerType {
		None,
		Background,
		OtherObjects,
		Player,
		Monsters,
		Max = 16
	};

	enum class eResourceType {
		Texture,
		AudioClip,
		Prefab,	//for saving data
		End
	};
}