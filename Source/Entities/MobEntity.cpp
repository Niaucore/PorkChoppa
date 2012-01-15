/*
 * MobEntity.cpp
 *
 *  Created on: 15.01.2012
 *      Author: Tim
 */

#include "Entities/MobEntity.h"

void CMobEntity::OnMove(float fTime, CMap *pMap)//TODO:Do something
{
	CEntity::OnMove(fTime, pMap);

	//Execute Movement
	CVector ScheduledMovement;
	if(FacingLeft) {
		ScheduledMovement = CVector();
	} else {

	}

	if(DecisionTimer > 0) {
		DecisionTimer -= fTime;
		if(DecisionTimer < 0) {
			DecisionTimer = 0;
		}
	} else { //Make a Movement Decision

	}
}
