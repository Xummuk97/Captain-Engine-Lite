#include <core/core.h>

using namespace captain_lite;

int main() 
{
    cout << Utils::format("Hello, {1}!", "Andrey") << endl;

    Resources resources;
    resources.add("background1", new ResourceTexture("background1.jpg"));
    resources.add("test", new ResourceTexture("test1.png"));
    
    Camera camera(0, 0, 800.0f, 600.0f);

    World world;

    world.bindEvent(WORLD_EVENT_LOAD_ENTITY, [](World* world, Properties* properties)
    {
        XMLElement* object_element = properties->getPropertyXMLElement("element");
        string object_name = object_element->Attribute("name");

        if (object_name == "player")
        {
            sf::Vector2f position = Utils::getXmlAttributeVector2f(object_element);

            Entity* entity = new Entity("background1", 0, 0, 32, 32);
            entity->setPosition(position.x, position.y);
            entity->addComponent(new ComponentDraw);
            Camera::getInstance()->bindEntity(entity);
            world->getEntityLayer(properties->getPropertyString("layer"))->pushEntity(entity);
        }
        else
        {
            sf::FloatRect rect = Utils::getXmlAttributeFloatRect(object_element);

            EntityInfo* entity_info = new EntityInfo({ rect.left, rect.top, rect.width, rect.height });
            world->pushEntityInfo(object_name, entity_info);
        }
    });

    world.loadMap("test.tmx");

    Background background("background1", 0, 0, 800, 600);

	Window window("Captain Engine Lite 1.0", 800, 600);
    window.setFPSLimit(60);
    window.setVerticalSyncEnabled(false);

    window.bindEvent(WINDOW_EVENT_GUI, [](Window* window, Properties* properties)
    {
        ImGui::Begin("DEBUG");
        ImGui::Text("fps: %f", 1 / window->getDeltaTime());
        ImGui::End();
    });

	window.exec();
	return EXIT_SUCCESS;
}