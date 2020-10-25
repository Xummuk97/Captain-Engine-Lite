#include <core/core.h>

int main() 
{
    try
    {
        Core c;

        auto timer = make_shared<Timer>(2.0f, [](Timer* timer) {
            if (timer->GetCount() < 3)
            {
                cout << "COUNT: " << timer->GetCount() << endl;
            }
            else
            {
                cout << "KILL" << endl;
                timer->Remove();
            }
        }, TIMER_REPEAT);
        Core::timerManagerInstance.Add(move(timer));

        auto txt = make_shared<TextureResource>("test1.png");
        Core::resourceManagerInstance.Set("test", txt);

        auto ent = make_shared<Entity>("test");

        auto lvl = make_shared<EntitiesLayer>();
        Core::levelInstance.PushLayer("test", move(lvl));

        Core::levelInstance.PushEntity("test", move(ent));

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