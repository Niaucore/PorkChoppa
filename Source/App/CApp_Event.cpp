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
	case SDL_ACTIVEEVENT:
		if(pEvent->active.gain == 0)
			Pause = true;
		else Pause = false;
		break;
	}
}
