/*
 * CApp_OnMove.cpp
 *
 *  Created on: 12.01.2012
 *      Author: Tim
 */

#include "App/App.h"

void CApp::OnMove(float fTime)
{
	if(Map.GameOver())
		return;

	if(Input.Pressed(CKey::Reset)) {
		Map.OnExit();
		Map.LoadMapFromFile(Map.GetLevelName());
	}

	if(Input.Pressed(CKey::Left) && Map.GetPlayer()->Vel.X > -Map.GetMaxSpeed()) {
		Map.GetPlayer()->Vel += CVector(-Map.GetMoveAccl() * fTime, 0);
		Map.GetPlayer()->FacingLeft = true;
	}
	if(Input.Pressed(CKey::Right) && Map.GetPlayer()->Vel.X < Map.GetMaxSpeed()) {
		Map.GetPlayer()->Vel += CVector(Map.GetMoveAccl() * fTime, 0);
		Map.GetPlayer()->FacingLeft = false;
	}

	if(Input.Pressed(CKey::Space)) {
		Map.GetPlayer()->Jump(CVector(0, -Map.GetJumpAccl()), &Map);
	}

	Map.OnMove(fTime);

	if(GameOverCheckTime > 0.2f) {
		Map.UpdateNumbers();
		GameOverCheckTime = 0;
	} else GameOverCheckTime += fTime;
}
