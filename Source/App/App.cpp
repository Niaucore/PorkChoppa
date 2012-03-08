/*
 * App.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

CApp::CApp() {
	pDisplay = pGameOver = NULL;
	Running = true;
	Pause = true;

	m_fTime = 0;
	GameOverCheckTime = 0;
	FPS = 0;
}

int CApp::OnExecute(const char* LevelName) {
	if (!OnInit(LevelName))
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
		if(Pause) fTime = 0;
		else fTime = (float)(t2-t1)/1000.0f;

		m_fTime += fTime;

		if(fTime > 0 && m_fTime > 0.2f) {
			m_fTime -= 0.2f;
			FPS = 1 / fTime;
		}
	}

	return 1;
}
