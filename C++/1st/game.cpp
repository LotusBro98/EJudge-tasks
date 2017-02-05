#include <iostream>

using namespace std;

class Game_Hero
{
public:
	int health;
	bool alive;
	bool Zombi;

	Game_Hero(int health = 10, bool zombie = false)
	{
		if (health > 0)
		{
			this->health = health;
			this->alive = true;
		}
		else
		{
			this->health = 0;
			this->alive = false;
		}
		this->Zombi = zombie;
	}

	bool isDead() 
	{
		return !this->alive;
	}

	int livePoints()
	{
		return this->health;
	}

	void damage(int damage = 5)
	{
		health -=  damage;
		if (health <= 0)
		{
			health = 0;
			alive = false;
		}
	}

	void heal(int health = 3)
	{
		this->health += health;
	}
};

/*
int main()
{
	Game_Hero hero = Game_Hero(true);

	cout << hero.isDead() << ' ' << hero.livePoints() << endl;
	return 0;
}
*/
