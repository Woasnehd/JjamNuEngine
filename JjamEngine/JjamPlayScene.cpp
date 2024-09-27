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
#include "JjamCamera.h"
#include "JjamRenderer.h"
#include "JjamPlayerScript.h"
#include "JjamMonsterScript.h"
#include "JjamAnimator.h"
#include "JjamAttack.h"
#include "JjamAttackScript.h"
#include "JjamBoxCollider2D.h"
#include "JjamCircleCollider2D.h"
#include "JjamColliderManager.h"

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
		ColliderManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Monsters, true);
		
		//Creating Background
		pbg = object::Instantiate<Background>(enums::eLayerType::Background, Vector2(0.0f, 0.0f));
		SpriteRenderer* bsr = pbg->AddComponent<SpriteRenderer>();

		//Rendering Background
		graphics::Texture* pbgtex = Resources::Find<graphics::Texture>(L"PlayBG");
		bsr->SetTexture(pbgtex);
		bsr->SetSize(Vector2(2.5f, 2.5f));

		//Creating Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		//Creating Player Object, Setting Camera Target
		player = object::Instantiate<Player>(enums::eLayerType::Player);
		PlayerScript* pScr = player->AddComponent<PlayerScript>();
		BoxCollider2D* boxCollider = player->AddComponent<BoxCollider2D>();
		boxCollider->SetOffSet(math::Vector2(-30.0f, 20.0f));

		cameraComp->SetTarget(player);

		//Rendering Player Object, Creating Player's Left Moving Motion Animation
		graphics::Texture* pLTexture = Resources::Find<graphics::Texture>(L"PlayerL");
		Animator* pAnimator = player->AddComponent<Animator>();
		pAnimator->CreateAnimation(L"Left", pLTexture
			, Vector2(0.0f, 0.0f), Vector2(238.0f, 266.0f), Vector2::Zero, 16, 0.2f);
		//Creating Player's Right Moving Motion Animation
		pLTexture = Resources::Find<graphics::Texture>(L"PlayerR");
		pAnimator->CreateAnimation(L"Right", pLTexture
			, Vector2(0.0f, 0.0f), Vector2(238.0f, 266.0f), Vector2::Zero, 16, 0.2f);
		//Creating Player's Skill1 Motion Animation
		pLTexture = Resources::Find<graphics::Texture>(L"PlayerS1");
		pAnimator->CreateAnimation(L"Skill1", pLTexture
			, Vector2(0.0f, 0.0f), Vector2(238.0f, 266.0f), Vector2::Zero, 19, 0.1f);
		//Creating Player's Down Motion Animation
		pLTexture = Resources::Find<graphics::Texture>(L"PlayerD");
		pAnimator->CreateAnimation(L"Down", pLTexture
			, Vector2(0.0f, 0.0f), Vector2(238.0f, 266.0f), Vector2::Zero, 34, 0.1f);

		//Setting Init Player Object Position, Scale
		player->GetComponent<Transform>()->SetPosition(Vector2(800.0f, 450.0f));
		player->GetComponent<Transform>()->SetScale(Vector2(1.5f, 1.5f));


		//Rendering Init Player Object Animation
		pAnimator->PlayAnimation(L"Left");
		//Setting EventFunction
		pAnimator->GetCompleteEvent(L"Skill1") = bind(&PlayerScript::Skill1, pScr);

		for (int i = 0; i < 1; i++) {
			//Creating Basic Monster Object
			monster = object::Instantiate<Monster>(enums::eLayerType::Monsters, Vector2(rand() % 1500 + 1, rand() % 700 + 1));
			monster->AddComponent<MonsterScript>();

			CircleCollider2D* mBoxCollider = monster->AddComponent<CircleCollider2D>();
			mBoxCollider->SetOffSet(math::Vector2(-45.0f, -30.0f));

			//Rendering Monster Object, Creating Monster's Left Moving Motion Animation
			graphics::Texture* mtex = Resources::Find<graphics::Texture>(L"FlyingMLeft");

			Animator* mAnimator = monster->AddComponent<Animator>();
			mAnimator->CreateAnimation(L"FlyingMLeftMove", mtex
				, Vector2(0.0f, 0.0f), Vector2(192.0, 192.0f), Vector2::Zero, 4, 0.1f);
			mAnimator->PlayAnimation(L"FlyingMLeftMove");
		}

		for (int i = 0; i < 1; i++) {
			//Creating Special Monster Object
			monster = object::Instantiate<Monster>(enums::eLayerType::Monsters, Vector2(rand() % 1500 + 1, rand() % 700 + 1));
			monster->AddComponent<MonsterScript>();

			BoxCollider2D* mBoxCollider = monster->AddComponent<BoxCollider2D>();
			mBoxCollider->SetOffSet(math::Vector2(-45.0f, -30.0f));

			//Rendering Monster Object, Creating Monster's Left Moving Motion Animation
			graphics::Texture* mtex = Resources::Find<graphics::Texture>(L"HeavyMRight");

			Animator* mAnimator = monster->AddComponent<Animator>();
			mAnimator->CreateAnimation(L"HeavyMRightMove", mtex
				, Vector2(0.0f, 0.0f), Vector2(192.0f, 192.0f), Vector2::Zero, 5, 0.1f);
			mAnimator->PlayAnimation(L"HeavyMRightMove");
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
		Scene::OnEnter();
	}

	void PlayScene::OnExit()
	{
		Scene::OnExit();
	}
}