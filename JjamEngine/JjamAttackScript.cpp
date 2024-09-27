#include "JjamAttackScript.h"
#include "JjamTime.h"
#include "JjamAnimator.h"
#include "JjamObject.h"
#include "JjamGameObject.h"
#include "JjamTransform.h"

namespace Jjam {
	AttackScript::AttackScript()
		:mState(AttackScript::eState::Fire)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mDeathTime(0.0f)
		, mDest(Vector2::Zero)
	{

	}

	AttackScript::~AttackScript()
	{

	}

	void AttackScript::Initialize()
	{

	}

	void AttackScript::Update()
	{
		mDeathTime += Time::DeltaTime();
		if (mDeathTime > 2.0f)
		{
			/*object::Destory(GetOwner());*/
		}

		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Jjam::AttackScript::eState::Fire:
			fire();
			break;

		case Jjam::AttackScript::eState::Hit:
			hit();
			break;

		case Jjam::AttackScript::eState::Down:
			break;

		default:
			break;
		}
	}

	void AttackScript::LateUpdate()
	{

	}

	void AttackScript::Render(HDC hdc)
	{

	}

	void AttackScript::fire()
	{
		mTime += Time::DeltaTime();

		if (mTime > 4.0f)
		{
			object::Destroy(GetOwner());
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Transform* plTr = mPlayer->GetComponent<Transform>();

		Vector2 dest = mDest - plTr->GetPosition();
		pos += dest.Normalize() * (300.0f * Time::DeltaTime());

		tr->SetPosition(pos);
	}

	void AttackScript::hit()
	{

	}

	void AttackScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case AttackScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case AttackScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case AttackScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case AttackScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}

		tr->SetPosition(pos);
	}
}