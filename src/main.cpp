
#include "DojoGame.h"

int main(int argc, char** argv) {

	auto& p = Dojo::Platform::create();
	p.run(make_unique<DojoGame>());

	return 0;
}

#ifdef PLATFORM_WIN32

#include <dojo/dojo_win_header.h>

int __stdcall WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd ) {
	return main(0, nullptr);
}

#endif