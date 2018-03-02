#include "maingame.hpp"
#include "../core/graphics/renderer.hpp"
#include "../core/utils/popup.hpp"
#include "../appbase.hpp"
#include "../eobjects/gameobject.hpp"
//#include "../collections/images/image.hpp"
#include "../collections/images/imagecollection.hpp"
#include "resources.hpp"

namespace Game {

	MainGame::MainGame(AppBase *base): _base(base){
    }

    MainGame::~MainGame(){
    }

    Core::ReturnStatus::Enum MainGame::reload(){
		_base->playerState.load();
		return Game::resources.loadArea(_base->playerState.getArea(), _base);

        return Core::ReturnStatus::Success;
    }

	Core::ReturnStatus::Enum MainGame::loop(){
		SDL_Event event;
		bool quit = false;
		
		EObjects::GameObject *newGO = EObjects::GameObject::newObject("obj01");
		Collections::Images::Image imageObj = Collections::Images::Image(_base);
		Collections::Images::Image imageObj02 = Collections::Images::Image(_base);
		Collections::Images::Image mage01 = Collections::Images::Image(_base);
		Collections::Images::Image mage02 = Collections::Images::Image(_base);
		Collections::Images::Image mage03 = Collections::Images::Image(_base);
		Collections::Images::Image mage05 = Collections::Images::Image(_base);
		Collections::Images::Image mage06 = Collections::Images::Image(_base);
		Collections::Images::Image soldier01 = Collections::Images::Image(_base);
		Collections::Images::Image test_area = Collections::Images::Image(_base);
		Collections::Images::ImageCollection mage07 = Collections::Images::ImageCollection(_base);

		if (test_area.loadImage("test_area.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}

		if (mage01.loadImage("mage01_01.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}
		if (mage03.loadImage("mage01_stand_03.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}
		if (mage02.loadImage("mage01_stand_02.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}
		if (mage05.loadImage("mage01_stand_05.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}
		if (mage06.loadImage("mage01_stand_06.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}

		if (mage07.loadImage("thomas.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}

		if (imageObj.loadImage("dagos_charset.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}

		if (imageObj02.loadImage("stand_final0.png") != Core::ReturnStatus::Success){
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}

		if (soldier01.loadImage("main_char_walking01.png") != Core::ReturnStatus::Success) {
			Core::ErrorHandler::errorOutput();
			Core::Utils::ShowPopUP(&_base->mainWindow, "Error!", "erro! =(", Core::Utils::PopUP_Type::Error);
			_base->playerState.setGameState(Core::GameState::Exit);
			return Core::ReturnStatus::Failed;
		}



		SDL_Rect mage;
		mage.x = 0;
		mage.y = 32;
		mage.w = 32;
		mage.h = 32;
		mage07.addFrame(1, mage);
		
        /* Enquanto não houver comando para sair do jogo */
        while (!quit)
        {
            /* Checa novos eventos */
            while(SDL_PollEvent(&event))
            {
				// Apaga todas as imagens da tela
				_base->mainWindow.renderer.setDrawColor(0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
				_base->mainWindow.renderer.clear();

				_base->mainWindow.mainView.setViewport();

                switch (event.type)
                {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym){
                            case SDLK_ESCAPE:
                                quit = true;
                                break;
                        }
                        break;


                }

				SDL_Rect test;
				
				test.x = 0;
				test.y = 0;
				test.w = _base->mainWindow.surfaceSize.getW();
				test.h = _base->mainWindow.surfaceSize.getH();
				_base->mainWindow.renderer.setDrawColor(0x11,0x22,0x33, SDL_ALPHA_OPAQUE);
				_base->mainWindow.renderer.fillRect(test);

				test.x = _base->mainWindow.surfaceSize.getW()-1;
				test.y = 0;
				test.w = _base->mainWindow.surfaceSize.getW();
				test.h = _base->mainWindow.surfaceSize.getH();
				_base->mainWindow.renderer.setDrawColor(0x55,0x00,0x44, SDL_ALPHA_OPAQUE);
				_base->mainWindow.renderer.fillRect(test);

				test.x = 0;
				test.y = _base->mainWindow.surfaceSize.getH()-1;
				test.w = _base->mainWindow.surfaceSize.getW();
				test.h = _base->mainWindow.surfaceSize.getH();
				_base->mainWindow.renderer.setDrawColor(0x55,0x00,0x44, SDL_ALPHA_OPAQUE);
				_base->mainWindow.renderer.fillRect(test);

				test.x = 0;
				test.y = 0;
				test.w = 640;
				test.h = 480;
				test_area.draw(NULL, &test);
				test.x= 0;
				test.y = 0;
				test.w = 90;
				test.h = 220;
				imageObj.draw(NULL, &test);
				test.x= 200;
				test.y = 0;
				test.w = 36;
				test.h = 55;
				imageObj02.draw(NULL, &test);
				test.x= 200;
				test.y = 200;
				test.w = 32;
				test.h = 32;
				mage01.draw(NULL, &test);
				test.x += 40;
				mage02.draw(NULL, &test);
				test.x -= 80;
				mage03.draw(NULL, &test);
				test.x -= 40;
				mage05.draw(NULL, &test);
				test.x -= 40;
				mage06.draw(NULL, &test, true);
				test.x -= 40;
				mage07.draw(1, &test, true);

				SDL_Rect sold01;
				sold01.x = 0;
				sold01.y = 0;
				sold01.w = 30;
				sold01.h = 25;
				test.w = 30;
				test.h = 25;
				test.x = 400;
				test.y = 102;

				soldier01.draw(&sold01, &test);
				Game::resources.update();


				_base->mainWindow.renderer.update();
            }
        }

        _base->playerState.setGameState(Core::GameState::Exit);

		return Core::ReturnStatus::Success;
    }

}
