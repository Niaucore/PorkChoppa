/*
 * CApp_OnMove.cpp
 *
 *  Created on: 12.01.2012
 *      Author: Tim
 */

#include "App/App.h"

void CApp::OnMove(float fTime)
{
	Map.GetEntity(AEntity)->Mov *= pow(0.125f, fTime * 4);
	Map.GetEntity(AEntity)->Mov += CVector(0, 9.81f * fTime * 4);

	if(Input.Pressed(CKey::Left) && Map.GetEntity(AEntity)->Mov.X > -3)
		Map.GetEntity(AEntity)->Mov += CVector(-40 * fTime, 0);
	if(Input.Pressed(CKey::Right) && Map.GetEntity(AEntity)->Mov.X < 3)
		Map.GetEntity(AEntity)->Mov += CVector(40 * fTime, 0);

	if(Input.Pressed(CKey::Space) &&
			Map.GetEntity(AEntity)->CanJump(&Map)) {
		Map.GetEntity(AEntity)->Mov += CVector(0, -20);
		Map.GetEntity(AEntity)->JumpTimer += 0.75f;
	}

	Map.OnMove(fTime);
}
