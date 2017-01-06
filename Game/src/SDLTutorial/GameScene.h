#pragma once
#include "Scene.h"
#include <vector>
#include "DynamicObject.h"
#include "Rana.h"
#include <time.h>
#include "FileManager.h"

class GameScene :
	public Scene
{
	int level;
	FileManager *fileManager;

	Rana *player;
	int oldPuntuation;
	bool incrementVelocity;

	Object insect;
	bool insectTake;
	bool insectPopUp;

	int initalTime;
	int playerTime;

	time_t* playerTimeSaved;
	time_t* playerCurrentTime;

	time_t* insectTimeSaved;
	time_t* insectCurrentTime;

	vector<Object> sceneObject;

	vector<DynamicObject> *riverLinesObjects;
	DynamicObject **lastRiverObject;
	int riverElementsForLine;

	vector<DynamicObject> *roadLinesObjects;
	DynamicObject **lastRoadObject;
	int roadElementsForLine;

	bool playerInPlatform;

	bool firstOccupied;
	bool secondOccupied;
	bool thirdOccupied;
	bool fourthOccupied;
	bool fifthOccupied;

	bool Collision(DynamicObject &d, Rana &r);
	bool Collision(Object &d, Rana &r);

	void Draw();
	void DrawPause();
	void Update();
	void InsertInsect();
	void DecreaseTime();
public:
	GameScene(SDL_Renderer *, SDL_Texture *, GameState*,Rana *,Difficulty*,FileManager*);
	~GameScene();
	void Loop();
	void Start();
};

