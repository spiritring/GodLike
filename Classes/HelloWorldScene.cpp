#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "2d/CCParticleSystemQuad.h"
#include "TestBox2d.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	m_TB = new CTestBox2d();
	addChild(m_TB);
    
	//auto rootNode = CSLoader::createNode("MainScene.csb");
	//auto tl = CSLoader::createTimeline("MainScene.csb");
	//tl->gotoFrameAndPlay(0, true);
	//rootNode->runAction(tl);

	//auto subNode = CSLoader::createNode("Node.csb");
	//auto t2 = CSLoader::createTimeline("Node.csb");
	//t2->gotoFrameAndPlay(0, true);
	//subNode->runAction(t2);
	//subNode->setPosition(200, 200);
	//addChild(subNode);

	//addChild(rootNode);
	
	scheduleUpdate();

	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->setSwallowTouches(false);
	_touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::TouchBegan, this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::TouchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::TouchEnded, this);
	_touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::TouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
	return true;
}

bool HelloWorld::TouchBegan(Touch* touch, Event* event)
{
	CCLOG("ccTouchBegan\n");
	return true;
}

void HelloWorld::TouchMoved(Touch* touch, Event* event)
{
	CCLOG("ccTouchMoved\n");
}

void HelloWorld::TouchEnded(Touch* touch, Event* event)
{
	CCLOG("ccTouchEnded\n");
}

void HelloWorld::TouchCancelled(Touch* touch, Event* event)
{
	CCLOG("ccTouchCancelled\n");
}

void HelloWorld::update(float delta) {

	m_TB->update(delta);

	static int timer = 0;
	static int posX = 0;
	static int dt = 1;
	if (timer++ % 10 == 0) {
		posX += dt;

		if (posX > 10) {
			dt = -1;
		}
		else if (posX < 0) {
			dt = 1;
		}
		
		//{
		//	auto subNode = CSLoader::createNode("Node.csb");
		//	auto t2 = CSLoader::createTimeline("Node.csb");
		//	t2->gotoFrameAndPlay(0, true);
		//	subNode->runAction(t2);
		//	subNode->setPosition(200 + posX * 30, 200);
		//	addChild(subNode);
		//}

		{
			//static auto subNode = CSLoader::createNode("Node1.csb");
			//static auto t2 = CSLoader::createTimeline("Node1.csb");
			//static int isOK = 0;
			//static auto p1 = static_cast<ParticleSystemQuad*>(subNode->getChildByName("Particle_1"));
			//static auto p2 = static_cast<ParticleSystemQuad*>(subNode->getChildByName("Particle_2"));
			//
			//if (isOK == 0) {
			//	isOK = 1;
			//	t2->gotoFrameAndPlay(0, true);
			//	subNode->runAction(t2);
			//	addChild(subNode);
			//}

			//p1->setDuration(1);
			//p2->setDuration(1);

			//p1->setPositionType(ParticleSystem::PositionType::RELATIVE);
			//p2->setPositionType(ParticleSystem::PositionType::RELATIVE);

			//p1->setPosition(200 + posX * 30, 400);
			//p2->setPosition(200 + posX * 30, 500);

			//p1->setAutoRemoveOnFinish(true);
			//p2->setAutoRemoveOnFinish(true);
		}
	}
}
