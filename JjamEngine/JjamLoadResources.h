#pragma once
#include "..\JjamEngine_SOURCE\\JjamResources.h"
#include "..\JjamEngine_SOURCE\\JjamTexture.h"

namespace Jjam
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"StartBG", L"D:\\Visual_Studio_2022\\JjamNu_Engine\\Resources\\Cernium_Start.png");
		Resources::Load<graphics::Texture>(L"PlayBG", L"D:\\Visual_Studio_2022\\JjamNu_Engine\\Resources\\Cernium_Play.png");
		Resources::Load<graphics::Texture>(L"EndBG", L"D:\\Visual_Studio_2022\\JjamNu_Engine\\Resources\\Cernium_End.png");

		Resources::Load<graphics::Texture>(L"Player", L"D:\\Visual_Studio_2022\\JjamNu_Engine\\Resources\\Player.png");
		Resources::Load<graphics::Texture>(L"Monster1", L"D:\\Visual_Studio_2022\\JjamNu_Engine\\Resources\\Monster1.png");
	}
}