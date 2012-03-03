/*
 * Entity.cpp
 *
 *  Created on: 11.01.2012
 *      Author: Tim
 */

#include "Entities/Entity.h"

CVector_Ui8 CEntity::GetSprite(CMap* CMap)
{
	if (FacingLeft)
		return Sprite;
	else return (Sprite + CVector_Ui8(1, 0));
}

bool CEntity::CanMove(CVector MovDir, CMap* pMap)
{
	CVector NewPos = Pos + MovDir; //Geht von der neuen Position aus

	CVector Cp0 = NewPos - CVector(HalfSize, HalfSize); //Collision-Point 0
	CVector Cp1 = NewPos + CVector(HalfSize, HalfSize);
	CVector Cp2 = NewPos + CVector(HalfSize, -HalfSize);
	CVector Cp3 = NewPos + CVector(-HalfSize, HalfSize);

	bool MayPass = (pMap->GetTile(Cp0.X, Cp0.Y)->IsPassable(Cp0, pMap, this)
			&& pMap->GetTile(Cp1.X, Cp1.Y)->IsPassable(Cp1, pMap, this)
			&& pMap->GetTile(Cp2.X, Cp2.Y)->IsPassable(Cp2, pMap, this)
			&& pMap->GetTile(Cp3.X, Cp3.Y)->IsPassable(Cp2, pMap, this));

	return MayPass;
}

bool CEntity::CanJump(CMap* pMap)
{
	return ((Vel.Y == 0) && CanMove(CVector(0, -1 * HalfSize), pMap));
}

CVector CEntity::GetEntityCorner(CVector MovDir)
{
	float ColX = 0, ColY = 0;

	if (MovDir.Y > 0)
		ColY = 1;
	else if (MovDir.Y < 0)
		ColY = -1;

	if (MovDir.X > 0)
		ColX = 1;
	else if (MovDir.X < 0)
		ColX = -1;

	return CVector(HalfSize * ColX, HalfSize * ColY);
}

void CEntity::OnMove(float fTime, CMap* pMap)
{
	float MovementAtom = 1.0f / BLOCK_SIZE;

	if ((0.1f > Vel.X) && (Vel.X > -0.1f)) {
		Vel.X = Mov.X = 0;
	}
	if ((0.1f > Vel.Y) && (Vel.Y > -0.1f)) {
		Vel.Y = Mov.Y = 0;
	}

	if (CanMove(CVector(0, MovementAtom), pMap))
		Vel += CVector(0, 9.81f * fTime * 8);

	if (Vel != CVector(0, 0)) {

		Vel *= pow(0.125f, fTime * 4);

		Mov += Vel * fTime;
		int X = abs(Mov.X * BLOCK_SIZE), Y = abs(Mov.Y * BLOCK_SIZE);

		int Xdir = 0, Ydir = 0;
		if (X > 0)
			Xdir = (int) (Mov.X * BLOCK_SIZE) / abs(Mov.X * BLOCK_SIZE);
		if (Y > 0)
			Ydir = (int) (Mov.Y * BLOCK_SIZE) / abs(Mov.Y * BLOCK_SIZE);

		while(X > 0 || Y > 0) {

			if (X > 0) {
				if (CanMove(CVector(Xdir * MovementAtom, 0), pMap)) {
					Pos.X += MovementAtom * Xdir;
					Mov.X -= Xdir * MovementAtom;
					--X;
				} else {
					X = 0;
					Vel.X = Mov.X = 0;
				}
			}
			if (Y > 0) {
				if (CanMove(CVector(0, Ydir * MovementAtom), pMap)) {
					Pos.Y += MovementAtom * Ydir;
					Mov.Y -= Ydir * MovementAtom;
					--Y;
				} else {
					Y = 0;
					Vel.Y = Mov.Y = 0;
				}
			}
		}
	}

	if(!IsCollectible()) { //Collect Things
		PtrList<CEntity*> CollectibleList = pMap->GetEntitiesInRadius(Pos, 1);
		for(Uint16 i=0;i<CollectibleList.size();i++) {
			if(!CollectibleList[i]->IsCollectible())
				continue;
			else CollectibleList[i]->OnCollect(this, pMap);
		}
	}
}

void CEntity::Jump(CVector JumpDirection, CMap* pMap)
{
	if (CanJump(pMap)) {
		Vel += JumpDirection;
	}
}

void CEntity::OnRender(SDL_Surface* pTarget, CMap* pMap)
{
	CVector_Ui8 Sprite = GetSprite(pMap);
	Uint8 SpriteX = Sprite.X;
	Uint8 SpriteY = Sprite.Y;

	gTileSet.RenderTile(SpriteX, SpriteY, pTarget, Pos.X - HalfSize, Pos.Y - HalfSize);
}

bool CEntity::IsCollectible()
{
	return false;
}

void CEntity::OnCollect(CEntity *pCollector, CMap *pMap)
{
}
