/*
 * Map.cpp
 *
 *  Created on: 11.01.2012
 *      Author: 06hofmann-sebas
 */

#include "Map/Map.h"

CMap::CMap()
{
}

int CMap::AddEntity(CEntity* pEntity)
{
	if(pEntity)
		EntityList.Push(pEntity);
	return EntityList.GetId(pEntity);
}

void CMap::RemoveEntity(int Id)
{
	EntityList.Remove(Id);
}

CEntity* CMap::GetEntity(int Id)
{
	if(Id < (int)EntityList.size())
		return EntityList[Id];
	else return NULL;
}

bool CMap::OnInit(Uint16 Width, Uint16 Height)
{
	MapW = Width;
	MapH = Height;
	for(Uint16 i=0;i<MapW*MapH;i++)
		TileList.Push(CTile::EmptyTile);

	EntityList.clear();

	return true;
}

void CMap::OnExit()
{
	for(Uint16 i=0;i<EntityList.size();i++)
		EntityList.Remove(i);
	EntityList.clear();

	for(Uint16 i=0;i<TileList.size();i++)
		TileList[i] = NULL;
	TileList.clear();
}

CTile*& CMap::GetTile(Uint16 X, Uint16 Y)
{
	if(X < MapW && Y < MapH)
		return TileList[Y*MapW+X];
	else return CTile::EmptyTile;
}

void CMap::ClearMap(CTile* ClearTile)
{
	for(Uint16 i=0;i<TileList.size();i++)
		TileList[i] = ClearTile;
}

void CMap::OnMove(float fTime)
{
	for(Uint16 i=0;i<EntityList.size();i++)
		if(EntityList[i])
			EntityList[i]->OnMove(fTime, this);
}

bool CMap::LoadMapFromFile(const char *FileName)
{
	FILE* File = fopen(FileName, "r");

	if(fscanf(File, "MAP X:%hu,Y:%hu\n", &MapW, &MapH) < 2)
		return false;

	OnInit(MapW, MapH);

	for(Uint16 Y=0;Y<MapW;Y++) {
		for(Uint16 X=0;X<MapH;X++) {
			char TileId;
			if(fscanf(File, " %c", &TileId) < 1)
				return false;
			switch(TileId) {
			case '0':
				TileList[Y*MapW+X] = CTile::EmptyTile;
				break;
			case '1':
				TileList[Y*MapW+X] = CTile::TestTile;
				break;
			}
		}
		fscanf(File, "\n");
	}

	return true;
}

PtrList<CEntity*> CMap::GetTileEntityList(CVector_Ui16 Pos)
{
	PtrList<CEntity*> Ret;
	for(Uint16 i=0;i<EntityList.size();i++) {
		CEntity* pEntity = EntityList[i];
		if(pEntity && (CVector_Ui16)pEntity->Pos == Pos)
			Ret.Push(EntityList[i]);
	}
	return Ret;
}

int CMap::GetEntityId(CEntity *pEntity)
{
	return EntityList.GetId(pEntity);
}

void CMap::OnRender(SDL_Surface* pTarget)
{
	for(Uint16 Y=0;Y<MapH;Y++)
		for(Uint16 X=0;X<MapW;X++) {
			TileList[Y*MapW+X]->OnRender(pTarget, CVector(X, Y), this);
		}

	for(Uint16 i=0;i<EntityList.size();i++)
		if(EntityList[i])
			EntityList[i]->OnRender(pTarget, this);
}


