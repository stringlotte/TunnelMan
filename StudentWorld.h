#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include "GraphObject.h"
#include <string>
#include <queue>
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class GraphObject;
class Earth;
class TunnelMan;
class Actor;
class Protester;
class StudentWorld : public GameWorld
{
	public:
		StudentWorld(std::string assetDir);
		~StudentWorld();

		virtual int init();
		virtual int move();
		virtual void cleanUp();

		TunnelMan* getPlayer();

		std::string displayText(int score, int level, int lives, int health, int squirts, int gold, int sonar, int barrels);
		void updateDisplayText();

		void detectNearActors(int x, int y, int radius);
		bool rCloseToPlayer(Actor* actor, int radius);
		Protester* rCloseProtester(Actor* actor, int radius);

		bool removeDirt(int x, int y); 
		bool isSupported(int x, int y);
		bool isEarth(int x, int y);
		bool isBoulder(int x, int y,int radius=3);

		bool isWalkable(int x, int y, GraphObject::Direction direction);
		void moveToExit(Protester* p);
		GraphObject::Direction moveToPlayer(Protester* pr, int M);
		
		void addActor(Actor* actor) { m_actors.push_back(actor); }
		void decBarrel() { m_barrelsLeft--; }
		void decProtester() { m_protestersAlive--; }

	private:
		bool m_isFirstTick;
		int m_tickSinceLast;
		int m_protestersAlive;
		int m_barrelsLeft;
		Earth* m_earth[64][64];
		
		TunnelMan* m_player;
		std::vector<Actor*> m_actors;
		
		int m_maze[64][64];
		struct Grid {
			int x;
			int y;
			Grid(int a, int b): x(a),y(b){}
		};
		bool withInRadius(int x1, int y1, int x2, int y2, int radius); 
		void addProtesters();
		void addGoodies();
		void addItem(int num, int type);
		bool rCloseActors(int x, int y, int radius); 
};

#endif // STUDENTWORLD_H_
