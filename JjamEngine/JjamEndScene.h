#pragma once
#include "..\JjamEngine_SOURCE\\JjamScene.h"

namespace Jjam
{
	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		bool result;
		int score;
	};
}