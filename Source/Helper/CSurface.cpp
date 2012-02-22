/*
 * CSurface.cpp
 *
 *  Created on: 07.12.2011
 *      Author: 06graefje-tim
 */

#include "Helper/CSurface.h"

Uint32 ReadPixel(SDL_Surface *surface, int x, int y);
void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

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

//From SDLtutorials.com
SDL_Surface* ScaleSurface(SDL_Surface *Surface, Uint16 Width, Uint16 Height)
{
    if(!Surface || !Width || !Height)
        return 0;

    SDL_Surface *_ret = SDL_CreateRGBSurface(Surface->flags, Width, Height, Surface->format->BitsPerPixel,
        Surface->format->Rmask, Surface->format->Gmask, Surface->format->Bmask, Surface->format->Amask);

    double    _stretch_factor_x = (static_cast<double>(Width)  / static_cast<double>(Surface->w)),
        _stretch_factor_y = (static_cast<double>(Height) / static_cast<double>(Surface->h));

    for(Sint32 y = 0; y < Surface->h; y++)
        for(Sint32 x = 0; x < Surface->w; x++)
            for(Sint32 o_y = 0; o_y < _stretch_factor_y; ++o_y)
                for(Sint32 o_x = 0; o_x < _stretch_factor_x; ++o_x)
                    DrawPixel(_ret, static_cast<Sint32>(_stretch_factor_x * x) + o_x,
                        static_cast<Sint32>(_stretch_factor_y * y) + o_y, ReadPixel(Surface, x, y));

    return _ret;
}

/*
 * Return the pixel value at (x, y)
 * NOTE: The surface must be locked before calling this!
 * From SDL-Documentation
 */
Uint32 ReadPixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

/*
 * Set the pixel at (x, y) to the given value
 * NOTE: The surface must be locked before calling this!
 * From SDL-Documentation
 */
void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}
