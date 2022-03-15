#ifndef _MY_OBJ_
#define _MY_OBJ_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace gx {

	enum ObjectType {
		None,
		Texture,
		Text,
		Claster
	};

	using actType = unsigned int;

	class Object_base {
	public:
		Object_base() : _position(0, 0), _scale(1, 1), _rotation(0), _draw(1) {
		}
		
		virtual void draw(sf::RenderWindow&) = NULL;
		virtual void setPosition(sf::Vector2f) = NULL;
		virtual void setScale(sf::Vector2f) = NULL;
		virtual void setRotation(float) = NULL;
		virtual void setDraw(bool) = NULL;
		virtual ObjectType getType() = NULL;
		virtual actType check(sf::RenderWindow&) = NULL;
		
		inline sf::Vector2f getPosition() {
			return _position;
		}
		inline sf::Vector2f getScale() {
			return _scale;
		}
		inline float getRotation() {
			return _rotation;
		}
		inline bool isDraw() {
			return _draw;
		}


	protected:
		sf::Vector2f _position;
		sf::Vector2f _scale;
		float _rotation;
		bool _draw;
	};

	class Object {
	public:
		Object();
		Object(const Object_base*);
		~Object();
		
		inline void draw(sf::RenderWindow& window) {
			base_ptr->draw(window);
		}
		inline void setPosition(sf::Vector2f new_position) {
			base_ptr->setPosition(new_position);
		}
		inline void setScale(sf::Vector2f new_scale) {
			base_ptr->setScale(new_scale);
		}
		inline void setRotation(float new_rotation) {
			base_ptr->setRotation(new_rotation);
		}
		inline void setDraw(bool _Val) {
			base_ptr->setDraw(_Val);
		}

		inline ObjectType getType() {
			return base_ptr->getType();
		}
		inline sf::Vector2f getPosition() {
			return base_ptr->getPosition();
		}
		inline sf::Vector2f getScale() {
			return base_ptr->getScale();
		}
		inline float getRotation() {
			return base_ptr->getRotation();
		}
		inline bool isDraw() {
			return base_ptr->isDraw();
		}

		inline Object_base* getObject() {
			return base_ptr;
		}

	protected:
		Object_base* base_ptr;

	};

}

#endif