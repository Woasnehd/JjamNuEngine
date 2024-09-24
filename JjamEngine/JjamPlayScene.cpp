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
		bsr->SetSize(Vector2(1.25f, 1.25f));

		player = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(100.0f, 625.0f));
		SpriteRenderer* psr = player->AddComponent<SpriteRenderer>();
		Script* psc = player->AddComponent<PlayerScript>();

		graphics::Texture* ptex = Resources::Find<graphics::Texture>(L"Player");
		psr->SetTexture(ptex);

		monster = object::Instantiate<Monster>(enums::eLayerType::Monsters, Vector2(400.0f, 625.0f));
		SpriteRenderer* msr = monster->AddComponent<SpriteRenderer>();
		Script* msc = monster->AddComponent<MonsterScript>();

		graphics::Texture* mtex = Resources::Find<graphics::Texture>(L"Monster1");
		msr->SetTexture(mtex);

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