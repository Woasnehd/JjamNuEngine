#pragma once
#include "..\JjamEngine_SOURCE\\JjamResources.h"
#include "..\JjamEngine_SOURCE\\JjamTexture.h"

namespace Jjam
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Logo", L"..\\Resources\\Logo.png");

		Resources::Load<graphics::Texture>(L"StartBG", L"..\\Resources\\StartScene.png");
		Resources::Load<graphics::Texture>(L"PlayBG", L"..\\Resources\\PlayScene.png");
		Resources::Load<graphics::Texture>(L"EndBG", L"..\\Resources\\EndScene.png");

		Resources::Load<graphics::Texture>(L"PlayerL", L"..\\Resources\\LucidL.png");
		Resources::Load<graphics::Texture>(L"PlayerR", L"..\\Resources\\LucidR.png");

		Resources::Load<graphics::Texture>(L"FlyingMLeft", L"..\\Resources\\FlyingMonster.png");
		Resources::Load<graphics::Texture>(L"HeavyMRight", L"..\\Resources\\HeavyMonster.png");

		Resources::Load<graphics::Texture>(L"MapleEffect", L"..\\Resources\\effect1.png");
	}
}