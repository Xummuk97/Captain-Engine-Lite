#include "entity.h"
#include <core/core.h>

CPEntity::CPEntity(Float mass, Float inertia)
    : _body(make_shared<Body>(mass, inertia))
{
    Core::spaceInstance.add(_body);
}

CPEntity::CPEntity(Float mass, Float inertia, const string& name)
    : CPEntity(mass, inertia)
{
    SetTexture(name);
}

CPEntity::~CPEntity()
{
    Core::spaceInstance.remove(_body);
}

string CPEntity::GetType() const
{
    return "CPEntity";
}

void CPEntity::Update()
{
    Vect position = _body->getPosition();
    SetPosition({ (float)position.x, (float)position.y });
}