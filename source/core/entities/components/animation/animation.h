#pragma once
#include <core/entities/components/components.h>
#include <core/entities/entity.h>

#define FRAMES_RUN (1 << 0)
#define FRAMES_FLIP (1 << 1)
#define FRAMES_CHAGE_FRAME (1 << 2)
#define FRAMES_BEGIN (1 << 3)

class Frames
{
	float _delay;
	size_t _currentFrame;
	vector<sf::IntRect> _frames;
	float _time;
	int _flags;

public:
	Frames(float delay);
	virtual ~Frames() = default;

	void AddFrame(const sf::IntRect& rect);
	sf::IntRect GetRectCurrentFrame() const;

	void Run();
	void Stop();
	void Flip();

	bool IsRun() const;
	bool IsFlip() const;
	bool IsChangeFrame() const;
	bool IsBegin() const;

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

	void LoadFromFile(const string& path);

	void AddFrames(const string& name, shared_ptr<Frames>& frames);
	Frames& GetCurrentFrames();

	void Run(const string& name);
};