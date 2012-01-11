/*
 * App.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

CApp::CApp() {
	pDisplay = NULL;
	Running = true;
}

int CApp::OnExecute() {
	if (!OnInit())
		return -1;

	SDL_Event Event;

	while (Running) {
		while (SDL_PollEvent(&Event))
			OnEvent(&Event);
		OnRender();
	}

	return 1;
}
