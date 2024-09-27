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

		void OnCollisionEnter(class Collider* other) override;
		void OnCollisionStay(class Collider* other) override;
		void OnCollisionExit(class Collider* other) override;

	private:
	};
}