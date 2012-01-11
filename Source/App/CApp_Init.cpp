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

	if(!Map.OnInit(5,5))
		return false;

	Map.GetTile(0,0) = CTile::TestTile;
	Map.GetTile(1,0) = CTile::TestTile;
	Map.GetTile(2,0) = CTile::TestTile;
	Map.GetTile(3,0) = CTile::TestTile;
	Map.GetTile(4,0) = CTile::TestTile;
	Map.GetTile(0,1) = CTile::TestTile;
	Map.GetTile(0,2) = CTile::TestTile;
	Map.GetTile(0,3) = CTile::TestTile;
	Map.GetTile(0,4) = CTile::TestTile;
	Map.GetTile(4,1) = CTile::TestTile;
	Map.GetTile(4,2) = CTile::TestTile;
	Map.GetTile(4,3) = CTile::TestTile;
	Map.GetTile(4,4) = CTile::TestTile;
	Map.GetTile(1,4) = CTile::TestTile;
	Map.GetTile(2,4) = CTile::TestTile;
	Map.GetTile(3,4) = CTile::TestTile;

	AEntity = Map.AddEntity(new CEntity(4));

	return true;
}

void CApp::OnExit()
{
	Map.OnExit();

	Map.RemoveEntity(AEntity);

	gTileSet.OnExit();

	SDL_FreeSurface(pDisplay);
	SDL_Quit();
}
