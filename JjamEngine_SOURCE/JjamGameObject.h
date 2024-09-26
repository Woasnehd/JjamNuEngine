#pragma once
#include "CommonInclude.h"
#include "JjamComponent.h"

namespace Jjam
{
	class GameObject
	{
	public:
		enum class eState {
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}

		void SetActive(bool power);
		void Death() { mState = eState::Dead; }
		eState GetActive() { return mState; }

	private:
		void initializeTransform();

	private:
		eState mState;
		vector<Component*> mComponents;
	};
}