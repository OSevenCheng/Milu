#pragma once

#include "Event.h"

#include <sstream>

namespace Milu
{
	class MILU_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float _x, float _y)
			:m_fMouseX(_x), m_fMouseY(_y) {}

		inline float GetX() const { return m_fMouseX; }
		inline float GetY() const { return m_fMouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;//Used in debug mode, so we don't care the performance
			ss << "MouseMoveEvent: " << m_fMouseX << ", " << m_fMouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_fMouseX;
		float m_fMouseY;
	};

	class MILU_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float _x, float _y)
			:m_fXOffset(_x), m_fYOffset(_y) {}

		inline float GetX() const { return m_fXOffset; }
		inline float GetY() const { return m_fYOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;//Used in debug mode, so we don't care the performance
			ss << "MouseScrolledEvent: " << m_fXOffset << ", " << m_fYOffset;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_fXOffset;
		float m_fYOffset;
	};

	class MILU_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_iButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int _button)
			:m_iButton(_button) {}
		int m_iButton;
	};

	class MILU_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int _button)
			: MouseButtonEvent(_button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_iButton;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	class MILU_API MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int _button)
			: MouseButtonEvent(_button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleaseEvent: " << m_iButton;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	private:
		int m_iRepeatCount;
	};
}