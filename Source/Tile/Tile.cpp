/*
 * Tile.cpp
 *
 *  Created on: 11.01.2012
 *      Author: 06hofmann-sebas
 */

#include "Tile/Tile.h"

CTile* CTile::EmptyTile = new CTile(0, TF_PASSABLE);

CTile* CTile::TestTile = new CTile(1, TF_NONE);

Uint8 CTile::GetTileId(CVector Pos, CMap* pMap)
{
	return TileId;
}

bool CTile::IsPassable(CVector Pos, CMap* pMap, CEntity* pTrespasser)
{
	return (TileFlags & TF_PASSABLE);
}

void CTile::OnMove(float fTime)
{
}

void CTile::OnRender(SDL_Surface* pTarget, CVector Pos, CMap* pMap)
{
	gTileSet.RenderTile(GetTileId(Pos, pMap), pTarget, Pos.X, Pos.Y);
}
