/*
 * MobEntity.cpp
 *
 *  Created on: 15.01.2012
 *      Author: Tim
 */

#include "Entities/MobEntity.h"

void CMobEntity::MakeMovementDecision()
{
	DecisionTimer = 3;
	Uint8 Decision = rand() % 2;
	if(Decision) FacingLeft = true;
	else FacingLeft = false;
}

void CMobEntity::OnMove(float fTime, CMap* pMap)//TODO:Do something
{
	//Execute Movement
	CVector ScheduledMovement;
	if(FacingLeft) {
		ScheduledMovement = CVector(-4,50);
	} else {
		ScheduledMovement = CVector(4 ,50);
	}

	if(!CanMove(ScheduledMovement, pMap))
		MakeMovementDecision();
	else Mov += ScheduledMovement * fTime;

	if(DecisionTimer > 0) {
		DecisionTimer -= fTime;
	} else {
		MakeMovementDecision();
	}

	CEntity::OnMove(fTime, pMap);
}
