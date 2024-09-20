#pragma once
#include "JjamEntity.h"
#include "JjamComponent.h"

namespace Jjam
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void ImageLoad(const wstring& path);

	private:
		Gdiplus::Image* mImgae;

		UINT mWidth;
		UINT mHeight;
	};
}