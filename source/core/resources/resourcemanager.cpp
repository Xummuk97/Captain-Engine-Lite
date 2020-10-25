#include "resource.h"

void ResourceManager::Set(const string& name, const shared_ptr<IResource>& resource)
{
	_data[name] = resource;
}

bool ResourceManager::Has(const string& name)
{
	return _data.find(name) != _data.end();
}
