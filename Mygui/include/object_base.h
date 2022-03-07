#ifndef _MY_OBJ_
#define _MY_OBJ_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace gx {

	enum ObjectType;

	class Object_base {
	public:
		Object_base() = delete;
		
		virtual void draw(sf::RenderWindow&) = NULL;
		virtual void setPosition(sf::Vector2i) = NULL;
		virtual void setScale(sf::Vector2f) = NULL;
		virtual void setRotation(float) = NULL;
		virtual void setDraw(bool) = NULL;
		virtual ObjectType getType() = NULL;
		
		inline sf::Vector2i getPosition() {
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
		sf::Vector2i _position;
		sf::Vector2f _scale;
		float _rotation;
		bool _draw;
	};

	class Object {
	public:
		Object();
		Object(const Object_base*);
		~Object();
		
		__forceinline void draw(sf::RenderWindow& window) {
			base_ptr->draw(window);
		}
		__forceinline void setPosition(sf::Vector2i new_position) {
			base_ptr->setPosition(new_position);
		}
		__forceinline void setScale(sf::Vector2f new_scale) {
			base_ptr->setScale(new_scale);
		}
		__forceinline void setRotation(float new_rotation) {
			base_ptr->setRotation(new_rotation);
		}
		__forceinline void setDraw(bool _Val) {
			base_ptr->setDraw(_Val);
		}

		__forceinline ObjectType getType() {
			return base_ptr->getType();
		}
		__forceinline sf::Vector2i getPosition() {
			return base_ptr->getPosition();
		}
		__forceinline sf::Vector2f getScale() {
			return base_ptr->getScale();
		}
		__forceinline float getRotation() {
			return base_ptr->getRotation();
		}
		__forceinline bool isDraw() {
			return base_ptr->isDraw();
		}

		__forceinline Object_base* getObject() {
			return base_ptr;
		}

	protected:
		Object_base* base_ptr;

	};

}

#endif