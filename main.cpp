#include <core/core.h>

int main() 
{
    try
    {
        Core c;

        Core::resourceManagerInstance.Set("test", make_shared<TextureResource>("test1.png"));

        shared_ptr<ILayer> lvl = make_shared<EntitiesLayer>();
        Core::levelInstance.PushLayer("test", lvl);

        auto frame1 = make_shared<Frames>(0.5f);
        frame1->AddFrame({ 0, 0, 16, 16 });
        frame1->AddFrame({ 0, 0, 32, 32 });

        auto animationComponent = make_shared<AnimationComponent>();
        animationComponent->AddFrame("frame1", frame1);

        animationComponent->SetCurrentFrames("frame1");

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