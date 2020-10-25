#include <core/core.h>
#include <core/system.h>

int main() 
{
    try
    {
        Core c("Captain Engine Lite 1.0", 800, 600);
        auto txt = make_shared<TextureResource>("test1.png");
        System::resourceManager.Set("test", txt);

        auto ent = make_shared<Entity>("test");

        auto lvl = make_shared<EntitiesLayer>();
        lvl->PushEntity(ent);

        System::level.PushLayer("test", lvl);

        c.Start();
    }
    catch (const char* error)
    {
        cout << error << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}