/*
 * CApp_Render.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

void CApp::OnRender() {
	SDL_FillRect(pDisplay, NULL, SDL_MapRGB(pDisplay->format, 0, 0, 0));

	Map.OnRender(pDisplay);

	SDL_Flip(pDisplay);
}
