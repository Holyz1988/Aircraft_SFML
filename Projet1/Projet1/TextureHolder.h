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
		Landscape,
		Airplane,
		Missile,
	};
}

class TextureHolder
{
public:
	void					Load(Textures::ID id, std::string& filename);
	sf::Texture&			Get(Textures::ID id);
	//const sf::Texture&		Get(Textures::ID id) const;// TODO : Comprendre cette ligne

private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};

