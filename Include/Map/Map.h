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

#include "Entities/Entity.h"

#include "Helper/PtrList.h"

class CMap
{
private:
	PtrList<CTile*> TileList;
	PtrList<CEntity*> EntityList;

	Uint16 MapW, MapH;

public:
	CMap();

	Uint16 GetW() { return MapW; }
	Uint16 GetH() { return MapH; }

	int AddEntity(CEntity* pEntity);
	void RemoveEntity(int Id);

	CEntity* GetEntity(int Id);
	int GetEntityId(CEntity* pEntity);

	CTile*& GetTile(Uint16 X, Uint16 Y);

	PtrList<CEntity*> GetTileEntityList(CVector_Ui16 Pos);

	void ClearMap(CTile* ClearTile);

	bool OnInit(Uint16 Width, Uint16 Height);
	void OnExit();

	bool LoadMapFromFile(const char* FileName);

	void OnMove(float fTime);
	void OnRender(SDL_Surface* pTarget);
};
