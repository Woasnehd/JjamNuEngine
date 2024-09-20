#include "JjamLayer.h"

namespace Jjam {
	Layer::Layer()
		:mGameObjects {}
	{

	}

	Layer::~Layer()
	{

	}

	void Layer::Initialize()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr) {
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

			gameObject->Render(hdc);
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