#pragma once

#include "common_header.h"

#include "Level.h"

class DojoGame :
	public Dojo::Game,
	public Dojo::ResourceGroup {
public:

	DojoGame();

private:

	virtual void onBegin() override;

	virtual void onLoop(float dt) override {

	}

	virtual void onEnd() override {

	}

	//----- immediate substate events
	virtual void onStateBegin() override {

	}

	virtual void onStateLoop(float dt) override {

	}

	virtual void onStateEnd() override {

	}

private:
private:
};
