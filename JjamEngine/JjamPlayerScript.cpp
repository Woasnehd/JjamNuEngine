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
#include "JjamAttack.h"
#include "JjamAttackScript.h"


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
            BasicAttack();
			break;

        case PlayerScript::eState::Skill1:
            Skill1();
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

    void PlayerScript::BasicAttack()
    {
        Attack* att = object::Instantiate<Attack>(enums::eLayerType::OtherObjects);
        AttackScript* attSrc = att->AddComponent<AttackScript>();

        attSrc->SetOwner(GetOwner());

        graphics::Texture* attTex = Resources::Find<graphics::Texture>(L"BasicAttack");
        Animator* attAnimator = att->AddComponent<Animator>();

        attAnimator->CreateAnimation(L"Attack", attTex
            , Vector2(0.0f, 0.0f), Vector2(50.0f, 50.0f), Vector2::Zero, 7, 0.1f);

        attAnimator->PlayAnimation(L"SitDown", false);

        Transform* tr = GetOwner()->GetComponent<Transform>();
        att->GetComponent<Transform>()->SetPosition(tr->GetPosition());

        Vector2 mousePos = Input::GetMousePosition();
        attSrc->mDest = mousePos;
    }

    void PlayerScript::Skill1()
    {
        if (mAnimator->IsPlaying(L"Skill1")) {
            mState = PlayerScript::eState::Idle;
            mAnimator->PlayAnimation(L"Idle", false);
        }
    }

    void PlayerScript::idle()
    {
        if (Input::GetKey(eKeyCode::LButton)) {
            Attack* att = object::Instantiate<Attack>(enums::eLayerType::Particle);
            AttackScript* attSrc = att->AddComponent<AttackScript>();
            
            attSrc->SetPlayer(GetOwner());

            graphics::Texture* attTex = Resources::Find<graphics::Texture>(L"BasicAttack");
            Animator* attAnimator = att->AddComponent<Animator>();

            attAnimator->CreateAnimation(L"Attack", attTex
                , Vector2(0.0f, 0.0f), Vector2(50.0f, 50.0f), Vector2::Zero, 7, 0.3f);

            attAnimator->PlayAnimation(L"Attack", false);

            Transform* tr = GetOwner()->GetComponent<Transform>();
            Vector2 objectPos = tr->GetPosition();
            objectPos.x += 40;
            objectPos.y += 100;

            att->GetComponent<Transform>()->SetPosition(objectPos);

            Vector2 mousePos = Input::GetMousePosition();
            attSrc->mDest = mousePos;
        }

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

        if (Input::GetKey(eKeyCode::E))
        {
            mState = PlayerScript::eState::Skill1;
            mAnimator->PlayAnimation(L"Skill1", false);
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

        if (Input::GetKey(eKeyCode::E))
        {
            mState = PlayerScript::eState::Skill1;
            mAnimator->PlayAnimation(L"Skill1", false);
        }

        if (Input::GetKey(eKeyCode::LButton)) {
            Attack* att = object::Instantiate<Attack>(enums::eLayerType::Particle);
            AttackScript* attSrc = att->AddComponent<AttackScript>();

            attSrc->SetPlayer(GetOwner());

            graphics::Texture* attTex = Resources::Find<graphics::Texture>(L"BasicAttack");
            Animator* attAnimator = att->AddComponent<Animator>();

            attAnimator->CreateAnimation(L"Attack", attTex
                , Vector2(0.0f, 0.0f), Vector2(50.0f, 50.0f), Vector2::Zero, 7, 0.3f);

            attAnimator->PlayAnimation(L"Attack", false);

            Transform* tr = GetOwner()->GetComponent<Transform>();
            Vector2 objectPos = tr->GetPosition();
            objectPos.x += 40;
            objectPos.y += 100;

            att->GetComponent<Transform>()->SetPosition(objectPos);

            Vector2 mousePos = Input::GetMousePosition();
            attSrc->mDest = mousePos;
        }

        if (Input::GetKeyUp(eKeyCode::A)) {
            mAnimator->PlayAnimation(L"Left");
            mState = PlayerScript::eState::Idle;
        }

        if (Input::GetKeyUp(eKeyCode::D))
        {
            mState = PlayerScript::eState::Idle;
            mAnimator->PlayAnimation(L"Right");
        }

        tr->SetPosition(pos);
    }
}
