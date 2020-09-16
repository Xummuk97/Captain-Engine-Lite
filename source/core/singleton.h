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

	static T* getInstance()
	{
		if (!instance)
		{
			exit(EXIT_FAILURE);
		}
		return instance;
	}

private:
	static T* instance;
};

template<class T>
T* Singleton<T>::instance;