#include "window.h"

int main() {
	gx::Window window(10, 10);

	while (window.startFrame()) {

		window.endFrame();
	}
}