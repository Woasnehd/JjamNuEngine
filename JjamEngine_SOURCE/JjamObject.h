#pragma once
#include "JjamComponent.h"
#include "JjamGameObject.h"
#include "JjamLayer.h"
#include "JjamScene.h"
#include "JjamSceneManager.h"
#include "JjamTransform.h"

namespace Jjam::object
{
	template <typename T>
	static T* Instantiate(Jjam::enums::eLayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);

		layer->AddGameObject(gameObject);

		return gameObject;
	}
	template <typename T>
	static T* Instantiate(Jjam::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);

		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* obj) {
		obj->Death();
	}

	static void DontDestroyOnLoad(GameObject* obj) {
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->EraseGameObejct(obj);

		Scene* donDestroyOnLoad = SceneManager::GetDestroyOnLoad();
		donDestroyOnLoad->AddGameObject(obj, obj->GetLayerType());
	}
}