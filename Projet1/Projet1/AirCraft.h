#pragma once

#include "Entity.hpp"

class AirCraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor
	};
	
public:
	explicit AirCraft(Type type);

private:
	Type mType;
};

