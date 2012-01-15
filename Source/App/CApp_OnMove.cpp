/*
 * CApp_OnMove.cpp
 *
 *  Created on: 12.01.2012
 *      Author: Tim
 */

#include "App/App.h"

void CApp::OnMove(float fTime)
{

	if(Input.Pressed(CKey::Left) && Map.GetEntity(AEntity)->Mov.X > -3) {
		Map.GetEntity(AEntity)->Mov += CVector(-40 * fTime, 0);
		Map.GetEntity(AEntity)->FacingLeft = true;
	}
	if(Input.Pressed(CKey::Right) && Map.GetEntity(AEntity)->Mov.X < 3) {
		Map.GetEntity(AEntity)->Mov += CVector(40 * fTime, 0);
		Map.GetEntity(AEntity)->FacingLeft = false;
	}

	if(Input.Pressed(CKey::Space)) {
		Map.GetEntity(AEntity)->Jump(CVector(0, -20), 0.75, &Map);
	}

	if(Input.Pressed(CKey::X) && Map.GetEntity(AEntity)->AttackTimer == 0) {
		Map.GetEntity(AEntity)->Attack(&Map);
		Map.GetEntity(AEntity)->AttackTimer += 0.5f;
	}

	Map.OnMove(fTime);
}
