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

void CMap::OnMove(float fTime)
{
	for(Uint16 i=0;i<EntityList.size();i++)
		if(EntityList[i])
			EntityList[i]->OnMove(fTime, this);
}

void CMap::OnRender(SDL_Surface* pTarget)
{
	for(Uint16 Y=0;Y<MapH;Y++)
		for(Uint16 X=0;X<MapW;X++) {
			gTileSet.RenderTile(TileList[Y*MapW+X]->GetTileId(CVector(X, Y), this), pTarget, X, Y);
		}

	for(Uint16 i=0;i<EntityList.size();i++)
		if(EntityList[i])
			gTileSet.RenderTile(EntityList[i]->GetSprite(this), pTarget, EntityList[i]->Pos.X, EntityList[i]->Pos.Y);
}


