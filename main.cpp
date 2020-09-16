#include <core/resource.h>
#include <core/world.h>
#include <core/window.h>
#include <core/camera.h>
#include <components/component_draw.h>

using namespace captain_lite;

int main() 
{
    Resources resources;
    resources.add("background1", new ResourceTexture("background1.jpg"));
    resources.add("test", new ResourceTexture("test1.png"));
    
    World world;

    LayerNormal* layer = new LayerNormal("one");

    Entity* entity = new Entity("test", 0, 0, 32, 32);
    entity->addComponent(new ComponentBackLight);
    layer->pushEntity(entity);

    world.pushLayer(layer);

    Camera camera(0, 0, 800.0f, 600.0f);
    camera.setBackground("background1", 0, 0, 800, 600);
    camera.bind(entity);

	Window window("Captain Engine Lite 1.0", 800, 600);
    sf::RenderWindow* renderWindow = window.getRenderWindow();
    renderWindow->setFramerateLimit(60);
    renderWindow->setVerticalSyncEnabled(false);
	window.exec();
	return EXIT_SUCCESS;
}