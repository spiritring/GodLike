#include "TestBox2d.h"
#include <vector>

using namespace std;

#define PTM_RATIO 32.0

CTestBox2d::CTestBox2d()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	// 初始化box2d对象 
	b2Vec2 noGravity(0, 0);
	m_PhyxWorld = new b2World(noGravity);
	m_PhyxWorld->SetAllowSleeping(true);

	// 设置碰撞监听
	m_PhyxWorld->SetContactListener(this);
	m_PhyxWorld->SetContactFilter(this);

	// Create ball body and shape
	{
		auto spr = CCSprite::create();
		spr->initWithFile("CloseNormal.png");
		addChild(spr);

		b2BodyDef ballBodyDef;
		ballBodyDef.type = b2_dynamicBody;
		ballBodyDef.position.Set(50 / PTM_RATIO, winSize.height / 2 / PTM_RATIO);
		ballBodyDef.userData = spr;
		m_PhyxBody = m_PhyxWorld->CreateBody(&ballBodyDef);

		b2CircleShape circle;
		circle.m_radius = 26.0 / PTM_RATIO;

		b2FixtureDef ballShapeDef;
		ballShapeDef.shape = &circle;
		ballShapeDef.density = 1.0f;
		ballShapeDef.friction = 0.2f;
		ballShapeDef.restitution = 0.8f;
		m_PhyxBody->CreateFixture(&ballShapeDef);

		m_PhyxBody->ApplyForce(b2Vec2(200, 0), b2Vec2(0, 0), false);
	}

	// Create ball body and shape
	{
		auto spr = CCSprite::create();
		spr->initWithFile("CloseNormal.png");
		addChild(spr);

		b2BodyDef ballBodyDef;
		ballBodyDef.type = b2_dynamicBody;
		ballBodyDef.position.Set((500) / PTM_RATIO, winSize.height / 2 / PTM_RATIO);
		ballBodyDef.userData = spr;
		m_PhyxBody = m_PhyxWorld->CreateBody(&ballBodyDef);

		b2CircleShape circle;
		circle.m_radius = 26.0 / PTM_RATIO;

		b2FixtureDef ballShapeDef;
		ballShapeDef.shape = &circle;
		ballShapeDef.density = 1.0f;
		ballShapeDef.friction = 0.2f;
		ballShapeDef.restitution = 0.8f;
		m_PhyxBody->CreateFixture(&ballShapeDef);
	}
}

CTestBox2d::~CTestBox2d()
{

}

void CTestBox2d::BeginContact(b2Contact* contact)
{

}

void CTestBox2d::EndContact(b2Contact* contact)
{

}

void CTestBox2d::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}

void CTestBox2d::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}

bool CTestBox2d::ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB)
{
	return true;
}

void CTestBox2d::update(float deltaTime)
{
	if (m_PhyxWorld)
	{
		m_PhyxWorld->Step(deltaTime, 8, 3);

		for (b2Body *b = m_PhyxWorld->GetBodyList(); b; b = b->GetNext()) 
		{
			if (b->GetUserData() != nullptr) 
			{
				CCSprite *spr = (CCSprite *)b->GetUserData();
				auto vPos = ccp(b->GetPosition().x * PTM_RATIO,
					b->GetPosition().y * PTM_RATIO);
				spr->setPosition(vPos);
				spr->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
			}
		}
	}
}





