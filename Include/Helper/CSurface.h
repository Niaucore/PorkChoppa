/*
 * CSurface.h
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#pragma once /* CSURFACE_H_ */

#include <SDL/SDL.h>

namespace CSurface {
SDL_Surface* Load(const char* FileName);

void Blit(SDL_Surface* pDst, SDL_Surface* pSrc, Sint16 X, Sint16 Y,
		Sint16 Xsrc = 0, Sint16 Ysrc = 0, Uint16 Wsrc = 0, Uint16 Hsrc = 0);
}

SDL_Surface* ScaleSurface(SDL_Surface *Surface, Uint16 Width, Uint16 Height);
