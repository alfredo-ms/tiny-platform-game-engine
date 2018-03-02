#ifndef __AppBase
#define __AppBase

#include "core/ibase.hpp"
#include "core/graphics/window.hpp"
#include "core/graphics/imagetypesupport.hpp"
#include "game/playerstate.hpp"
#include <memory>




// classe utilizada para administrar as funções básicas do jogo
class AppBase: public Core::IBase {
public:
	~AppBase();
	virtual std::string getComponentID(void) const { return "Core::Manager"; };
	Core::ReturnStatus::Enum init();
	void close();
	int showCursor(bool show);

	Core::Graphics::Window mainWindow;
	Core::Graphics::ImageTypeSupport *imgSupport;
	Game::PlayerState playerState;
	
	static AppBase *getInstance();

private:
	AppBase();
};

#endif // __AppBase
