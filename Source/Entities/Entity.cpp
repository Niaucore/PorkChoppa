/*
 * Entity.cpp
 *
 *  Created on: 11.01.2012
 *      Author: Tim
 */

#include "Entities/Entity.h"

CVector_Ui8 CEntity::GetSprite(CMap* CMap)
{
	if(Health < 10) return CVector_Ui8(0,1);
	if(FacingLeft)
		return Sprite;
	else return (Sprite + CVector_Ui8(1,0));
}

bool CEntity::CanMove(CVector MovDir, CMap* pMap)
{
	CVector NewPos = Pos + MovDir;//Geht von der neuen Position aus

	CVector Cp0 = NewPos - CVector(HalfSize, HalfSize); //Collision-Point 0
	CVector Cp1 = NewPos + CVector(HalfSize, HalfSize);
	CVector Cp2 = NewPos + CVector(HalfSize, -HalfSize);
	CVector Cp3 = NewPos + CVector(-HalfSize, HalfSize);

	bool MayPass = (pMap->GetTile(Cp0.X, Cp0.Y)->IsPassable(Cp0, pMap, this) &&
					pMap->GetTile(Cp1.X, Cp1.Y)->IsPassable(Cp1, pMap, this) &&
					pMap->GetTile(Cp2.X, Cp2.Y)->IsPassable(Cp2, pMap, this) &&
					pMap->GetTile(Cp3.X, Cp3.Y)->IsPassable(Cp2, pMap, this));

	return MayPass;
}

bool CEntity::CanJump(CMap* pMap)
{
	return (!CanMove(CVector(0, 0.05 * HalfSize), pMap) && CanMove(CVector(0, -1 * HalfSize), pMap) && JumpTimer == 0);
}

CVector CEntity::GetEntityCorner(CVector MovDir)
{
	float ColX = 0, ColY = 0;

	if(MovDir.Y > 0)
		ColY = 1;
	else if(MovDir.Y < 0)
		ColY = -1;

	if(MovDir.X > 0)
		ColX = 1;
	else if(MovDir.X < 0)
		ColX = -1;

	return CVector(HalfSize * ColX, HalfSize * ColY);
}

void CEntity::OnMove(float fTime, CMap* pMap)
{
	if(Mov != CVector(0,0))
	{
		if(CanMove(Mov * fTime, pMap))
			Pos += Mov * fTime;
		else if(CanMove(CVector(Mov.X * fTime, 0), pMap)) {
			Mov.Y = 0;
			Pos += Mov * fTime;
		} else if(CanMove(CVector(0, Mov.Y * fTime), pMap)) {
			Mov.X = 0;
			Pos += Mov * fTime;
		}
		else Mov = CVector(0,0); //Stop the Entity
	}

	Mov *= pow(0.125f, fTime * 4);
	Mov += CVector(0, 9.81f * fTime * 4);

	if(AttackTimer > 0) {
		AttackTimer -= fTime;
		if(AttackTimer < 0) AttackTimer = 0.0f;
	}

	if(JumpTimer > 0) {
		JumpTimer -= fTime;
		if(JumpTimer < 0) JumpTimer = 0.0f;
	}
}

void CEntity::Attack(CMap *pMap)
{
	CVector AttackPoint = Pos + GetEntityCorner(FacingLeft ? CVector(-1,0) : CVector(1,0)) * 2.0f;
	CVector EAttackPointY = AttackPoint + CVector(0, ((AttackPoint.Y < 0.5f) ? 1 : -1));//Extended AttackPoint in Y direction
	CVector EAttackPointX = AttackPoint + CVector(((AttackPoint.X < 0.5f) ? -1 : 1), 0);

	PtrList<CEntity*> EntityList = pMap->GetTileEntityList(AttackPoint);
	PtrList<CEntity*> EEntityListY = pMap->GetTileEntityList(EAttackPointY);
	PtrList<CEntity*> EEntityListX = pMap->GetTileEntityList(EAttackPointX);

	PtrList<CEntity*> AttackList = PtrList<CEntity*>::join(EntityList, PtrList<CEntity*>::join(EEntityListY, EEntityListX));
	for(Uint16 i=0;i<AttackList.size();i++) {
		if(AttackList[i] == this) continue;
		AttackList[i]->OnHurt(pMap, this);
		if(AttackList[i]->Health == 0)
			pMap->RemoveEntity(pMap->GetEntityId(AttackList[i]));
	}
}

void CEntity::OnHurt(CMap *pMap, CEntity *pAttacker)
{
	Health--;
}

void CEntity::Jump(CVector JumpDirection, float DoubleJumpDelay, CMap *pMap)
{
	if(CanJump(pMap)) {
		Mov += JumpDirection;
		JumpTimer += DoubleJumpDelay;
	}
}

void CEntity::OnRender(SDL_Surface* pTarget, CMap* pMap)
{
	CVector_Ui8 Sprite = GetSprite(pMap);
	Uint8 SpriteX = Sprite.X;
	Uint8 SpriteY = Sprite.Y;

	gTileSet.RenderTile(SpriteX, SpriteY, pTarget, Pos.X-HalfSize, Pos.Y-HalfSize);

	if(AttackTimer > 0.25f)
		gTileSet.RenderTile(1,1,pTarget, Pos.X + (FacingLeft ? -HalfSize - 1 : HalfSize), Pos.Y - HalfSize);//if the entity is facing right, the Attack-indicator has to be on the Tile to the right which ENDS on the Entity's Left side(It begins 1 TileW to the left)
}
