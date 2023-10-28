#ifndef ACTOR_H_
#define ACTOR_H_
#include "GameConstants.h"
#include "GraphObject.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class StudentWorld;

class Actor: public GraphObject
{
	public:
		Actor(int imageID, int x, int y, Direction dir, double size, unsigned int depth, StudentWorld* studentworld);
		virtual ~Actor();
		virtual void doSomething() = 0; // do something during every tick
		bool isAlive() const { return isalive; }
		void setDead() { isalive=false; }
		StudentWorld* getWorld()const { return m_world; }

		void moveTo(int x, int y);
		
	private:
		StudentWorld* m_world;
		bool isalive;

};

class HumanActor: public Actor
{
	public:
		HumanActor(StudentWorld* world, int imageID, int x, int y, Direction dir, int hitpoint);
        virtual ~HumanActor() {}

		int getHealth() const { return m_health; }
		void setHealth(int amt) { m_health-=amt; }

		void moveInDirection(Direction direction);
		virtual void isAnnoyed(int hitpoint) = 0;
		
	private:
		int m_health;
};


class TunnelMan: public HumanActor
{
	public:
		TunnelMan(StudentWorld* world);
		virtual ~TunnelMan() {}
		virtual void doSomething();

		void inc(int id);
        int getSquirts() const { return m_squirts; }
        int getSonar() const { return m_sonar; }
        int getGold() const { return m_gold; }

		virtual void isAnnoyed(int hitpoint);
		void shoot();

	private:
		int m_squirts;
		int m_sonar;
		int m_gold;
};

class Earth: public Actor
{
	public:
		Earth(int x, int y, StudentWorld* world); //start out facing rightward, depth = 3, size=.25
        virtual ~Earth() {}
        virtual void doSomething() {}
}; 

class Boulder: public Actor
{
	public:
		Boulder(int x, int y, StudentWorld* world);
		virtual void doSomething();
		void bonkMan();
	private:
		bool stable;
		bool isFalling;
		int m_ticks;
		bool haveBonked = false;

};

class Squirt: public Actor
{
	public:
		Squirt(StudentWorld* world, int x, int y, Direction dir);
		virtual void doSomething();
		bool annoyProtesters();
	private:
		int m_travel;
};


class Item: public Actor
{
	public:
		Item(int imageID, int x, int y, StudentWorld* world);
		virtual void doSomething() = 0;
		void pendingDisap(int ticks);
	private:
		int m_tick;
};

class Barrel : public Item
{
	public:
		Barrel(int x, int y, StudentWorld* world);
		virtual void doSomething();
};

class Gold :public Item
{
	public:
		Gold(StudentWorld* world, int x, int y, bool visible,bool pickupable);
		virtual void doSomething();
	private:
		bool isDropped;
};

class Goodie: public Item
{
	public:
		Goodie(int imageID, int x, int y, StudentWorld* world);
		virtual void doSomething();
};

class Sonar: public Goodie
{
	public:
		Sonar(StudentWorld* world, int x, int y);
};

class WaterPool: public Goodie
{
	public:
		WaterPool(StudentWorld* world, int x, int y);
};

class Protester: public HumanActor
{
	public:
		Protester(StudentWorld* world, int imageID,int hitpoint);
        virtual ~Protester() {}
		void doSomething();

		void beBribed();
		void isAnnoyed(int hitpoint);
		void beStunned();

	private:
		bool m_leaveField;
		int m_numSquares;
		int tickcnt;
        int m_nonRestTicks;
        int m_annoyance;
		int checkYell;
		int m_ticksToWaitBetweenMoves;
		void numSquaresToMoveInCurrentDirection() { m_numSquares = rand() % 53 + 8; }
		void turnAround();
		Direction randomDirection();
		Direction playerPos();
		bool isAtIntersection();
		bool checkFace();
		bool straightPathToPlayer(Direction direction);
};


class RegularProtester: public Protester
{
	public:
		RegularProtester(StudentWorld* world);
};

class HardcoreProtester: public Protester
{
	public:
		HardcoreProtester(StudentWorld* world);
};


#endif // ACTOR_H_
