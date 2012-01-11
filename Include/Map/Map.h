/*
 * Map.h
 *
 *  Created on: 12.12.2011
 *      Author: 06graefje-tim
 */

#pragma once /* MAP_H_ */

class CMap;

#include <SDL/SDL.h>

#include "Tile/TileSet.h"
#include "Tile/Tile.h"

#include "Helper/PtrList.h"

class CMap
{
private:
	PtrList<CTile*> TileList;

	Uint16 MapW, MapH;

public:
	CMap();

	bool OnInit(Uint16 Width, Uint16 Height);
	void OnExit();

	void OnMove(float fTime);
	void OnRender(SDL_Surface* pTarget);
};
