#pragma once
#include "..\JjamEngine_SOURCE\JjamGameObject.h"
#include "JjamPlayer.h"

namespace Jjam
{
	class Monster : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetHp(float demage) { hp -= demage; }
		float GetHp() { return hp; }

	private:
		float hp = 100;
	};
}