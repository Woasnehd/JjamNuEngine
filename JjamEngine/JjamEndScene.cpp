#include "JjamEndScene.h"
#include "JjamBackGround.h"
#include "JjamTransform.h"
#include "JjamSpriteRenderer.h"
#include "JjamInput.h"
#include "JjamSceneManager.h"

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
		Background* ebg = new Background();

		Transform* tr = ebg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = ebg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\Visual_Studio_2022\\JjamNu_Engine\\Resources\\Ending_Background.png");

		AddGameObject(ebg);
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
	}
}