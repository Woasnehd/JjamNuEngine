#pragma once
#include "JjamEntity.h"
#include "JjamGameObject.h"

namespace Jjam {
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);

		const vector<GameObject*>& GetGameObjects() { return mGameObjects; }

	private:
		vector<GameObject*> mGameObjects;
	};

	typedef vector<GameObject*>::iterator gameObjIter;
}
