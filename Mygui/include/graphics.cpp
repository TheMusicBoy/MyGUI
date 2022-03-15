#include "graphics.h"
#include <SFML/Window/Mouse.hpp>

namespace gx {

	// Texture

	Texture::Texture() {
		sprite.setTexture(texture);
	}

	Texture::Texture(const ImgName name) : Texture() {
		texture.loadFromImage(gx::Assets::getPtr()->getImg(name));
	}

	Texture::Texture(sf::Vector2f pos) : Texture() {
		_position = pos;
	}

	Texture::Texture(sf::Vector2f pos, const ImgName name) : Texture(name) {
		_position = pos;
	}

	Texture::~Texture() {
		texture.~Texture();
	}

	void Texture::draw(sf::RenderWindow& window) {
		if(_draw) window.draw(sprite);
	}

	void Texture::setPosition(sf::Vector2f new_position) {
		_position = new_position;
		sprite.setPosition(_position);
	}

	void Texture::setScale(sf::Vector2f new_scale) {
		_scale = new_scale;
		sprite.setScale(new_scale);
	}

	void Texture::setDraw(bool new_draw) {
		_draw = new_draw;
	}

	ObjectType Texture::getType() {
		return ObjectType::Texture;
	}

	actType Texture::check(sf::RenderWindow& window) {
		sf::Vector2i size = { sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y};
		size.x *= _scale.x;
		size.y *= _scale.y;

		sf::Vector2i mouse = sf::Mouse::getPosition();
		if (mouse.x >= _position.x && mouse.y >= _position.y)
			if (mouse.x <= _position.x + size.x && mouse.y <= _position.y + size.y)
				return 1;
		return 0;
	}

	void Texture::setTexture(const ImgName name) {
		texture.loadFromImage(gx::Assets::getPtr()->getImg(name));
	}

}