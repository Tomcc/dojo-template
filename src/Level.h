#pragma once

#include "common_header.h"

class DojoGame;

class Level :
	public GameState,
	public InputDeviceListener,
	public InputSystemListener {
public:

	Level(DojoGame& game);

	virtual ~Level();

	virtual void onDeviceConnected(InputDevice& j) override;
	void onDeviceDisconnected(InputDevice& j) override;

	void onButtonReleased(InputDevice& j, int action) override;

	void onLoop(float dt) override;
private:
	virtual void onBegin() override;
	virtual void onEnd() override;

	Unique<Object> _makeMainCamera(uint32_t w, uint32_t h);
};
