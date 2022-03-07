#include "assets.h"
#include "presets.h"

#include <fstream>

namespace gx {

// Assets

	Assets::Assets(bool) {
		nlohmann::json json_struct;

		std::fstream input(ASSET_DIR, std::ios::in);
		input >> json_struct;
		input.close();

		img_mas = json_struct["images"];
		fnt_mas = json_struct["fonts"];

	}

	Assets::~Assets() {
		img_mas.~data();
		fnt_mas.~data();
	}

	Assets* Assets::getPtr() {
		static Assets* instance_ptr = nullptr;

		if (instance_ptr == nullptr)
			instance_ptr = new Assets(true);

		return instance_ptr;
	}

}