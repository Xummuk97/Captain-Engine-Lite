#pragma once
#include <core/entities/components/components.h>
#include <core/entities/entity.h>

class Frames
{
	float _delay;
	size_t _currentFrame;
	vector<sf::IntRect> _frames;
	float _time;
	bool _isStart;
	bool _isFlip;
	bool _isChangeFrame;

public:
	Frames(float delay);
	virtual ~Frames() = default;

	void AddFrame(const sf::IntRect& rect);
	sf::IntRect GetRectCurrentFrame() const;

	void Start();
	void Stop();
	void Flip();

	bool IsStart() const;
	bool IsFlip() const;
	bool IsChangeFrame() const;

	void Update();
};

class AnimationComponent : public IComponent<Entity>
{
	map<string, shared_ptr<Frames>> _frames;
	string _currentFrames;

public:
	AnimationComponent() = default;
	~AnimationComponent() = default;

	void Load(Entity& object) override;
	void Update(Entity& object) override;
	void Draw(Entity& object) override;

	void AddFrame(const string& name, shared_ptr<Frames>& frames);
	void SetCurrentFrames(const string& name);
	Frames& GetCurrentFrames();

	void LoadFromFile(const string& path);
};