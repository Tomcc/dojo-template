#include "Level.h"

#include "DojoGame.h"

Level::Level(DojoGame& game) 
	: GameState(game) {

}

Level::~Level() {

}

Unique<Object> Level::_makeMainCamera(uint32_t w, uint32_t h) {
	DEBUG_ASSERT(w > 0 and w % 2 == 0, "Invalid width");
	DEBUG_ASSERT(h > 0 and h % 2 == 0, "Invalid height");

	auto r = w / (float)h;

	auto cameraDir = Vector::NegativeUnitZ;
	auto obj = make_unique<Object>(self, -cameraDir);
	auto& viewport = obj->addComponent([&] {
		auto viewport = make_unique<Viewport>(*obj, Vector(11 * r, 11), Color::Blue, 0._deg, 0.01f, 100.f);
		setViewport(*viewport);
		return viewport;
	}());

	obj->addComponent(make_unique<SoundListener>(*obj, 10.f));

	return obj;
}

void Level::onBegin() {

	auto& platform = Platform::singleton();
	//start the storage system
	auto& config = platform.getUserConfiguration();
	
	Platform::singleton().getSoundManager().setMasterVolume(config.getNumber("masterVolume", 0.2f));

	addSubgroup((DojoGame&) getGame()); 

	loadResources();

	auto w = platform.getUserConfiguration().getInt("internalWidth", platform.getWindowWidth());
	auto h = platform.getUserConfiguration().getInt("internalHeight", platform.getWindowHeight());
	//TODO this could get different w/h to get downscaled in software
	auto& camera = addChild(_makeMainCamera(w, h));

	platform.getInput().addListener(self);

	//add all existing devices
	auto& devices = platform.getInput().getDeviceList();

	for (auto&& d : devices) {
		onDeviceConnected(*d);
	}
}

void Level::onEnd() {
	Platform::singleton().getInput().removeListener(self);
	Platform::singleton().getRenderer().removeAllRenderables();
	Platform::singleton().getSoundManager().stopAllSounds();
	Platform::singleton().getSoundManager().stopMusic();

	for (auto&& d : Platform::singleton().getInput().getDeviceList()) {
		d->removeListener(self);
	}
}

//----- immediate substate events

void Level::onLoop(float dt) {
	updateChilds(dt);
}

void Level::onButtonReleased(InputDevice& j, int action) {

}

void Level::onDeviceConnected(InputDevice& j) {
	j.addListener(self);
}

void Level::onDeviceDisconnected(InputDevice& j) {
}
