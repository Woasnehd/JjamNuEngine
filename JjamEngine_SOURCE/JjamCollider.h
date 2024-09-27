#pragma once
#include "JjamComponent.h"

namespace Jjam {
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
	private:

	};
}