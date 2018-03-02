#include "resources.hpp"
#include "../common/pugixml/pugixml.hpp"
#include "../core/utils/popup.hpp"
#include "../eobjects/components/graphics/simplepicture.hpp"
#include "../eobjects/components/position.hpp"

#define __COMMON_ID "common-id:"
#define __UNIQUE_ID "unique-id:"

namespace Game {

    Resources::Resources(){
    }

    Resources::~Resources(){
		clear();
    }

	void Resources::notifyXmlLoadError(std::string message){
		message = "Error to load XML file: " + message;
		addErrorMessage(message);
	}

	Core::ReturnStatus::Enum Resources::loadArea(std::string area_file, AppBase *appBase){
		// Limpa dados alocados anteriormente
		clear();

		// Variaveis relacionadas ao carregamento do tileset
		std::map<std::string, Collections::Images::ImageCollection*>::iterator tilesetList_it;
		std::string tilesetName;
		std::string tilesetSource;
		Core::integer_id tileQuantity = 0;
		Core::integer_id tileID = 0;
		SDL_Rect tileRect;
		tileRect.x = 0;
		tileRect.y = 0;
		tileRect.h = 0;
		tileRect.w = 0;

		//Variaveis relacioadas ao carregamento do mapa
		std::string mapSource;
		std::string mapName;
		Core::Layer::Enum mapLayer;

		// Variaveis de uso geral
		std::stringstream stringStreamValue;
		Core::integer_id objectCounter = 0;

		// Verifica se o arquivo de area, que � o principal, foi carregado corretamente
		pugi::xml_document doc_area;
		pugi::xml_parse_result result = doc_area.load_file(area_file.c_str());
		if (!result){
			notifyXmlLoadError(result.description());
			return Core::ReturnStatus::Failed;
		}

		// Verifica o tamanho dos tiles, que s�o v�lidos para todos os mapas e eventos
		if ((!doc_area.child("area").attribute("tilewidth")) || (!doc_area.child("area").attribute("tileheight"))) {
			notifyXmlLoadError("attributes 'tilewidth' and/or 'tileheight' not encountered in the file '" + area_file + "'.");
			return Core::ReturnStatus::Failed;
		} else {
			stringStreamValue << doc_area.child("area").attribute("tilewidth").value();
			stringStreamValue >> tileRect.w;
			stringStreamValue.str(std::string());
			stringStreamValue.clear();
			stringStreamValue << doc_area.child("area").attribute("tileheight").value();
			stringStreamValue >> tileRect.h;
		}

		/* ********* In�cio do carregamento dos tilesets ************* */
		for (pugi::xml_node node_tileset : doc_area.child("area").children("tileset"))
		{
			if (!node_tileset.attribute("src")){
				notifyXmlLoadError("attribute 'src' of the node 'tileset' not found in file '" + area_file + "'.");
				return Core::ReturnStatus::Failed;
			}

			pugi::xml_document doc_tileset;
			pugi::xml_parse_result result = doc_tileset.load_file(node_tileset.attribute("src").value());
			if (!result){
				notifyXmlLoadError(result.description());
				return Core::ReturnStatus::Failed;
			}

			if (!doc_tileset.child("tileset")){
				notifyXmlLoadError("node 'map' not found in file '" + std::string(node_tileset.attribute("src").value()) + "'.");
				return Core::ReturnStatus::Failed;
			}

			if (!doc_tileset.child("tileset").attribute("name")){
				notifyXmlLoadError("attribute 'name' of the node 'tileset' not found in file '" + std::string(node_tileset.attribute("src").value()) + "'.");
				return Core::ReturnStatus::Failed;
			}

			if (!doc_tileset.child("tileset").attribute("src")){
				notifyXmlLoadError("Error to load XML file: attribute 'src' of the node 'tileset' not found in file '" + std::string(node_tileset.attribute("src").value()) + "'.");
				return Core::ReturnStatus::Failed;
			}

			tilesetSource = doc_tileset.child("tileset").attribute("src").value();
			tilesetName = doc_tileset.child("tileset").attribute("name").value();

			_sharedData.tilesetList.insert(std::make_pair(tilesetName, new Collections::Images::ImageCollection(appBase)));
			tilesetList_it = _sharedData.tilesetList.find(tilesetName);
			if (tilesetList_it->second->loadImage(tilesetSource) != Core::ReturnStatus::Success){
				notifyXmlLoadError("Error to load image file '" + tilesetSource + "'.");
				return Core::ReturnStatus::Failed;
			}
			Core::integer_id numColums = tilesetList_it->second->getImageWidth() / tileRect.w;
			Core::integer_id numLines = tilesetList_it->second->getImageHeight() / tileRect.h;

			tileID = 0;
			for (pugi::xml_node node_tile : doc_tileset.child("tileset").children("tile")){
				if ((!node_tile.child("position")) || (!node_tile.child("position").attribute("x")) || (!node_tile.child("position").attribute("y"))){
					notifyXmlLoadError("Error to load XML file: node 'position' or attribute 'x'/'y' of the node 'tile->position' not found in file '" + std::string(node_tileset.attribute("src").value()) + "'.");
					return Core::ReturnStatus::Failed;
				}

				stringStreamValue.str(std::string());
				stringStreamValue.clear();
				stringStreamValue << node_tile.child("position").attribute("x").value();
				stringStreamValue >> tileRect.x;
				
				stringStreamValue.str(std::string());
				stringStreamValue.clear();
				stringStreamValue << node_tile.child("position").attribute("y").value();
				stringStreamValue >> tileRect.y;

				tileRect.x *= tileRect.w;
				tileRect.y *= tileRect.h;
				tilesetList_it->second->addFrame(tileID, tileRect);
				tileID++;
			}
		}
		/* ************ Fim do carregamento dos tilesets ************* */

		/* *************** Inicio da cria��o dos mapas *************** */
		for (pugi::xml_node node_map : doc_area.child("area").children("map"))
		{
			// Verifica se o arquivo de mapa foi carregado corretamente
			pugi::xml_document doc_map;
			mapSource = node_map.attribute("src").value();
			result = doc_map.load_file(node_map.attribute("src").value());
			if (!result){
				notifyXmlLoadError(result.description());
				return Core::ReturnStatus::Failed;
			}
		
			if (!doc_map.child("map")){
				notifyXmlLoadError("node 'map' not found in file '" + mapSource + "'.");
				return Core::ReturnStatus::Failed;
			}

			if (!doc_map.child("map").attribute("name")){
				notifyXmlLoadError("attribute 'name' of the node 'map' not found in file '" + mapSource + "'.");
				return Core::ReturnStatus::Failed;
			}
			mapName = doc_map.child("map").attribute("name").value();

			// Verifica os tilesets de determinado bloco e cria um GameObject para cada item de acordo com suas defini��es
			for (pugi::xml_node node_layer : doc_map.child("map").children("layer")){

				if (strcmp(node_layer.attribute("type").value(), "solidblocks") == 0){
					mapLayer = Core::Layer::SolidBlocks;
				}else{
					notifyXmlLoadError("attribute 'type' of the node 'layer' is incorrect in file '" + mapSource + "'.");
					return Core::ReturnStatus::Failed;
				}

				for (pugi::xml_node node_tileMap : node_layer.children("tile")){
					// Verifica os dados relacionados ao tile
					stringStreamValue.str(std::string());
					stringStreamValue.clear();
					stringStreamValue << node_tileMap.attribute("id").value();
					stringStreamValue >> tileID;
					stringStreamValue.str(std::string());
					stringStreamValue.clear();
					stringStreamValue << node_tileMap.attribute("x").value();
					stringStreamValue >> tileRect.x;
					tileRect.x *= tileRect.w;
					stringStreamValue.str(std::string());
					stringStreamValue.clear();
					stringStreamValue << node_tileMap.attribute("y").value();
					stringStreamValue >> tileRect.y;
					tileRect.y *= tileRect.h;

					// Cria um novo objeto
					stringStreamValue.str(std::string());
					stringStreamValue.clear();
					stringStreamValue << __COMMON_ID;
					stringStreamValue << objectCounter;
					EObjects::GameObject *goTile = EObjects::GameObject::newObject(stringStreamValue.str());

					// Adiciona os componentes necess�rios
					EObjects::Components::Graphics::SimplePicture* simplePicture = new EObjects::Components::Graphics::SimplePicture(_sharedData.tilesetList.find(node_tileMap.attribute("tileset").value())->second, tileID);
					simplePicture->setOwner(goTile);
					goTile->addGOC(simplePicture);
					EObjects::Components::Position *tilePosition = new EObjects::Components::Position();
					tilePosition->setX(tileRect.x);
					tilePosition->setY(tileRect.y);
					tilePosition->setOwner(goTile);
					goTile->addGOC(tilePosition);

					_eventList[mapName].goList[mapLayer].push_back(goTile);

					objectCounter++;
				}
			}

		}
		/* **************** Fim da cria��o dos mapas ***************** */

        return Core::ReturnStatus::Success;
    }

	void Resources::update(){
		//Event *_event = &;
		/*for (std::vector<EObjects::GameObject*>::iterator it = _eventList["map0001"].goList.begin(); it != _eventList["map0001"].goList.end(); it++) {
			it->second->update();
			// iterator->first = key
			// iterator->second = value
			// Repeat if you also want to iterate through the second map.
		}*/
		for (auto &go : _eventList["map0001"].goList[Core::Layer::SolidBlocks]){
			EObjects::Components::Graphics::SimplePicture *picture = dynamic_cast<EObjects::Components::Graphics::SimplePicture*>(go->getGOC("EObjects::Components::Graphics::Picture"));
			if (picture)
				picture->update();
		}

//		_event->goList[0]->sendMessage("e", nullptr);
		//EObjects::GameObject *go = _eventList["map0001"].goList[0];
//		EObjects::Components::SimplePicture *picture = dynamic_cast<EObjects::Components::SimplePicture*>(_eventList["map0001"].goList[0]->getGOC("EObjects::Components::Graphics::Picture"));
		//if (go)
		//	go->update();// ["common-id:0"]->
	}

	void SharedData::clear(){
		// Deleta todos os tilesets alocados
		for (auto tilesets : tilesetList){
			if (tilesets.second)
				delete tilesets.second;
		}
		tilesetList.clear();
	}

	void Resources::clear(){
		// Limpa dados relacionados aos eventos
		for (auto event : _eventList){
			for (auto layer : event.second.goList){
				for (auto gameObject : layer.second){
					if (gameObject)
						delete gameObject;
				}
				layer.second.clear();
			}
			event.second.goList.clear();
		}
		_eventList.clear();

		_sharedData.clear();

	}

}
