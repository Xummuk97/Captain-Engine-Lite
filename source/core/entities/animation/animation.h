#pragma once
#include <core/includes.h>

#define FRAMES_STOP (1 << 0)
#define FRAMES_FLIP (1 << 1)

class Frames
{
	vector<sf::IntRect> _data;
	sf::Sprite& _sprite;
	float _delay;
	int _flags;
	string _name;
	size_t _frameCount;

	void ChangeFrame();

public:
	Frames(const string& name, sf::Sprite& sprite, float delay);
	virtual ~Frames() = default;

	void AddFrame(const sf::IntRect& rect);
	int GetFlags() const;

	void Start();
	void Stop();
	void Flip();
};

class AnimationManager
{
	map<string, shared_ptr<Frames>> _frames;
	string _nameCurrentFrames;
	sf::Sprite& _sprite;

public:
	AnimationManager(sf::Sprite& sprite);
	virtual ~AnimationManager() = default;

	Frames& Add(const string& name, float delay);
	bool Has(const string& name);

	void SetNameCurrentFrames(const string& name);
	string GetNameCurrentFrames() const;
	Frames& GetCurrentFrames();
	void FlipCurrentFrames();
};