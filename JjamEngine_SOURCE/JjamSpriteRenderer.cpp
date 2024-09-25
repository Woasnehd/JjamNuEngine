#include "JjamSpriteRenderer.h"
#include "JjamGameObject.h"
#include "JjamTransform.h"
#include "JjamRenderer.h"
#include "JjamCamera.h"

namespace Jjam
{
	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponentType::SpriteRenderer), mTexture(nullptr), mSize(Vector2::One)
	{

	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Initialize()
	{

	}

	void SpriteRenderer::Update()
	{

	}

	void SpriteRenderer::LateUpdate()
	{

	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr) {
			assert(false);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 scale = tr->GetScale();
		float rot = tr->GetRotation();

		pos = renderer::mainCamera->CaluatePosition(pos);

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp) {
			TransparentBlt(hdc, pos.x, pos.y
				,mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeigt() * mSize.y * scale.y, mTexture->GetHdc(), 0, 0
				, mTexture->GetWidth(), mTexture->GetHeigt(), RGB(255, 0, 255));
		}

		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png) {
			Gdiplus::ImageAttributes imageAtt = {};

			imageAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphcis(hdc);

			graphcis.TranslateTransform(pos.x, pos.y);
			graphcis.RotateTransform(rot);
			graphcis.TranslateTransform(-pos.x, -pos.y);

			graphcis.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y,
					mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeigt() * mSize.y * scale.y),
				0, 0, mTexture->GetWidth(), mTexture->GetHeigt(), Gdiplus::UnitPixel, nullptr);
		}
	}
}