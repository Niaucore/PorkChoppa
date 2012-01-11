/*
 * Tile.cpp
 *
 *  Created on: 11.01.2012
 *      Author: 06hofmann-sebas
 */

#include "Tile/Tile.h"

CTile* CTile::EmptyTile = new CTile(0);

CTile* CTile::TestTile = new CTile(1);

Uint8 CTile::GetTileId(CVector Pos, CMap* pMap)
{
	return TileId;
}

void CTile::OnMove(float fTime)
{
}
