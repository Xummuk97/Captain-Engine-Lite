#include "entity.h"
#include <core/core.h>

Entity::Entity(const string& type)
    : ComponentsManager(*this)
    , _type(type)
{
}

Entity::Entity(const string& type, const string& textureName)
    : Entity(type)
{
    SetTexture(textureName);
}

Entity::Entity(const string& type, const string& tag, const string& textureName)
    : Entity(type, textureName)
{
    _tag = tag;
}

string Entity::GetType() const
{
    return _type;
}

string Entity::GetTag() const
{
    return _tag;
}

sf::Sprite& Entity::GetSprite()
{
    return _sprite;
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
