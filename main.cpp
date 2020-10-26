#include <core/core.h>

int main() 
{
    try
    {
        Core c;

        Core::resourceManagerInstance.Set("test", make_shared<TextureResource>("test1.png"));

        shared_ptr<ILayer> lvl = make_shared<EntitiesLayer>();
        Core::levelInstance.PushLayer("test", lvl);

        auto ent = make_shared<Entity>("test");
        AnimationManager& animationManager = ent->GetAnimationManager();
        Frames& frame1 = animationManager.Add("frame1", 1.0f);
        frame1.AddFrame({ 0, 0, 16, 16 });
        frame1.AddFrame({ 0, 0, 32, 32 });

        animationManager.SetNameCurrentFrames("frame1");

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