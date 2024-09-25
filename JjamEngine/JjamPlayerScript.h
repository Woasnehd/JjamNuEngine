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
			Down
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void AttackEffect();

	private:
		void idle();
		void move();

	private:
		eState mState;
		class Animator* mAnimator;

		/*void (*StartEvent)();
		void (*CompleteEvent)();
		void (*EndEvent)();*/
	};
}