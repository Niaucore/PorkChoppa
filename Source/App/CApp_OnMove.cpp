/*
 * CApp_OnMove.cpp
 *
 *  Created on: 12.01.2012
 *      Author: Tim
 */

#include "App/App.h"

void CApp::OnMove(float fTime)
{

	if(Input.Pressed(CKey::Left) && Map.GetPlayer()->Vel.X > -3) {
		Map.GetPlayer()->Vel += CVector(-40 * fTime, 0);
		Map.GetPlayer()->FacingLeft = true;
	}
	if(Input.Pressed(CKey::Right) && Map.GetPlayer()->Vel.X < 3) {
		Map.GetPlayer()->Vel += CVector(40 * fTime, 0);
		Map.GetPlayer()->FacingLeft = false;
	}

	if(Input.Pressed(CKey::Space)) {
		Map.GetPlayer()->Jump(CVector(0, -20), &Map);
	}

	Map.OnMove(fTime);
}
