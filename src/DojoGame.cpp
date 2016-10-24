#include "DojoGame.h"

#include "Level.h"

#include <random>

using namespace Dojo;

DojoGame::DojoGame() :
	Game("Dojo Game", 0, 0, Dojo::DO_LANDSCAPE_RIGHT, 1.f / 60.f, 1.f / 15.f, false)
{

}

void DojoGame::onBegin() {
	//load common res
	addPrefabMeshes();
	addFolder("data");

	setState(make_shared<Level>(self));
}
