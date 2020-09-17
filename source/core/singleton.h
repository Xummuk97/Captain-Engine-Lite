#pragma once

template<class T>
class Singleton
{
public:
	Singleton(T* obj)
	{
		if (!instance)
		{
			instance = obj;
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}

	~Singleton()
	{}

	static T* getInstance()
	{
		if (!instance)
		{
			instance = new T;
		}
		return instance;
	}

private:
	static T* instance;
};

template<class T>
T* Singleton<T>::instance;