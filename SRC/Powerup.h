#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "GameObject.h"

class Powerup : public GameObject
{
public:
	Powerup(void);
	~Powerup(void);
	void Render(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif