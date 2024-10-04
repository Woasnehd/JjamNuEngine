#pragma once
#include "JjamScene.h"

namespace Jjam
{
	class DontDestroyOnLoad : public Scene
	{
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Background* pbg;
		class Player* player;
		class Monster* monster;
		class BasicAttack* attack;
	};
}