#include "JjamEndScene.h"
#include "JjamBackGround.h"
#include "JjamTransform.h"
#include "JjamSpriteRenderer.h"
#include "JjamInput.h"
#include "JjamSceneManager.h"
#include "JjamObject.h"
#include "JjamTexture.h"
#include "JjamResources.h"

namespace Jjam {
	EndScene::EndScene()
		:result(false), score(0)
	{

	}

	EndScene::~EndScene()
	{

	}

	void EndScene::Initialize()
	{
		ebg = object::Instantiate<Background>(enums::eLayerType::Background, Vector2(0.0f, 0.0f));
		SpriteRenderer* bsr = ebg->AddComponent<SpriteRenderer>();

		graphics::Texture* ebg = Resources::Find<graphics::Texture>(L"EndBG");
		bsr->SetTexture(ebg);
	}

	void EndScene::Update()
	{
		Scene::Update();
	}

	void EndScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"EndScene";
		TextOut(hdc, 0, 20, str, 8);
	}
}