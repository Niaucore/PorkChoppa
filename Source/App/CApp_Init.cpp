/*
 * CApp_Init.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

bool CApp::OnInit() {
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		return false;

	if ((pDisplay = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		return false;

	if(!gTileSet.OnInit("gfx/TileSet.bmp", 16, 16))
		return false;

	if(!Map.LoadMapFromFile("Maps/1.map.txt"))
		return false;

	AEntity = Map.AddEntity(new CEntity(0, 2, 0.475, CVector(2,2)));

	MEntity = Map.AddEntity(new CEntity(0, 3, 0.475, CVector(4,2)));

	return true;
}

void CApp::OnExit()
{
	Map.OnExit();

	Map.RemoveEntity(AEntity);
	Map.RemoveEntity(MEntity);

	gTileSet.OnExit();

	SDL_FreeSurface(pDisplay);
	SDL_Quit();
}
