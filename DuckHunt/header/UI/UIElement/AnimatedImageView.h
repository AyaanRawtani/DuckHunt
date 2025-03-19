#pragma once
#include "UI/UIElement/ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement {
		enum class AnimationType {
			FADE_IN,
			FADE_OUT
		};

		class AnimatedImageView : public ImageView {
		private:
			using CallbackFunction = std::function<void()>;
			CallbackFunction callbackFunction = nullptr;

			void updateElapsedDuration();
			void handleAnimationProgress();
			void updateAnimation();

		protected:
			float defaultAnimationDuration = 2.f;
			AnimationType animationType;

			float animationDuration;
			float elapsedDuration;

			sf::Clock clock;

			void setAnimationType(AnimationType animationType);
			void setAnimationDuration(float duration);

			void fadeIn();
			void fadeOut();

			virtual void reset();

		public:
			AnimatedImageView();
			~AnimatedImageView();

			void initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f postion) override;
			void update() override;
			void render() override;

			void playAnimation(AnimationType animationType, float duration, CallbackFunction animationEndCallback);
			void registerCallbackFunction(CallbackFunction animation_end_callback);




		};
	}
}