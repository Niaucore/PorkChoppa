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

	float fTime = 0.0f;
	Uint32 t1,t2;

	while (Running) {
		t1 = SDL_GetTicks();
		while (SDL_PollEvent(&Event))
			OnEvent(&Event);
		OnRender();
		OnMove(fTime);
		t2 = SDL_GetTicks();
		fTime = (float)(t2-t1)/1000.0f;
	}

	return 1;
}
