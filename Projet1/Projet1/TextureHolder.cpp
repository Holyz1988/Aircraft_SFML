#include "TextureHolder.h"

void TextureHolder::Load(Textures::ID id, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename))
	{
		throw std::runtime_error("TextureHolder::Load - Failed to load " + filename);
	}
	texture->setSmooth(true);

	mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::Get(Textures::ID id)
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());

	return *found->second;
}

/*const sf::Texture& TextureHolder::Get(Textures::ID id) const
{
	auto found = mTextureMap.find(id);
	return *found->second;
}

/*

*/
