/*
 * Map.cpp
 *
 *  Created on: 11.01.2012
 *      Author: 06hofmann-sebas
 */

#include "Map/Map.h"

CMap::CMap()
{
}

bool CMap::OnInit(Uint16 Width, Uint16 Height)
{
	MapW = Width;
	MapH = Height;
	for(Uint16 i=0;i<MapW*MapH;i++)
		TileList.Push(CTile::EmptyTile);
	return true;
}

void CMap::OnExit()
{
	for(Uint16 i=0;i<TileList.size();i++)
		//TileList[i] = NULL;
	TileList.clear();
}

void CMap::OnMove(float fTime)
{

}

void CMap::OnRender(SDL_Surface* pTarget)
{
	for(Uint16 Y=0;Y<MapH;Y++)
		for(Uint16 X=0;X<MapW;X++)
			gTileSet.RenderTile(TileList[Y*MapW+X]->GetTileId(CVector(X,Y)/*, this*/), pTarget, X, Y);
}


