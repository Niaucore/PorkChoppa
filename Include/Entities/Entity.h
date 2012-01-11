/*
 * Entity.h
 *
 *  Created on: 11.01.2012
 *      Author: Tim
 */

#pragma once /* ENTITY_H_ */

class CEntity;

#include <SDL/SDL.h>

#include "Helper/CVector.h"

#include "Map/Map.h"

class CEntity
{
private:
	Uint8 SpriteId;

public:
	CVector Pos;
	CVector Mov;

public:
	CEntity(Uint8 Sprite) : SpriteId(Sprite) { }
	virtual ~CEntity() { }

	virtual Uint8 GetSprite(CMap* pMap);

	virtual bool CanMove(CVector Movement, CMap* pMap);

	virtual void OnMove(float fTime, CMap* pMap);
};
