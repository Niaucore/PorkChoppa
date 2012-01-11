/*
 * Tile.h
 *
 *  Created on: 09.01.2012
 *      Author: 06hofmann-sebas
 */

#pragma once /* TILE_H_ */

class CTile;

#include <SDL/SDL.h>

//#include "Map/Map.h"

#include "Helper/CVector.h"

class CTile
{
private:
	Uint8 TileId;

public:
	CTile(Uint8 Id) : TileId(Id) { }
	virtual ~CTile() { }

	static CTile* EmptyTile;
	static CTile* TestTile;

	virtual Uint8 GetTileId(CVector Pos/*, CMap* pMap*/);
};
