#include <core/core.h>

int main() 
{
    try
    {
        Core c;
        auto txt = make_shared<TextureResource>("test1.png");
        Core::resourceManagerInstance.Set("test", txt);

        auto ent = make_shared<Entity>("test");

        auto lvl = make_shared<EntitiesLayer>();
        lvl->PushEntity(ent);

        Core::levelInstance.PushLayer("test", lvl);

        c.Start();
    }
    catch (const char* error)
    {
        cout << error << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}