/*
 * Map.cpp
 *
 *  Created on: 11.01.2012
 *      Author: 06hofmann-sebas
 */

#include "Map/Map.h"

CMap::CMap()
{
	PlayerEntity = -1;
	IsGameOver = false;
	NumRemainingCollectibles = 1;
	LevelName = NULL;
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

bool CMap::LoadMapFromFile(const char* FileName)
{
	EntityList.clear();

	LevelName = FileName;

	FILE* File = fopen(FileName, "r");
	if(File == NULL) return false;

	if(fscanf(File, "MAP X:%hu,Y:%hu\n", &MapW, &MapH) < 2)
		return false;

	if(fscanf(File, "GRAV:%f,SLOWDOWN:%f,ACCL:%f,JUMP:%f,MAX_SPEED:%f\n", &Gravity, &Slowdown, &MoveAccl, &JumpAccl, &MaxSpeed) < 5)
		return false;

	OnInit(MapW, MapH);

	for(Uint16 Y=0;Y<MapH;Y++) {
		for(Uint16 X=0;X<MapW;X++) {
			char TileId;
			if(fscanf(File, " %c", &TileId) < 1)
				return false;
			switch(TileId) {
			case '0':
				TileList[Y*MapW+X] = CTile::AirTile;
				break;
			case '1':
				TileList[Y*MapW+X] = CTile::EarthTile;
				break;
			case '2':
				TileList[Y*MapW+X] = CTile::StoneTile;
				break;
			case 'P':
				TileList[Y*MapW+X] = CTile::AirTile;
				PlayerEntity = AddEntity(new CEntity(0,2, 0.46875f/*0.5 - 1/32(ein Pixel)*/, CVector(X + 0.5f, Y + 0.5f)));
				break;
			case 'C':
				TileList[Y*MapW+X] = CTile::AirTile;
				AddEntity(new CollectibleEntity(2,1, 0.46875f, CVector(X + 0.5f, Y + 0.5f)));
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

PtrList<CEntity*> CMap::GetEntitiesInRadius(CVector Pos, double Radius)
{
	PtrList<CEntity*> Ret;
	double RadiusSq = Radius * Radius;
	for(Uint16 i=0;i<EntityList.size();i++) {
		if(EntityList[i]) {
			CVector D = (EntityList[i]->Pos - Pos);
			if(VecLengthSq(D) < RadiusSq) {
				Ret.Push(EntityList[i]);
			}
		}
	}
	return Ret;
}

CEntity* CMap::GetPlayer()
{
	return GetEntity(PlayerEntity);
}

void CMap::UpdateNumbers()
{
	NumRemainingCollectibles = 0;

	for(Uint16 i=0;i<EntityList.size();i++) {
		if(EntityList[i] && EntityList[i]->IsCollectible()) {
			++NumRemainingCollectibles;
		}
	}
	if(NumRemainingCollectibles > 0) IsGameOver = false;
	else IsGameOver = true;
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


