#include "DifficultyScene.h"



DifficultyScene::DifficultyScene(SDL_Renderer * renderer, SDL_Texture *global, GameState* g, Difficulty* d)
{
	r = renderer;
	t = global;
	gameState = g;
	menu = IMG_LoadTexture(r, "../../res/gfx/difficult.png");
	difficult = d;
}


DifficultyScene::~DifficultyScene()
{
	r = nullptr;
	t = nullptr;
	gameState = nullptr;

	delete t;
	delete r;
	delete gameState;
}

void DifficultyScene::Loop()
{
	SDL_Event evnt;
	for (bool isRunning = true; isRunning;)
	{
		//INPUT HANDLER
		while (SDL_PollEvent(&evnt))
		{
			switch (evnt.type)
			{
			case SDL_QUIT:
				isRunning = false;
				*gameState = GameState::QUIT;
				break;
			case SDL_MOUSEBUTTONDOWN:

				if (evnt.button.y >= 210 && evnt.button.y <= 270
					&& (evnt.button.x >= 300 && evnt.button.x <= 470))
				{
					isRunning = false;
					*difficult = Difficulty::EASE;
					*gameState = GameState::GAME;
				}
				else if (evnt.button.y >= 350 && evnt.button.y <= 410
					&& evnt.button.x >= 260 && evnt.button.x <= 510)
				{
					isRunning = false;
					*difficult = Difficulty::MEDIUM;
					*gameState = GameState::GAME;
				}
				else if (evnt.button.y >= 510 && evnt.button.y <= 570
					&& evnt.button.x >= 320 && evnt.button.x <= 450)
				{
					isRunning = false;
					*difficult = Difficulty::HARD;
					*gameState = GameState::GAME;
				}
				break;
			case SDL_KEYDOWN:

				if (evnt.key.keysym.sym == SDLK_ESCAPE)
				{
					isRunning = false;
					*gameState = GameState::QUIT;
				}
				break;
			}

		}
		Draw();
	}
}

void DifficultyScene::Draw()
{
	SDL_RenderClear(r);

	SDL_RenderCopy(r, t, new SDL_Rect{ 0,0,800,50 }, new SDL_Rect{ 0,0,800,100 });

	string text = "Ease";
	SDL_Rect textLocation = { 300,210,170,60 };
	RenderText(text.c_str(), textLocation);

	text = "Medium";
	textLocation = { 260,350,250,60 };
	RenderText(text.c_str(), textLocation);

	text = "Hard";
	textLocation = { 320,510,130,60 };
	RenderText(text.c_str(), textLocation);

	//Pintem tots elements del renderer
	SDL_RenderPresent(r);
}