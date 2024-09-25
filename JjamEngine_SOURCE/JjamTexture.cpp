#include "JjamTexture.h"
#include "JjamApplication.h"

extern Jjam::Application application;

namespace Jjam::graphics {
	Texture::Texture()
		:Resource(enums::eResourceType::Texture),
		mImage(nullptr),
		mBitmap(NULL),
		mHdc(nullptr),
		mWidth(0),
		mHeight(0)
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const wstring& path)
	{
		wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp") {
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr) {
				return S_FALSE;
			}

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}

		else if (ext == L"png") {
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());

			if (mImage == nullptr) {
				return S_FALSE;
			}

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();

			// HDC·Î º¯È¯
			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP bitmap;
			Gdiplus::Bitmap bmp(mWidth, mHeight, PixelFormat32bppARGB);
			Gdiplus::Graphics graphics(&bmp);
			graphics.DrawImage(mImage, 0, 0, mWidth, mHeight);

			bmp.GetHBITMAP(Gdiplus::Color(0, 0, 0), &bitmap);
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, bitmap);

			DeleteObject(oldBitmap);
		}
	
		return S_OK;
	}

}
