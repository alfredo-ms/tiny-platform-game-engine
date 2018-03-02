#include <iostream>
#include <memory>
#include "main.hpp"
#include "core/utils/popup.hpp"
#include "game/mainmenu.hpp"
#include "game/maingame.hpp"
#include "game/intro.hpp"


Main::Main() {
}

Main::~Main(){
}

Core::ReturnStatus::Enum Main::init(){
	// inicializa a variável com as funções básicas da engine
	base = AppBase::getInstance();

    /***** funções relacionadas à inicialização da engine ****************************/
	if (base->init() != Core::ReturnStatus::Success)
        return Core::ReturnStatus::Failed;

    /***** funções relacionadas à inicialização da janela e seus componentes *********/
	base->showCursor(false);
	base->mainWindow.setTitle("Game Engine v0.01");
	base->mainWindow.setScaleSystem(Core::Video::ScaleType::NearestAspectRatio_WithAllScreen);
	base->mainWindow.internalResolution.set(400, 240);
    base->mainWindow.setFullScreen(true);
	base->mainWindow.useDesktopResolution(true);

    if (base->mainWindow.create() != Core::ReturnStatus::Success)
        return Core::ReturnStatus::Failed;
	
	if (base->imgSupport->init() != Core::ReturnStatus::Success)
		return Core::ReturnStatus::Failed;

    //render.getRender().setFramerateLimit(60);

    return Core::ReturnStatus::Success;
}

int Main::run(){
	Core::ReturnStatus::Enum returnedStatus = Core::ReturnStatus::Success;
    std::string currentModule = "";
    std::shared_ptr<Game::Intro> intro;
    std::shared_ptr<Game::MainGame> mainGame;
    std::shared_ptr<Game::MainMenu> mainMenu;

    while (base->playerState.gameState() != Core::GameState::Exit){
        switch (base->playerState.gameState()){
			// Game introduction
            case Core::GameState::Intro:
                intro = std::make_shared<Game::Intro>();
                currentModule = intro->getComponentID();
                returnedStatus = intro->load();
                intro.reset();
                base->playerState.setGameState(Core::GameState::MainMenu);
                break;
			// Game main menu loop
			case Core::GameState::MainMenu:
				mainMenu = std::make_shared<Game::MainMenu>();
				currentModule = mainMenu->getComponentID();
				returnedStatus = mainMenu->load();
				mainMenu.reset();
				base->playerState.setGameState(Core::GameState::MainGame);
				break;
			// The game loop
            case Core::GameState::MainGame:
                mainGame = std::make_shared<Game::MainGame>(base);
                currentModule = mainGame->getComponentID();
                returnedStatus = mainGame->reload();
				if (returnedStatus == Core::ReturnStatus::Success)
					returnedStatus = mainGame->loop();
                mainGame.reset();
                break;
        }

        if (returnedStatus != Core::ReturnStatus::Success){
            Core::ErrorHandler::errorOutput();
            std::ostringstream messageStream;
            messageStream<<"An error has occurred in the \""<<currentModule<<"\" module! Please, verify the file \""<<__ERRORLOG_FILE_NAME<<"\" for more details.";
            Core::Utils::ShowPopUP(&base->mainWindow, "Error!", messageStream.str(), Core::Utils::PopUP_Type::Error);

            return 1;
        }


    }

    return 0;
}

int main (int argc, char ** argv)
{
    Main objMain;
    if (objMain.init() != Core::ReturnStatus::Success){
        Core::ErrorHandler::errorOutput();
        std::ostringstream messageStream;
        messageStream<<"An error has occurred in the \"Main.init()\" function! Please, verify the file \""<<__ERRORLOG_FILE_NAME<<"\" for more details.";
        Core::Utils::ShowPopUP(nullptr, "Error!", messageStream.str(), Core::Utils::PopUP_Type::Error);

        return 1;
    }

    return objMain.run();
}
