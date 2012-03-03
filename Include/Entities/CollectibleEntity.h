/*
 * CollectibleEntity.h
 *
 *  Created on: 03.03.2012
 *      Author: Tim
 */

#pragma once /* COLLECTIBLEENTITY_H_ */

#include "Entity.h"

class CollectibleEntity : public CEntity {
private:
	float VanishTimer;
	bool IsCollected;

public:
	CollectibleEntity(Uint8 SpriteX, Uint8 SpriteY, float Half_Size, CVector InitialPos) : CEntity(SpriteX, SpriteY, Half_Size, InitialPos), VanishTimer(0.0f), IsCollected(false) { }
	~CollectibleEntity();

	CVector_Ui8 GetSprite(CMap* pMap);

	void OnMove(float fTime, CMap* pMap);

	bool IsCollectible();
	void OnCollect(CEntity* pCollector, CMap* pMap);
};

