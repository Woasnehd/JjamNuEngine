#pragma once
#include "JjamComponent.h"
#include "JjamAnimation.h"

namespace Jjam
{
	class Animator : public Component
	{
	public:
		struct Event {
			void operator=(function<void()> func) {
				mEvent = move(func);
			}

			void operator()() {
				if (mEvent) {
					mEvent();
				}
			}

			function<void()> mEvent;
		};

		struct Events {
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		Animator();
		~Animator();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void CreateAnimation(const wstring& name
			, graphics::Texture* spriteSheet
			, math::Vector2 leftTop
			, math::Vector2 size
			, math::Vector2 offset
			, UINT spriteLegth
			, float duration);

		Animation* FindAnimation(const wstring& name);
		bool IsPlaying(const wstring& name);
		void PlayAnimation(const wstring& name, bool loop = true);

		Events* FindEvents(const std::wstring& name);
		function<void()>& GetStartEvent(const std::wstring& name);
		function<void()>& GetCompleteEvent(const std::wstring& name);
		function<void()>& GetEndEvent(const std::wstring& name);

	private:
		map<wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

		map<wstring, Events*> mEvents;
	};
}
