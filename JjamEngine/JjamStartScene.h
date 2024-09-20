#pragma once
#include "..\JjamEngine_SOURCE\\JjamScene.h"

namespace Jjam
{
	class StartScene : public Scene
	{
	public:
		StartScene();
		~StartScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}