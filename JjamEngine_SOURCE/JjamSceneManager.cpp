#include "JjamSceneManager.h"

namespace Jjam
{
	map<wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mDontDestroyOnLoad = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene) {
			mActiveScene->OnExit();
		}

		map<wstring, Scene*>::iterator iter = mScene.find(name);

		if (iter == mScene.end()) {
			return nullptr;
		}

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

	void SceneManager::Initialize()
	{
		mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
		mDontDestroyOnLoad->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
		mDontDestroyOnLoad->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
		mDontDestroyOnLoad->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}