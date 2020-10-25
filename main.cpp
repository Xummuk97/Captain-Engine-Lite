#include <core/core.h>

int main() 
{
    try
    {
        Core c;

        auto timer = make_shared<Timer>(2.0f, [](Timer& timer) {
            cout << "TIMER 2.0F!!!" << endl;
        }, TIMER_REPEAT);
        Core::timerManagerInstance.Add("test1", timer);

        Core::resourceManagerInstance.Set("test", make_shared<TextureResource>("test1.png"));

        shared_ptr<ILayer> lvl = make_shared<EntitiesLayer>();
        Core::levelInstance.PushLayer("test", lvl);

        weak_ptr<ILayer> newLayer = Core::levelInstance.GetLayer("test");
        auto ent = make_shared<Entity>("test");
        newLayer.lock()->PushEntity(ent);

        Core::levelInstance.RemoveLayer("test");

        c.Start();
    }
    catch (const char* error)
    {
        cout << error << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}