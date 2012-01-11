/*
 * App.h
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#pragma once/* APP_H_ */

class CApp;

#include <SDL/SDL.h>

#include "Map/Map.h"

class CApp {
private:
	SDL_Surface* pDisplay;
	bool Running;

	CMap Map;

	int AEntity;

public:
	CApp();

	int OnExecute();

	bool OnInit();
	void OnExit();

	void OnEvent(SDL_Event* pEvent);
	void OnRender();
	void OnMove(float fTime);
};
