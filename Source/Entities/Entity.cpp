/*
 * Entity.cpp
 *
 *  Created on: 11.01.2012
 *      Author: Tim
 */

#include "Entities/Entity.h"

Uint8 CEntity::GetSprite(CMap* pMap)
{
	return SpriteId;
}

bool CEntity::CanMove(CVector Movement, CMap* pMap)
{
	return true;
}

void CEntity::OnMove(float fTime, CMap* pMap)
{
	if(Mov != CVector(0,0))
	{
		if(CanMove(Mov, pMap))
			Pos += Mov * fTime;
	}
}
