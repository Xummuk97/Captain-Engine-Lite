#pragma once
#include <core/includes.h>

class Entity
{
	sf::Sprite _sprite;
	string _tag;

public:
	Entity() = default;
	Entity(const string& name);
	virtual ~Entity() = default;

	void SetTexture(const string& name);
	void SetTextureRect(const sf::IntRect& rect);
	void Move(const sf::Vector2f& offset);
	void SetPosition(const sf::Vector2f& position);

	sf::FloatRect GetRectangle() const;
	sf::Vector2f GetPosition() const;
	bool IsContains(const sf::Vector2f& point);
	bool IsIntersects(const sf::FloatRect& rect);

	void SetTag(const string& tag);

	virtual string GetType() const;
	string GetTag() const;

	virtual void Update();
	virtual void Draw();
};

class CPEntity : public Entity 
{
protected:
	shared_ptr<Body> _body;

public:
	CPEntity(Float mass, Float inertia);
	CPEntity(Float mass, Float inertia, const string& name);
	~CPEntity();

	shared_ptr<Body> GetBody() { return _body; }

	virtual string GetType() const;

	virtual void Update();
};