#include <core/core.h>

using namespace captain_lite;

int main() 
{
    Resources resources;
    resources.add("background1", new ResourceTexture("background1.jpg"));
    resources.add("test", new ResourceTexture("test1.png"));
    
    Camera camera(0, 0, 800.0f, 600.0f);

    World world;

    world.bindEvent(WORLD_EVENT_LOAD_ENTITY, [](World* world)
    {
        XMLElement* object_element = world->getLastLoadObject();
        string object_name = object_element->Attribute("name");

        if (object_name == "player")
        {
            float x = object_element->FloatAttribute("x");
            float y = object_element->FloatAttribute("y");

            Entity* entity = new Entity("background1", 0, 0, 32, 32);
            entity->setPosition(x, y);
            entity->addComponent(new ComponentDraw);
            Camera::getInstance()->bindEntity(entity);
            world->getEntityLayer(world->getLastLayerName())->pushEntity(entity);
        }
        else if (object_name == "collision")
        {
            float x = object_element->FloatAttribute("x");
            float y = object_element->FloatAttribute("y");
            float width = object_element->FloatAttribute("width");
            float height = object_element->FloatAttribute("height");

            EntityInfo* entity_info = new EntityInfo({ x, y, width, height });
            world->pushEntityInfo(object_name, entity_info);
        }
    });

    world.loadMap("test.tmx");

    Background background("background1", 0, 0, 800, 600);

	Window window("Captain Engine Lite 1.0", 800, 600);
    window.setFPSLimit(60);
    window.setVerticalSyncEnabled(false);

    window.bindEvent(WINDOW_EVENT_GUI, [](Window* window)
    {
        ImGui::Begin("DEBUG");
        ImGui::Text("fps: %f", 1 / window->getDeltaTime());
        ImGui::End();
    });

	window.exec();
	return EXIT_SUCCESS;
}