#include <core/core.h>

int main() 
{
    try
    {
        Core c;

        auto timer = make_shared<Timer>(2.0f, [](Timer* timer) {
            cout << "TIMER 2.0f KILL" << endl;
        });
        Core::timerManagerInstance.Add(timer);

        auto txt = make_shared<TextureResource>("test1.png");
        Core::resourceManagerInstance.Set("test", txt);

        shared_ptr<ILayer> lvl = make_shared<EntitiesLayer>();
        Core::levelInstance.PushLayer("test", lvl);

        ILayer& newLayer = Core::levelInstance.GetLayer("test");
        auto ent = make_shared<Entity>("test");
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