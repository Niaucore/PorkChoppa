/*
 * CApp_Render.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

void CApp::OnRender() {
	SDL_FillRect(pDisplay, NULL, SDL_MapRGB(pDisplay->format, 0, 0, 0));

	CSurface::Blit(pDisplay, pBackground, 0, 0);

	Map.OnRender(pDisplay);

	char FpsString[20];
	itoa((int)FPS, FpsString, 10);
	int i=0;
	while(FpsString[i] != '\0') {
		gTileSet.RenderTile(FpsString[i]-'0',15,pDisplay,0+i,0);
		i++;
	}

	SDL_Flip(pDisplay);
}
