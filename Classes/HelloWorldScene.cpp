#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
	auto tl = CSLoader::createTimeline("MainScene.csb");
	tl->gotoFrameAndPlay(0, true);
	rootNode->runAction(tl);

	auto subNode = CSLoader::createNode("Node.csb");
	auto t2 = CSLoader::createTimeline("Node.csb");
	t2->gotoFrameAndPlay(0, true);
	subNode->runAction(t2);
	subNode->setPosition(200, 200);
	addChild(subNode);

	addChild(rootNode);	

	scheduleUpdate();

	return true;
}

void HelloWorld::update(float delta) {
	static int timer = 0;
	static int posX = 0;
	if (timer++ % 50 == 0) {
		posX++;
		
		auto subNode = CSLoader::createNode("Node.csb");
		auto t2 = CSLoader::createTimeline("Node.csb");
		t2->gotoFrameAndPlay(0, true);
		subNode->runAction(t2);
		subNode->setPosition(200 + posX * 30, 200);
		addChild(subNode);
	}
}
