/*
 * Input.cpp
 *
 *  Created on: 13.01.2012
 *      Author: Tim
 */

#include "Input/Input.h"

CKey CKey::Left(SDLK_LEFT);
CKey CKey::Right(SDLK_RIGHT);
CKey CKey::Up(SDLK_UP);
CKey CKey::Down(SDLK_DOWN);
CKey CKey::Space(SDLK_SPACE);
CKey CKey::X(SDLK_x);

CInput Input;

bool CInput::Pressed(CKey key)
{
	return key.IsPressed();
}

bool CKey::IsPressed()
{
	Uint8* KeyState = SDL_GetKeyState(NULL);
	return (bool)(KeyState[sym]);
}
