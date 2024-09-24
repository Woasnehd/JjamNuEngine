#pragma once
#include "JjamResource.h"

namespace Jjam::graphics {
	class Texture : public Resource {
	public:
		enum class eTextureType {
			Bmp,
			Png,
			None
		};

		Texture();
		~Texture();

		virtual HRESULT Load(const wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeigt() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		eTextureType mType;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}
