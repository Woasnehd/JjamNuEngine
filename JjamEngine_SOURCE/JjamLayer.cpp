#include "JjamLayer.h"

namespace Jjam {
	Layer::Layer()
		:mGameObjects {}
	{

	}

	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr) {
				continue;
			}

			GameObject::eState state = gameObject->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) {
				continue;
			}

			gameObject->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr) {
				continue;
			}

			GameObject::eState state = gameObject->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) {
				continue;
			}

			gameObject->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr) {
				continue;
			}

			GameObject::eState state = gameObject->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) {
				continue;
			}

			gameObject->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr) {
				continue;
			}

			GameObject::eState state = gameObject->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead) {
				continue;
			}

			gameObject->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for (gameObjIter it = mGameObjects.begin(); it < mGameObjects.end();)
		{
			GameObject::eState active = (*it)->GetActive();

			if (active == GameObject::eState::Dead) {
				GameObject* deathObj = (*it);
				it = mGameObjects.erase(it);

				delete deathObj;
				deathObj = nullptr;
				continue;
			}

			it++;
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr) {
			return;
		}

		mGameObjects.push_back(gameObject);
	}
}