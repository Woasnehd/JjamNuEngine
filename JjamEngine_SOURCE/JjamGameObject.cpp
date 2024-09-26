#include "JjamGameObject.h"
#include "JjamInput.h"
#include "JjamTime.h"
#include "JjamTransform.h"

namespace Jjam
{
	GameObject::GameObject()
		:mState(eState::Active)
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) {
				continue;
			}

			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) {
				continue;
			}

			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) {
				continue;
			}

			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) {
				continue;
			}

			comp->Render(hdc);
		}
	}

	void GameObject::SetActive(bool power)
	{
		if (power == true) {
			mState = eState::Active;
		}

		if (power == false) {
			mState = eState::Paused;
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}