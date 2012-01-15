/*
 * MobEntity.h
 *
 *  Created on: 15.01.2012
 *      Author: Tim
 */

#pragma once /* MOBENTITY_H_ */

#include "Entities/Entity.h"

class CMobEntity : public CEntity
{
protected:
	float DecisionTimer;

public:
	CMobEntity(CVector_Ui8 Tile, float halfsize, CVector InitialPos, Uint8 InitialHealth) : CEntity(Tile.X, Tile.Y, halfsize, InitialPos, 10), DecisionTimer(0.0f) { }

	void OnMove(float fTime, CMap *pMap);
};
