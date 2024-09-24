#pragma once
#include "..\JjamEngine_SOURCE\JjamScript.h"

namespace Jjam {
	class MonsterScript : public Script
	{
	public:
		MonsterScript();
		~MonsterScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}