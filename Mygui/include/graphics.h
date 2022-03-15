#ifndef _MY_GX_
#define _MY_GX_

#include "object_base.h"

#include "assets.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace gx {

	class Texture : public Object_base {
	public:
		Texture();
		Texture(const ImgName name);
		Texture(sf::Vector2f pos);
		Texture(sf::Vector2f pos, const ImgName name);
		~Texture();

		void draw(sf::RenderWindow&) override;
		void setPosition(sf::Vector2f) override;
		void setScale(sf::Vector2f) override;
		void setRotation(float) override;
		void setDraw(bool) override;
		ObjectType getType() override;
		actType check(sf::RenderWindow&) override;

		void setTexture(const ImgName name);

	private:
		sf::Texture texture;
		sf::Sprite sprite;
	};

	class Text : public Object_base {
	public:
		Text();
		Text(const FntName name);
		Text(sf::Vector2f pos);
		Text(sf::Vector2f pos, FntName name);
		~Text();

		void draw(sf::RenderWindow&) override;
		void setPosition(sf::Vector2f) override;
		void setScale(sf::Vector2f) override;
		void setDraw(bool) override;
		ObjectType getType() override;
		actType check(sf::RenderWindow&) override;

		void setFont(FntName name);
		const FntName getFont();

	};

	class Claster : public Object_base {
	public:
		Claster();
		Claster(std::vector<Object_base*> list);
		Claster(sf::Vector2f pos);
		Claster(sf::Vector2f pos, std::vector<Object_base*> list);
		~Claster();

		void draw(sf::RenderWindow&) override;
		void setPosition(sf::Vector2f) override;
		void setScale(sf::Vector2f) override;
		void setDraw(bool) override;
		ObjectType getType() override;
		actType check(sf::RenderWindow&) override;

		std::list<Object_base*>& getList();

	protected:
		std::list<Object_base*> object_list;

	};

}

#endif