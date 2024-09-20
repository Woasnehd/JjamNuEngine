#pragma once
#include "..\JjamEngine_SOURCE\JjamGameObject.h"

namespace Jjam
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}