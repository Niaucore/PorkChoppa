/*
 * CollectibleEntity.cpp
 *
 *  Created on: 03.03.2012
 *      Author: Tim
 */

#include "Entities/CollectibleEntity.h"

CollectibleEntity::~CollectibleEntity()
{
}

CVector_Ui8 CollectibleEntity::GetSprite(CMap* pMap)
{
	if(IsCollected) return Sprite + CVector_Ui8(1,0);
	return Sprite;
}

void CollectibleEntity::OnMove(float fTime, CMap* pMap)
{
	CEntity::OnMove(fTime, pMap);

	if(IsCollected) {
		VanishTimer -= fTime;
		if(VanishTimer <= 0) {
			pMap->RemoveEntity(pMap->GetEntityId(this));
		}
	}
}

bool CollectibleEntity::IsCollectible()
{
	return true;
}

void CollectibleEntity::OnCollect(CEntity* pCollector, CMap* pMap)
{
	if(IsCollected) return;

	++pCollector->Points;

	IsCollected = true;
	VanishTimer = 0.125f;
}





