/*
 * Input.h
 *
 *  Created on: 13.01.2012
 *      Author: Tim
 */

#pragma once /* INPUT_H_ */

#include <SDL/SDL.h>

class CKey
{
private:
	SDLKey sym;
public:
	CKey(SDLKey key) : sym(key) { }

	bool IsPressed();

	static CKey Up;
	static CKey Down;
	static CKey Left;
	static CKey Right;
	static CKey Space;
	static CKey X;
};

extern class CInput
{
public:
	bool Pressed(CKey key);
} Input;
