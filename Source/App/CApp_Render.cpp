/*
 * CApp_Render.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

void CApp::OnRender()
{
	SDL_FillRect(pDisplay, NULL, SDL_MapRGB(pDisplay->format, 0, 0, 0));

	if (Map.GameOver()) {
		Sint16 X = (pDisplay->w - pGameOver->w) / 2;
		Sint16 Y = (pDisplay->h - pGameOver->h) / 2;
		CSurface::Blit(pDisplay, pGameOver, X, Y);
	} else {

		Map.OnRender(pDisplay);

		char FpsString[20];
		itoa((int) FPS, FpsString, 10);
		int i = 0;
		while(FpsString[i] != '\0') {
			gTileSet.RenderTile(FpsString[i] - '0', 15, pDisplay, 0 + i, 0);
			i++;
		}

		itoa((int) Map.RemainingPoints(), FpsString, 10);
		i = 0;
		int len = strlen(FpsString);
		while(FpsString[i] != '\0') {
			gTileSet.RenderTile(FpsString[i] - '0', 15, pDisplay, Map.GetW() - len + i, 0);
			i++;
		}
	}

	SDL_Flip(pDisplay);
}
