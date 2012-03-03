/*
 * Main.cpp
 *
 *  Created on: 30.11.2011
 *      Author: 06graefje-tim
 */

#include "App/App.h"

int main(int argc, char** argv) {
	const char* LevelName = (argc > 1) ? argv[1] : "Maps/1.map.txt";
	CApp App;
	return App.OnExecute(LevelName);
}
