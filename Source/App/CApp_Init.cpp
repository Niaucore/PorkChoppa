/*
 * CApp_Init.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

bool CApp::OnInit(const char* LevelName) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		return false;

	if(!Map.LoadMapFromFile(LevelName))
		return false;

	if ((pDisplay = SDL_SetVideoMode(Map.GetW() * 32, Map.GetH() * 32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		return false;


	if((pGameOver = CSurface::Load("gfx/GameOver.bmp")) == NULL)
		return false;

	if(!gTileSet.OnInit("gfx/TileSet.bmp", 32, 32))
		return false;

	return true;
}

void CApp::OnExit()
{
	Map.OnExit();

	gTileSet.OnExit();

	SDL_FreeSurface(pGameOver);

	SDL_FreeSurface(pDisplay);
	SDL_Quit();
}
