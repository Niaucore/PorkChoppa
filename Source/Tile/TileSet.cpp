/*
 * TileSet.cpp
 *
 *  Created on: 09.01.2012
 *      Author: 06hofmann-sebas
 */

#include "Tile/TileSet.h"

CTileSet gTileSet;

CTileSet::CTileSet()
{
	pTileSet = NULL;
	TileW = TileH = 0;
	NumTilesX = NumTilesY = 0;
}

bool CTileSet::OnInit(const char* TileSetName, Uint16 TileWidth, Uint16 TileHeight)
{
	SDL_Surface* pTemp;
	if((pTemp = SDL_LoadBMP(TileSetName)) == NULL)
		return false;
	if((pTileSet = SDL_DisplayFormat(pTemp)) == NULL)
		return false;
	SDL_FreeSurface(pTemp);

	TileW = TileWidth;
	TileH = TileHeight;

	NumTilesX = pTileSet->w / TileW;
	NumTilesY = pTileSet->h / TileH;

	return true;
}

void CTileSet::OnExit()
{
	SDL_FreeSurface(pTileSet);
}

void CTileSet::RenderTile(Uint8 TileId, SDL_Surface* pTarget, Sint16 X, Sint16 Y)
{
	SDL_Rect TileRc;
	TileRc.x = TileId % NumTilesX * TileW;
	TileRc.y = TileId / NumTilesY * TileH;
	TileRc.w = TileW;
	TileRc.h = TileH;

	SDL_Rect DestRc;
	DestRc.x = X;
	DestRc.y = Y;


	SDL_BlitSurface(pTileSet, &TileRc, pTarget, &DestRc);
}
