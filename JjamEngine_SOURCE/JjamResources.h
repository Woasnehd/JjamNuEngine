#pragma once
#include "JjamResource.h"

namespace Jjam {
	class Resources
	{
	public:
		template<typename T>
		static T* Find(const wstring& key) {
			auto it = mResources.find(key);

			if (it == mResources.end()) {
				return nullptr;
			}

			return dynamic_cast<T*>(it->second);
		}

		template<typename T>
		static T* Load(const wstring& key, const wstring& path) {
			T* resource = Resources::Find<T>(key);

			if (resource != nullptr) {
				return resource;
			}

			resource = new T();

			if (FAILED(resource->Load(path))) {
				assert(false);
			}
			
			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(make_pair(key, resource));

			return resource;
		}

		static void Release()
		{
			for (auto& iter : mResources)
			{
				delete iter.second;
				iter.second = nullptr;
			}
		}

	private:
		static map<wstring, Resource*> mResources;
	};
}
