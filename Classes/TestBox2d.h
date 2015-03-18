#ifndef __TestBox2d_SCENE_H__
#define __TestBox2d_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

class CTestBox2d :
	public CCNode,
	public b2ContactListener,
	public b2ContactFilter
{
public:
	CTestBox2d();
	virtual ~CTestBox2d();

private:
	virtual void BeginContact(b2Contact* contact);
	virtual void EndContact(b2Contact* contact);
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	virtual bool ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB);

public:
	void update(float deltaTime);

private:
	b2World*                    m_PhyxWorld;
	b2Body *                    m_PhyxBody;
};

#endif