#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <utility>
#include <cassert>

namespace Textures
{
	enum ID
	{
		Airplane,
		Lanscape,
		Missile
	};
}

namespace Fonts
{
	enum ID
	{
		Menu
	};
}

namespace Sounds
{
	enum ID
	{
		BackgroundMusic
	};
}

template<typename Resource, typename Identifier>
class AssetsManager
{
public:

	void Load(Identifier id, std::string filename);
	Resource& Get(Identifier id);
	
	//template<typename Parameter>
	//void Load(Identifier id,const std::string& filename, const Parameter& secondParam);
	//Resource& Get(Identifier id);

private :

	void insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
	
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "RessourceHolder.inl"
