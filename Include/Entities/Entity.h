/*
 * Entity.h
 *
 *  Created on: 11.01.2012
 *      Author: Tim
 */

#pragma once /* ENTITY_H_ */

class CEntity;

#include <SDL/SDL.h>

#include "Tile/TileSet.h"

#include "Helper/CVector.h"

#include "Map/Map.h"

class CEntity
{
private:
	CVector_Ui8 Sprite;
	float HalfSize;

public:
	CVector Pos;
	CVector Mov;//Velocity
	float JumpTimer;

public:
	CEntity(Uint8 SpriteX, Uint8 SpriteY, float Half_Size) : Sprite(CVector_Ui8(SpriteX, SpriteY)), HalfSize(Half_Size), JumpTimer(0.0f) { }
	virtual ~CEntity() { }

	virtual CVector_Ui8 GetSprite(CMap* pMap);

	virtual CVector GetEntityCorner(CVector MovementDirection);

	virtual bool CanMove(CVector Movement, CMap* pMap);

	virtual bool CanJump(CMap* pMap);

	virtual void OnMove(float fTime, CMap* pMap);

	virtual void OnRender(SDL_Surface* pTarget, CMap* pMap);
};
