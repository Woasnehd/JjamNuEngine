#include "JjamMonsterScript.h"
#include "JjamInput.h"
#include "JjamTime.h"
#include "JjamTransform.h"
#include "JjamGameObject.h"
#include "JjamLayer.h"
#include "JjamSceneManager.h"

namespace Jjam {
	MonsterScript::MonsterScript()
	{

	}

	MonsterScript::~MonsterScript()
	{

	}

	void MonsterScript::Initialize()
	{

	}

	void MonsterScript::Update()
	{
		Transform* mtr = GetOwner()->GetComponent<Transform>();
		Vector2 mpos = mtr->GetPosition();

		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* playerLayer = activeScene->GetLayer(enums::eLayerType::Player);

		if (!playerLayer->GetGameObjects().empty())
		{
			GameObject* player = playerLayer->GetGameObjects().front();
			Transform* playerTransform = player->GetComponent<Transform>();
			Vector2 playerPos = playerTransform->GetPosition();

			Vector2 direction = playerPos - mpos;
			direction.Normalize();

			float speed = 50.0f;

			mpos = mpos + (direction * speed * Time::DeltaTime());
			mtr->SetPosition(mpos);
		}
	}

	void MonsterScript::LateUpdate()
	{

	}

	void MonsterScript::Render(HDC hdc)
	{

	}
}