#pragma once
#include "..\JjamEngine_SOURCE\JjamScript.h"

namespace Jjam {
	class PlayerScript : public Script
	{
	public:
		enum class eState {
			Idle,
			Move,
			Attack,
			Skill1,
			Down
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Attack();
		void Skill1();

	private:
		void idle();
		void move();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}