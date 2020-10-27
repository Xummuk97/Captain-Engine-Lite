#pragma once
#include <core/includes.h>
#include <core/entities/components/components.h>

class Entity : public ComponentsManager<Entity>
{
	string _type;
	string _tag;
	sf::Sprite _sprite;

public:
	Entity(const string& type);
	Entity(const string& type, const string& textureName);
	Entity(const string& type, const string& tag, const string& textureName);
	virtual ~Entity() = default;

	void SetTexture(const string& name);
	void SetTextureRect(const sf::IntRect& rect);
	void Move(const sf::Vector2f& offset);
	void SetPosition(const sf::Vector2f& position);

	sf::FloatRect GetRectangle() const;
	sf::Vector2f GetPosition() const;
	bool IsContains(const sf::Vector2f& point);
	bool IsIntersects(const sf::FloatRect& rect);

	string GetType() const;
	string GetTag() const;

	sf::Sprite& GetSprite();
};