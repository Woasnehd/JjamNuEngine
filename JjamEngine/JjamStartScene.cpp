#include "JjamStartScene.h"
#include "JjamBackGround.h"
#include "JjamTransform.h"
#include "JjamSpriteRenderer.h"
#include "JjamInput.h"
#include "JjamSceneManager.h"
#include "JjamObject.h"
#include "JjamTexture.h"
#include "JjamResources.h"

namespace Jjam {
	StartScene::StartScene()
	{

	}

	StartScene::~StartScene()
	{

	}

	void StartScene::Initialize()
	{
		sbg = object::Instantiate<Background>(enums::eLayerType::Background, Vector2(0.0f, 0.0f));
		SpriteRenderer* bsr = sbg->AddComponent<SpriteRenderer>();

		graphics::Texture* sbgtex = Resources::Find<graphics::Texture>(L"StartBG");
		bsr->SetTexture(sbgtex);
		bsr->SetSize(Vector2(1.0f, 1.1f));

		sbg = object::Instantiate<Background>(enums::eLayerType::OtherObjects, Vector2(420.0f, 50.0f));
		bsr = sbg->AddComponent<SpriteRenderer>();

		sbgtex = Resources::Find<graphics::Texture>(L"Logo");
		bsr->SetTexture(sbgtex);
		bsr->SetSize(Vector2(1.25f, 1.25f));
	}

	void StartScene::Update()
	{
		Scene::Update();
	}

	void StartScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::B)) {
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void StartScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		/*wchar_t str[50] = L"StartScene";
		TextOut(hdc, 0, 20, str, 9);*/
	}
}