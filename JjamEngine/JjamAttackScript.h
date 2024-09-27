#pragma once
#include "..\JjamEngine_SOURCE\JjamScript.h"
#include "..\\JjamEngine_SOURCE\\JjamTransform.h"

namespace Jjam {
	class AttackScript : public Script
	{
		enum class eState
		{
			Fire,
			Hit,
			Down
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

	public:
		AttackScript();
		~AttackScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPlayer(GameObject* player) { mPlayer = player; }

		Vector2 mDest;

	private:
		void fire();
		void hit();

		void translate(Transform* tr);

	private:
		GameObject* mPlayer;

		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;

		float mTime;
		float mDeathTime;
	};
}