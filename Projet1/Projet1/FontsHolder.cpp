#include "FontsHolder.h"

void FontsHolder::Load(Police::ID id, const std::string & filename)
{
	std::unique_ptr<sf::Font> font(new sf::Font());
	if(!font->loadFromFile(filename))
	{
		throw std::runtime_error("FontsHolder::Load - Failed to load " + filename);
	}

	mFontMap.insert(std::make_pair(id, std::move(font)));
}

sf::Font & FontsHolder::Get(Police::ID id)
{
	auto it = mFontMap.find(id);
	assert(it != mFontMap.end());

	return *it->second;
}

/*const sf::Font & FontsHolder::Get(Police::ID id) const
{
	auto it = mFontMap.find(id);
	return *it->second;
}
*/