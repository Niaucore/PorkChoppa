/*
 * CApp_Init.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

bool CApp::OnInit()
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		return false;

	if((pDisplay = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		return true;
	return true;
}

void CApp::OnExit()
{
	SDL_FreeSurface(pDisplay);
	SDL_Quit();
}
