/*
 * Tile.cpp
 *
 *  Created on: 11.01.2012
 *      Author: 06hofmann-sebas
 */

#include "Tile/Tile.h"

CTile* CTile::EmptyTile = new CTile(0, TF_PASSABLE);

CTile* CTile::AirTile = new CTile(0, TF_PASSABLE);
CTile* CTile::EarthTile = new CTile(2, TF_NONE);
CTile* CTile::StoneTile = new CTile(3, TF_NONE);

Uint8 CTile::GetTileId(CVector Pos, CMap* pMap)
{
	if(this == EarthTile && pMap->GetTile(Pos.X, Pos.Y - 1) == AirTile) {
		if(pMap->GetTile(Pos.X - 1, Pos.Y) == AirTile && pMap->GetTile(Pos.X + 1, Pos.Y) == AirTile)
			return TileId + 5;
		else if(pMap->GetTile(Pos.X - 1, Pos.Y) == AirTile)
			return TileId + 2;
		else if(pMap->GetTile(Pos.X + 1, Pos.Y) == AirTile)
			return TileId + 4;
		return TileId + 3;
	}
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
