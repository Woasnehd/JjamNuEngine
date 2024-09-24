#pragma once
#include "JjamEntity.h"

namespace Jjam {
	class Resource : public Entity{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const wstring& path) = 0;

		const wstring& GetPath() { return mPath; }
		void SetPath(const wstring& path) { mPath = path; }

	private:
		enums::eResourceType mType;
		wstring mPath;
	};
}