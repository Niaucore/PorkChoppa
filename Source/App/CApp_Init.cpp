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
	/*if(!Map.OnInit(9,9))
		return false;

	Map.ClearMap(CTile::TestTile);
	for(Uint16 X=1;X<Map.GetW()-1;X++)
		for(Uint16 Y=1;Y<Map.GetH()-1;Y++)
			Map.GetTile(X, Y) = CTile::EmptyTile;

	Map.GetTile(4,1) = CTile::TestTile;
	Map.GetTile(4,2) = CTile::TestTile;
	Map.GetTile(4,3) = CTile::TestTile;

	Map.GetTile(Map.GetW() - 2, Map.GetH() - 2) = CTile::TestTile;
	Map.GetTile(Map.GetW() - 3, Map.GetH() - 2) = CTile::TestTile;
	Map.GetTile(Map.GetW() - 4, Map.GetH() - 2) = CTile::TestTile;
	Map.GetTile(Map.GetW() - 2, Map.GetH() - 3) = CTile::TestTile;*/

	AEntity = Map.AddEntity(new CEntity(0, 2, 0.5));
	Map.GetEntity(AEntity)->Pos = CVector(2,2);

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
