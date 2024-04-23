#include <stdlib.h>
#include "GameUtil.h"
#include "Powerup.h"
#include "BoundingShape.h"

Powerup::Powerup(void) : GameObject("Powerup")
{
	mAngle = rand() % 360;
	mRotation = rand() % 90;
	
	mPosition.x = rand() / 2;
	mPosition.y = rand() / 2;
	mPosition.z = 0.0;
	
	mVelocity.x = 3.0 * cos(DEG2RAD * mAngle);
	mVelocity.y = 3.0 * sin(DEG2RAD * mAngle);
	mVelocity.z = 0.0;
}

Powerup::~Powerup(void)
{
}

void Powerup::Render(void)
{
	glBegin(GL_LINE_LOOP);
	
	glColor3f(0.0, 0.0, 1.0);
	
	glVertex3f(-3, -3, 0.0);
	glVertex3f(-3, 3, 0.0);
	glVertex3f(3, 3, 0.0);
	glVertex3f(3, -3, 0.0);
	
	glEnd();

	glEnable(GL_LIGHTING);
}

bool Powerup::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() == GameObjectType("Bullet")) return false;
	if (o->GetType() == GameObjectType("Asteroid")) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void Powerup::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}