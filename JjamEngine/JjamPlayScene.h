#pragma once
#include "..\JjamEngine_SOURCE\\JjamScene.h"

namespace Jjam
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

		int GetMonsterCount() { return mMonsterCount; }
		void SetMonsterCount(int num) { mMonsterCount = num; }

	private:
		class Background* pbg;
		class Player* player;
		class Monster* monster;
		class BasicAttack* attack;

		int mMonsterCount = 40;
	};
}