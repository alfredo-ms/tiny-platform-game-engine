#ifndef __Game_Resources
#define __Game_Resources

#include "../core/ibase.hpp"
#include "../eobjects/gameobject.hpp"
#include "../collections/images/imagecollection.hpp"


namespace Game {
	struct Event {
	public:
		Core::Event::Type::Enum type;
		Core::RGBColor backgroundColor;
		std::map<Core::Layer::Enum, std::vector<EObjects::GameObject*>> goList;
	};

	struct SharedData{
	public:
		std::map<std::string, Collections::Images::ImageCollection*> tilesetList;
		void clear();
	};

    class Resources: public Core::IBase {
        public:
            Resources();
            ~Resources();

            virtual std::string getComponentID(void) const { return "Game::Resources"; };
			Core::ReturnStatus::Enum loadArea(std::string area_file, AppBase *appBase);
			void update();
			void clear();
			void notifyXmlLoadError(std::string message);

		private:
			typedef std::map<std::string, Event> EventList;
			EventList _eventList;
			SharedData _sharedData;
    };

	static Resources resources;
}

#endif // __Game_Resources
