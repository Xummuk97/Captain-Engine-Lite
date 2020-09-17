#include <core/core.h>

using namespace captain_lite;

int main() 
{
    Resources resources;
    resources.add("background1", new ResourceTexture("background1.jpg"));
    resources.add("test", new ResourceTexture("test1.png"));
    
    World world;
    world.loadMap("test.tmx");

    Camera camera(0, 0, 800.0f, 600.0f);

    Background background("background1", 0, 0, 800, 600);

	Window window("Captain Engine Lite 1.0", 800, 600);
    window.setFPSLimit(60);
    window.setVerticalSyncEnabled(false);
	window.exec();
	return EXIT_SUCCESS;
}