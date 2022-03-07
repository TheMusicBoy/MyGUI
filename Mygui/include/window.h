#ifndef _MY_WINDOW_
#define _MY_WINDOW_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Vector2.hpp>
#include <list>

namespace gx {

	class Window;

	using time_type = unsigned int;

	class Events {
	public:
		Events();
		~Events();
		
		bool isHappened(sf::Event::EventType _event_type);
		size_t count(sf::Event::EventType _event_type);

		
	private:
		friend Window;

		void clear();
		bool update(sf::RenderWindow& window);
		size_t event_list[sf::Event::EventType::Count];
	};

	using Events_ptr = const Events*;


	class Window {
	public:

#pragma region Constructors/Desturctonrs

		Window();

		Window(size_t, size_t);

#ifdef _STRING_
		Window(size_t width, size_t height, const std::string& name) {
			window.create(sf::VideoMode(width, height), name);
		}
#endif

		Window(size_t, size_t, const char*);


		~Window();

#pragma endregion Constructor/Destructors

#pragma region Open

		void open(size_t, size_t);

#ifdef _STRING_
		void open(size_t width, size_t height, const std::string& name) {
			if (window.isOpen()) window.close();
			window.create(sf::VideoMode(width, height), name);
		}
#endif

		void open(size_t, size_t, const char*);

		void close();

#pragma endregion Open

		inline bool isOpen() {
			return window.isOpen();
		}

		template<typename _Object>
		void draw(_Object& object) {
			object.draw(window);
		}

		bool startFrame();
		void endFrame();

		inline sf::Vector2u getSize() {
			return window.getSize();
		}
		inline sf::Vector2i getPosition() {
			return window.getPosition();
		}

		inline bool check(sf::Event::EventType _type) {
			return events.isHappened(_type);
		}
		inline size_t count(sf::Event::EventType _type) {
			return events.count(_type);
		}

		inline const sf::Vector2i& mouse() {
			return sf::Mouse::getPosition();
		}

		inline time_type clock() {
			return delay;
		}

		Events_ptr getEvents();

	private:
		sf::RenderWindow window;
		Events events;
		time_type delay, end;
	};

}

#endif