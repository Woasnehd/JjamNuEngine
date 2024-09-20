#pragma once
#include "CommonInclude.h"

namespace Jjam
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const wstring& name) { mName = name; }
		wstring& GetName() { return mName; }

	private:
		wstring mName;
	};
}