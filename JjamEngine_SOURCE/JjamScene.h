#pragma once
#include "JjamEntity.h"
#include "JjamGameObject.h"

namespace Jjam
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		vector<GameObject*> mGameObjects;
	};
}