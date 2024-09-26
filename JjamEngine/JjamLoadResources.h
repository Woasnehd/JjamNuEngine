#pragma once
#include "..\JjamEngine_SOURCE\\JjamResources.h"
#include "..\JjamEngine_SOURCE\\JjamTexture.h"

namespace Jjam
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Logo", L"..\\Resources\\Logo.png");

		Resources::Load<graphics::Texture>(L"StartBG", L"..\\Resources\\StartScene.png");
		Resources::Load<graphics::Texture>(L"PlayBG", L"..\\Resources\\PlayBackground.png");
		Resources::Load<graphics::Texture>(L"EndBG", L"..\\Resources\\EndScene.png");

		Resources::Load<graphics::Texture>(L"PlayerL", L"..\\Resources\\LucidL.png");
		Resources::Load<graphics::Texture>(L"PlayerR", L"..\\Resources\\LucidR.png");
		Resources::Load<graphics::Texture>(L"PlayerS1", L"..\\Resources\\SkillEffect1.png");
		Resources::Load<graphics::Texture>(L"PlayerD", L"..\\Resources\\DownEffect.png");

		Resources::Load<graphics::Texture>(L"FlyingMLeft", L"..\\Resources\\FlyingMonster.png");
		Resources::Load<graphics::Texture>(L"HeavyMRight", L"..\\Resources\\HeavyMonster.png");

		Resources::Load<graphics::Texture>(L"BasicAttack", L"..\\Resources\\BasicAttackObject.png");
	}
}