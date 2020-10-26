#include "entity.h"
#include <core/core.h>

Entity::Entity()
    : _animationManager(_sprite)
{
}

Entity::Entity(const string& name)
    : Entity()
{
    SetTexture(name);
}

string Entity::GetType() const
{
    return "Entity";
}

string Entity::GetTag() const
{
    return _tag;
}

AnimationManager& Entity::GetAnimationManager()
{
    return _animationManager;
}

void Entity::SetTexture(const string& name)
{
    _sprite.setTexture(Core::resourceManagerInstance.Get<sf::Texture>(name).Get());
}

void Entity::SetTextureRect(const sf::IntRect& rect)
{
    _sprite.setTextureRect(rect);
}

void Entity::Move(const sf::Vector2f& offset)
{
    _sprite.move(offset);
}

void Entity::SetPosition(const sf::Vector2f& position)
{
    _sprite.setPosition(position);
}

sf::FloatRect Entity::GetRectangle() const
{
    return _sprite.getGlobalBounds();
}

sf::Vector2f Entity::GetPosition() const
{
    return _sprite.getPosition();
}

bool Entity::IsContains(const sf::Vector2f& point)
{
    return _sprite.getGlobalBounds().contains(point);
}

bool Entity::IsIntersects(const sf::FloatRect& rect)
{
    return _sprite.getGlobalBounds().intersects(rect);
}

void Entity::SetTag(const string& tag)
{
    _tag = tag;
}

void Entity::Update()
{
}

void Entity::Draw()
{
    Core::windowInstance->draw(_sprite);
}

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
