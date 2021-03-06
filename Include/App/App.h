/*
 * App.h
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#pragma once/* APP_H_ */

class CApp;

#include <SDL/SDL.h>

#include <math.h>

#include "Input/Input.h"

#include "Map/Map.h"

class CApp {
private:
	SDL_Surface* pDisplay;
	SDL_Surface* pGameOver;

	bool Running;

	bool Pause;

	CMap Map;

	float FPS;
	float m_fTime;
	float GameOverCheckTime;

public:
	CApp();

	int OnExecute(const char* LevelName);

	bool OnInit(const char* LevelName);
	void OnExit();

	void OnEvent(SDL_Event* pEvent);
	void OnRender();
	void OnMove(float fTime);
};
