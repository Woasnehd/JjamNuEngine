#pragma once
#include "..\JjamEngine_SOURCE\\JjamSceneManager.h"
#include "JjamPlayScene.h"
#include "JjamEndScene.h"
#include "JjamStartScene.h"

namespace Jjam
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<EndScene>(L"EndScene");
		SceneManager::CreateScene<StartScene>(L"StartScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}