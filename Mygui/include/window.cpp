#include "window.h"
#include <ctime>

namespace gx {

	// Events

#pragma region Events

	Events::Events() {
		for (size_t iter = 0; iter < sf::Event::EventType::Count; iter++)
			event_list[iter] = 0;
	}

	Events::~Events() {}

	void Events::clear() {
		for (size_t iter = 0; iter < sf::Event::EventType::Count; iter++)
			event_list[iter] = 0;
	}

	bool Events::isHappened(sf::Event::EventType _type) {
		return event_list[_type] != 0;
	}

	size_t Events::count(sf::Event::EventType _type) {
		return event_list[_type];
	}

	bool Events::update(sf::RenderWindow& window) {
		this->clear();
		sf::Event event;

		while (window.pollEvent(event)) {
			event_list[event.type]++;

			if (event.type == sf::Event::Closed)
				return false;
		}
		return true;
	}

#pragma endregion Events

	// Window

#pragma region Window

#pragma region Constructors/Desturctors

	Window::Window() {}

	Window::Window(size_t width, size_t height) {
		window.create(sf::VideoMode(width, height), "");
	}

	Window::Window(size_t width, size_t height, const char* name) {
		window.create(sf::VideoMode(width, height), name);
	}

	Window::~Window() {
		window.close();
	}

#pragma endregion Constructors/Destructors

#pragma region Open/Close

	void Window::open(size_t widht, size_t height) {
		if (window.isOpen()) window.close();
		window.create(sf::VideoMode(widht, height), "");
	}

	void Window::open(size_t width, size_t height, const char* name) {
		if (window.isOpen()) window.close();
		window.create(sf::VideoMode(width, height), name);
	}

	void Window::close() {
		if(window.isOpen()) window.close();
	}

#pragma endregion Open/Close

	bool Window::startFrame() {
		if (!events.update(window))
			return false;

		delay = std::clock() - end;
		end = std::clock();

		window.clear();
		return true;
	}

	void Window::endFrame() {
		window.display();
	}

	Events_ptr Window::getEvents() {
		return &events;
	}
	
#pragma endregion Window



}