#include "JjamPlayerScript.h"
#include "JjamInput.h"
#include "JjamTime.h"
#include "JjamTransform.h"
#include "JjamGameObject.h"
#include "JjamAnimator.h"
#include "JjamResources.h"
#include "JjamPlayer.h"
#include "JjamObject.h"
#include "JjamResources.h"


namespace Jjam {
	PlayerScript::PlayerScript()
		:mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{

	}

	PlayerScript::~PlayerScript()
	{

	}

	void PlayerScript::Initialize()
	{
		
	}

	void PlayerScript::Update()
	{
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case PlayerScript::eState::Idle:
			idle();
			break;

		case PlayerScript::eState::Move:
			move();
			break;

		case PlayerScript::eState::Attack:
			break;

		case PlayerScript::eState::Down:
			break;

		default:
			break;
		}
	}

	void PlayerScript::LateUpdate()
	{

	}

	void PlayerScript::Render(HDC hdc)
	{

	}

    void PlayerScript::idle()
    {
        if (Input::GetKey(eKeyCode::D))
        {
            mState = PlayerScript::eState::Move;
            mAnimator->PlayAnimation(L"Right");
        }
        if (Input::GetKey(eKeyCode::A))
        {
            mState = PlayerScript::eState::Move;
            mAnimator->PlayAnimation(L"Left");
        }
        if (Input::GetKey(eKeyCode::W))
        {
            mState = PlayerScript::eState::Move; 
        }
        if (Input::GetKey(eKeyCode::S))
        {
            mState = PlayerScript::eState::Move;
        }
    }

    void PlayerScript::move()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();

        if (Input::GetKey(eKeyCode::D))
        {
            pos.x += 100.0f * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::A))
        {
            pos.x -= 100.0f * Time::DeltaTime();
        }

        if (Input::GetKey(eKeyCode::W))
        {
            pos.y -= 100.0f * Time::DeltaTime();
        }
        if (Input::GetKey(eKeyCode::S))
        {
            pos.y += 100.0f * Time::DeltaTime();
        }

        if (Input::GetKeyUp(eKeyCode::A)) {
            mAnimator->PlayAnimation(L"Left");
            mState = PlayerScript::eState::Idle;
        }

        if (Input::GetKeyUp(eKeyCode::D))
        {
            /*mAnimator->PlayAnimation(L"RightIdle");*/
            mState = PlayerScript::eState::Idle;
        }

        tr->SetPosition(pos);
    }
}
