/*
 * TileSet.h
 *
 *  Created on: 09.01.2012
 *      Author: 06hofmann-sebas
 */

#pragma once /* TILESET_H_ */

#include <SDL/SDL.h>

#include "Helper/CSurface.h"

class CTileSet
{
private:
	SDL_Surface* pTileSet;

	Uint16 TileW, TileH;

	Uint16 NumTilesX, NumTilesY;

public:
	CTileSet();

	bool OnInit(const char* TileSetName, Uint16 TileWidth, Uint16 TileHeight);
	void OnExit();

	void RenderTile(Uint8 TileId, SDL_Surface* pTarget, float X, float Y) {
		RenderTile(TileId % NumTilesX, TileId / NumTilesX, pTarget, X, Y);
	}
	void RenderTile(Uint8 TileIdX, Uint8 TileIdY, SDL_Surface* pTarget, float X, float Y);
};

extern CTileSet gTileSet;
