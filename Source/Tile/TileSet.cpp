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
	if((pTileSet = CSurface::Load(TileSetName)) == NULL)
		return false;

	SDL_SetColorKey(pTileSet, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(pTileSet->format, 255,0,255));

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

void CTileSet::RenderTile(Uint8 TileIdX, Uint8 TileIdY, SDL_Surface* pTarget, float X, float Y)
{
	CSurface::Blit(pTarget, pTileSet, X * TileW, Y * TileH, TileIdX % NumTilesX * TileW, TileIdY % NumTilesY * TileH, TileW, TileH);
}
