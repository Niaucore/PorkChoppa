/*
 * Entity.h
 *
 *  Created on: 11.01.2012
 *      Author: Tim
 */

#pragma once /* ENTITY_H_ */

class CEntity;

#include <SDL/SDL.h>

#include "math.h"

#include "Tile/TileSet.h"

#include "Helper/CVector.h"

#include "Map/Map.h"

class CEntity
{
protected:
	CVector_Ui8 Sprite;
	float HalfSize;

public:
	CVector Pos;
	CVector Mov;//Scheduled Movement, which is consistent due to Pixel-Perfect Collision Detection
	CVector Vel;//Velocity
	bool FacingLeft; //Points in the general direction the entity is facing

	Uint8 Health;
	float AttackTimer;

	int Points;

public:
	CEntity(Uint8 SpriteX, Uint8 SpriteY, float Half_Size, CVector InitialPos, Uint8 InitialHealth = 3) : Sprite(CVector_Ui8(SpriteX, SpriteY)), HalfSize(Half_Size), Pos(InitialPos), FacingLeft(false), Health(InitialHealth), AttackTimer(0.0f), Points(0) { }
	virtual ~CEntity() { }

	virtual CVector_Ui8 GetSprite(CMap* pMap);

	virtual CVector GetEntityCorner(CVector MovementDirection);

	virtual void Jump(CVector JumpDirection, CMap* pMap);

	virtual bool CanMove(CVector Movement, CMap* pMap);

	virtual void Attack(CMap* pMap);

	virtual void OnHurt(CMap* pMap, CEntity* pAttacker);

	virtual bool CanJump(CMap* pMap);

	virtual void OnMove(float fTime, CMap* pMap);

	virtual void OnRender(SDL_Surface* pTarget, CMap* pMap);

	virtual bool IsCollectible();
	virtual void OnCollect(CEntity* pCollector, CMap* pMap);
};

#include "Entities/MobEntity.h"
#include "Entities/CollectibleEntity.h"
