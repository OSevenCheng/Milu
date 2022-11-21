#pragma once

#include "Event.h"

namespace Milu
{

	class MILU_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_iWidth(width), m_iHeight(height) {}

		inline unsigned int GetWidth() const { return m_iWidth; }
		inline unsigned int GetHeight() const { return m_iHeight; }

		std::string ToString() const override
		{
			std::stringstream ss;//Used in debug mode, so we don't care the performance
			ss << "WindowResizeEvent: " << m_iWidth << ", " << m_iHeight;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_iWidth;
		unsigned int m_iHeight;
	};

	class MILU_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent(){}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MILU_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MILU_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

    class MILU_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}