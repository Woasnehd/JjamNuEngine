#include "JjamAnimation.h"
#include "JjamTime.h"
#include "JjamTransform.h"
#include "JjamGameObject.h"
#include "JjamAnimator.h"
#include "JjamRenderer.h"
#include "JjamCamera.h"

namespace Jjam {
    Animation::Animation()
        : Resource(enums::eResourceType::Animation)
        , mAnimator(nullptr)
        , mTexture(nullptr)
        , mAnimationSheet{}
        , mIndex(-1)
        , mTime(0.0f)
        , mbComplete(false)
    {

    }

    Animation::~Animation()
    {

    }

    HRESULT Animation::Load(const std::wstring& path)
    {
        return E_NOTIMPL;
    }

    void Animation::Update()
    {
        if (mbComplete)
            return;

        mTime += Time::DeltaTime();
        if (mAnimationSheet[mIndex].duration < mTime)
        {
            mTime = 0.0f;

            if (mIndex < mAnimationSheet.size() - 1)
                mIndex++;
            else
                mbComplete = true;
        }
    }

    void Animation::Render(HDC hdc)
    {
        if (mTexture == nullptr)
            return;

        GameObject* gameObj = mAnimator->GetOwner();
        Transform* tr = gameObj->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        Vector2 scale = tr->GetScale();
        float rot = tr->GetRotation();


        if (renderer::mainCamera)
            pos = renderer::mainCamera->CaluatePosition(pos);

        Sprite sprite = mAnimationSheet[mIndex];
        graphics::Texture::eTextureType type = mTexture->GetTextureType();

        if (type == graphics::Texture::eTextureType::Bmp) {
            BLENDFUNCTION func = {};
            func.BlendOp = AC_SRC_OVER;
            func.BlendFlags = 0;
            func.AlphaFormat = AC_SRC_ALPHA;
            func.SourceConstantAlpha = 255;

            HDC imgHdc = mTexture->GetHdc();

            AlphaBlend(hdc
                , pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.x / 2.0f)
                , sprite.size.x * scale.x
                , sprite.size.y * scale.y
                , imgHdc
                , sprite.leftTop.x
                , sprite.leftTop.y
                , sprite.size.x
                , sprite.size.y
                , func);
        }

        else if (type == graphics::Texture::eTextureType::Png) {
            Gdiplus::ImageAttributes imageAtt = {};
            imageAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

            Gdiplus::Graphics grap(hdc);

            grap.TranslateTransform(pos.x, pos.y);
            grap.RotateTransform(rot);
            grap.TranslateTransform(-pos.x, -pos.y);

            grap.DrawImage(mTexture->GetImage(),
                Gdiplus::Rect(
                      pos.x - (sprite.size.x / 2.0f)
                    , pos.y - (sprite.size.x / 2.0f)
                    , sprite.size.x * scale.x
                    , sprite.size.y * scale.y),
                sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, Gdiplus::UnitPixel, nullptr);
        }
    }

    void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet
        , Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration)
    {
        mTexture = spriteSheet;
        for (size_t i = 0; i < spriteLegth; i++)
        {
            Sprite sprite = {};
            sprite.leftTop.x = leftTop.x + (size.x * i);
            sprite.leftTop.y = leftTop.y;
            sprite.size = size;
            sprite.offset = offset;
            sprite.duration = duration;

            mAnimationSheet.push_back(sprite);
        }
    }
    void Animation::Reset()
    {
        mTime = 0.0f;
        mIndex = 0;
        mbComplete = false;
    }
}