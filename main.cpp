#include <core/core.h>

int main() 
{
    try
    {
        Core c;

        Core::resourceManagerInstance.Set("test", make_shared<TextureResource>("test1.png"));

        shared_ptr<ILayer> lvl = make_shared<EntitiesLayer>();
        Core::levelInstance.PushLayer("test", lvl);

        auto animationComponent = make_shared<AnimationComponent>();
        animationComponent->LoadFromFile("player.xml");

        auto ent = make_shared<Entity>("test", "test");
        ent->AddComponent("drawable", make_shared<DrawableComponent>());
        ent->AddComponent("animation", animationComponent);

        ILayer& newLayer = Core::levelInstance.GetLayer("test");
        newLayer.PushEntity(ent);

        c.Start();
    }
    catch (const char* error)
    {
        cout << error << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}