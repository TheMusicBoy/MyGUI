#ifndef _MY_ASSETS_
#define _MY_ASSETS_

#include <string>
#include <vector>

#include <nlohmann/json.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Font.hpp>

#include "enum.h"

namespace gx {
	
	template<typename ObjClass>
	class data {
	public:
		data() {};
		data(const nlohmann::json& json_str) {
			resource.resize(json_str["count"]);

			size_t pos = 0;

			for (auto iter : json_str)
				resource[pos].loadFromFile(iter);
		}

		~data() {
			resource.clear();
		}

		inline const ObjClass& operator[](size_t index) {
			return resource[index];
		}

	protected:
		std::vector<ObjClass> resource;

	};

	class Assets {
	private:
		Assets(bool);
	public:
		Assets() = delete;
		Assets& operator=(Assets&) = delete;

		~Assets();

		static Assets* getPtr();

		const inline sf::Image& getImg(const ImgName name) {
			return img_mas[name];
		}

		const inline sf::Font& getFnt(const FntName name) {
			return fnt_mas[name];
		}
		
	private:

		data<sf::Image> img_mas;
		data<sf::Font> fnt_mas;

	};

}

#endif