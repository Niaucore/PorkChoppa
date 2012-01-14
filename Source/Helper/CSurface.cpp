/*
 * CSurface.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "Helper/CSurface.h"

SDL_Surface* CSurface::Load(const char* FileName) {
	SDL_Surface* pTemp = SDL_LoadBMP(FileName);
	if (!pTemp)
		return NULL;
	SDL_Surface* pRet = SDL_DisplayFormat(pTemp);
	SDL_FreeSurface(pTemp);
	return pRet;
}

void CSurface::Blit(SDL_Surface* pDst, SDL_Surface* pSrc, Sint16 X, Sint16 Y,
		Sint16 Xsrc, Sint16 Ysrc, Uint16 Wsrc, Uint16 Hsrc) {
	if (!Wsrc)
		Wsrc = pSrc->w;
	if (!Hsrc)
		Hsrc = pSrc->h;

	SDL_Rect DstRect = { X, Y, 0, 0 };
	SDL_Rect SrcRect = { Xsrc, Ysrc, Wsrc, Hsrc };

	SDL_BlitSurface(pSrc, &SrcRect, pDst, &DstRect);
}
