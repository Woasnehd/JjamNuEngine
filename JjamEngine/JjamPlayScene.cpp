#include "JjamPlayScene.h"
#include "JjamApplication.h"
#include "JjamGameObject.h"
#include "JjamPlayer.h"
#include "JjamMonster.h"
#include "JjamBackGround.h"
#include "JjamTransform.h"
#include "JjamSpriteRenderer.h"
#include "JjamInput.h"
#include "JjamSceneManager.h"
#include "JjamObject.h"
#include "JjamTexture.h"
#include "JjamResources.h"
#include "JjamPlayerScript.h"
#include "JjamCamera.h"
#include "JjamRenderer.h"
#include "JjamMonsterScript.h"
#include "JjamAnimator.h"

extern Jjam::Application application;

namespace Jjam
{
	PlayScene::PlayScene()
	{

	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(application.GetWidth() / 2, application.GetHeight() / 2));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		pbg = object::Instantiate<Background>(enums::eLayerType::Background, Vector2(0.0f, 0.0f));
		SpriteRenderer* bsr = pbg->AddComponent<SpriteRenderer>();

		graphics::Texture* pbgtex = Resources::Find<graphics::Texture>(L"PlayBG");
		bsr->SetTexture(pbgtex);
		bsr->SetSize(Vector2(2.5f, 2.5f));

		player = object::Instantiate<Player>(enums::eLayerType::Player);
		PlayerScript* pScr = player->AddComponent<PlayerScript>();
		cameraComp->SetTarget(player);

		graphics::Texture* pLTexture = Resources::Find<graphics::Texture>(L"PlayerL");
		Animator* pAnimator = player->AddComponent<Animator>();
		pAnimator->CreateAnimation(L"Left", pLTexture
			, Vector2(0.0f, 0.0f), Vector2(340.0f, 380.0f), Vector2::Zero, 6, 0.2f);

		pLTexture = Resources::Find<graphics::Texture>(L"PlayerR");
		pAnimator->CreateAnimation(L"Right", pLTexture
			, Vector2(0.0f, 0.0f), Vector2(340.0f, 380.0f), Vector2::Zero, 6, 0.2f);

		/*pAnimator->CreateAnimation(L"LeftAttack", pLTexture
			, Vector2(0.0f, 100.0f), Vector2(52.0f, 50.0f), Vector2::Zero, 7, 0.1f);
		pAnimator->CreateAnimation(L"LeftDown", pLTexture
			, Vector2(0.0f, 450.0f), Vector2(52.0f, 50.0f), Vector2::Zero, 4, 0.1f);*/

		pAnimator->PlayAnimation(L"Left");

		pAnimator->GetCompleteEvent(L"") = bind(&PlayerScript::AttackEffect, pScr);

		player->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		player->GetComponent<Transform>()->SetScale(Vector2(0.7f, 0.7f));

		for (int i = 0; i < 20; i++) {
			monster = object::Instantiate<Monster>(enums::eLayerType::FlyingMonsters, Vector2(rand() % 1500 + 1, rand() % 700 + 1));
			monster->AddComponent<MonsterScript>();
			graphics::Texture* mtex = Resources::Find<graphics::Texture>(L"FlyingMLeft");

			Animator* mAnimator = monster->AddComponent<Animator>();
			mAnimator->CreateAnimation(L"FlyingMLeftMove", mtex
				, Vector2(0.0f, 0.0f), Vector2(192.0, 192.0f), Vector2::Zero, 4, 0.1f);
			mAnimator->PlayAnimation(L"FlyingMLeftMove", true);
		}

		for (int i = 0; i < 5; i++) {
			monster = object::Instantiate<Monster>(enums::eLayerType::HeavyMonsters, Vector2(rand() % 1500 + 1, rand() % 700 + 1));
			monster->AddComponent<MonsterScript>();
			graphics::Texture* mtex = Resources::Find<graphics::Texture>(L"HeavyMRight");

			Animator* mAnimator = monster->AddComponent<Animator>();
			mAnimator->CreateAnimation(L"HeavyMRightMove", mtex
				, Vector2(0.0f, 0.0f), Vector2(192.0f, 192.0f), Vector2::Zero, 5, 0.1f);
			mAnimator->PlayAnimation(L"HeavyMRightMove", true);
		}

		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"EndScene");
		}

		if (Input::GetKeyDown(eKeyCode::B)) {
			SceneManager::LoadScene(L"StartScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		/*wchar_t str[50] = L"PlayScene";
		TextOut(hdc, 0, 20, str, 9);*/
	}
	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
		Transform* tr = pbg->AddComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}
}