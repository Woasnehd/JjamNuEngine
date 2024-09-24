#include "JjamPlayer.h"
#include "JjamInput.h"
#include "JjamTransform.h"
#include "JjamTime.h"


namespace Jjam
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(eKeyCode::D))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();

			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}