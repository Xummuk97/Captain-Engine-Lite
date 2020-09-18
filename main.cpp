#include <core/core.h>

using namespace captain_lite;

int main() 
{
    Resources resources;
    resources.add("background1", new ResourceTexture("background1.jpg"));
    resources.add("test", new ResourceTexture("test1.png"));
    
    World world;
    world.loadMap("test.tmx");

    LayerObjects* lo = new LayerObjects("test");
    Entity* e = new Entity("test", 0, 0, 32, 32);
    lo->pushEntity(e);
    world.pushLayer(lo);

    Camera camera(0, 0, 800.0f, 600.0f);
    camera.bindEntity(e);

    Background background("background1", 0, 0, 800, 600);

	Window window("Captain Engine Lite 1.0", 800, 600);
    window.setFPSLimit(60);
    window.setVerticalSyncEnabled(false);

    window.bindEvent(WINDOW_EVENT_GUI, [](Window* window)
    {
        ImGui::Text("fps: %f", 1 / window->getDeltaTime());
    });

	window.exec();
	return EXIT_SUCCESS;
}