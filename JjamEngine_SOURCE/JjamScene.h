#pragma once
#include "JjamEntity.h"
#include "JjamGameObject.h"
#include "JjamLayer.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, eLayerType type);

	private:
		vector<Layer*> mLayers;
	};
}