#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <utility>
#include <cassert>

namespace Police
{
	enum ID
	{
		Menu
	};
}

class FontsHolder
{
public:

	void					Load(Police::ID id, const std::string& filename);
	sf::Font&				Get(Police::ID id);
	//const sf::Font&			Get(Police::ID id) const;

private:
	std::map<Police::ID, std::unique_ptr<sf::Font>> mFontMap;

};

