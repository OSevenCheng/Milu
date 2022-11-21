#pragma once

#include "Event.h"

namespace Milu
{
	class MILU_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_iKeycode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard|EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			:m_iKeycode(keycode) {}

		int m_iKeycode;
	};

	class MILU_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_iRepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_iRepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_iKeycode << " (" << m_iRepeatCount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_iRepeatCount;
	};
	class MILU_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << m_iKeycode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}