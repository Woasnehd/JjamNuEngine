#include "JjamPlayScene.h"
#include "JjamGameObject.h"
#include "JjamPlayer.h"
#include "JjamBackGround.h"
#include "JjamTransform.h"
#include "JjamSpriteRenderer.h"
#include "JjamInput.h"
#include "JjamSceneManager.h"

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
		pbg = new Background();

		Transform* tr = pbg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = pbg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\Visual_Studio_2022\\JjamNu_Engine\\Resources\\Playing_Background.png");

		AddGameObject(pbg);
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
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"PlayScene";
		TextOut(hdc, 0, 20, str, 9);
	}
	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
		Transform* tr = pbg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}