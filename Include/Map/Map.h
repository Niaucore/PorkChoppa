/*
 * Map.h
 *
 *  Created on: 12.12.2011
 *      Author: 06graefje-tim
 */

#pragma once /* MAP_H_ */

class CMap;

#define BLOCK_SIZE 32

#define MAX_GRAVITY_CHECKS 4

#define MAX(x,y) (x>y?x:y)

#include <math.h>

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

	float JumpAccl, MoveAccl, MaxSpeed, Gravity, Slowdown;

	int PlayerEntity;

	bool IsGameOver;
	Uint16 NumRemainingCollectibles;

	const char* LevelName;

public:
	CMap();

	CEntity* GetPlayer();

	Uint16 GetW() { return MapW; }
	Uint16 GetH() { return MapH; }

	float GetJumpAccl() { return JumpAccl; }
	float GetMoveAccl() { return MoveAccl; }
	float GetMaxSpeed() { return MaxSpeed; }
	float GetGravity()  { return Gravity;  }
	float GetSlowdown() { return Slowdown; }

	const char* GetLevelName() { return LevelName; }

	void UpdateNumbers();
	bool GameOver() { return IsGameOver; }
	Uint16 RemainingPoints() { return NumRemainingCollectibles; }

	int AddEntity(CEntity* pEntity);
	void RemoveEntity(int Id);

	CEntity* GetEntity(int Id);
	int GetEntityId(CEntity* pEntity);

	CTile*& GetTile(Uint16 X, Uint16 Y);

	PtrList<CEntity*> GetTileEntityList(CVector_Ui16 Pos);

	PtrList<CEntity*> GetEntitiesInRadius(CVector Pos, double Radius);

	void ClearMap(CTile* ClearTile);

	bool OnInit(Uint16 Width, Uint16 Height);
	void OnExit();

	bool LoadMapFromFile(const char* FileName);

	void OnMove(float fTime);
	void OnRender(SDL_Surface* pTarget);
};
