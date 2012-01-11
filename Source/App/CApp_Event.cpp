/*
 * CApp_Event.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

void CApp::OnEvent(SDL_Event* pEvent) {
	switch (pEvent->type) {
	case SDL_QUIT:
		Running = false;
		break;
	case SDL_KEYDOWN:
		Map.GetEntity(AEntity)->Mov = CVector(1,0);
		break;
	}
}
