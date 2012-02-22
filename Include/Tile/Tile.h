/*
 * Tile.h
 *
 *  Created on: 09.01.2012
 *      Author: 06hofmann-sebas
 */

#pragma once /* TILE_H_ */

class CTile;

#include <SDL/SDL.h>

#include "Tile/TileSet.h"

#include "Map/Map.h"

#include "Entities/Entity.h"

#include "Helper/CVector.h"

enum eTileFlags {
	TF_NONE = 0x00,
	TF_PASSABLE = 0x01
};

class CTile
{
private:
	Uint8 TileId;
	Uint8 TileFlags;

public:
	CTile(Uint8 Id, Uint8 Flags = TF_PASSABLE) : TileId(Id), TileFlags(Flags) { }
	virtual ~CTile() { }

	static CTile* EmptyTile;
	static CTile* AirTile;
	static CTile* EarthTile;
	static CTile* StoneTile;

	virtual Uint8 GetTileId(CVector Pos, CMap* pMap);

	virtual bool IsPassable(CVector Pos, CMap* pMap, CEntity* pTrespasser);

	virtual void OnMove(float fTime);

	virtual void OnRender(SDL_Surface* pTarget, CVector Pos, CMap* pMap);
};
