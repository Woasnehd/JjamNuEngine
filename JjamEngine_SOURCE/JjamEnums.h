#pragma once

namespace Jjam::enums {
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