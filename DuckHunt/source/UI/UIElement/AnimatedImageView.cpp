#include "UI/UIElement/AnimatedImageView.h"

namespace UI {
	namespace UIElement {
		void AnimatedImageView::updateElapsedDuration()
		{
			float deltaTime = clock.restart().asSeconds();
			elapsedDuration += deltaTime;
		}
		void AnimatedImageView::handleAnimationProgress()
		{
			if (elapsedDuration >= animationDuration && callbackFunction) {
				callbackFunction();
			}
		}
		void AnimatedImageView::updateAnimation()
		{
			switch (animationType)
			{
			case UI::UIElement::AnimationType::FADE_IN:
				fadeIn();
				break;
			case UI::UIElement::AnimationType::FADE_OUT:
				fadeOut();
				break;
			default:
				break;
			}
		}
		void AnimatedImageView::setAnimationType(AnimationType animationType)
		{
			this->animationType = animationType;
		}
		void AnimatedImageView::setAnimationDuration(float duration)
		{
			animationDuration = duration;
		}
		void AnimatedImageView::fadeIn()
		{
			float alpha = std::min(1.0f, elapsedDuration / animationDuration);
			image_sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
		}
		void AnimatedImageView::fadeOut()
		{
			float alpha = std::max(0.f, 1.f - (elapsedDuration / animationDuration));
			image_sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
		}
		void AnimatedImageView::reset()
		{
			animationDuration = defaultAnimationDuration;
			animationType = AnimationType::FADE_IN;
			clock.restart();
			elapsedDuration = 0.0f;

		}
		AnimatedImageView::AnimatedImageView()
		{
		}
		AnimatedImageView::~AnimatedImageView()
		{
		}
		void AnimatedImageView::initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f postion)

		{
			ImageView::initialize(texturePath, imageWidth, imageHeight, postion);
		}
		void AnimatedImageView::update()
		{
			ImageView::update();
			if (ui_state == UIState::VISIBLE)
			{
				updateElapsedDuration();
				handleAnimationProgress();
				updateAnimation();
			}
		}
		void AnimatedImageView::render()
		{
			ImageView::render();
		}
		void AnimatedImageView::playAnimation(AnimationType animationType, float duration, CallbackFunction animationEndCallback)
		{
			ImageView::show();
			reset();
			setAnimationType(animationType);
			setAnimationDuration(duration);
			registerCallbackFunction(animationEndCallback);
		}
		void AnimatedImageView::registerCallbackFunction(CallbackFunction animationEndCallback)
		{
			callbackFunction = animationEndCallback;
		}
	}
}