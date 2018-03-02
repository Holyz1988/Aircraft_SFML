void Entity::SetVelocity(sf::Vector2f velocity)
{
	this->mVelocity = velocity;
}

void Entity::SetVelocity(float velocityX, float velocityY)
{
	this->mVelocity.x = velocityX;
	this->mVelocity.y = velocityY;
}

sf::Vector2f Entity::GetVelocity()
{
	return this->mVelocity;
}