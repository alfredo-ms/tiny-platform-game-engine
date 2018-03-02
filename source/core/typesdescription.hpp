#ifndef __Core_TypesDescription
#define __Core_TypesDescription

#include <string>
#include <SDL.h>

// definições de nomes externos de variáveis
#define __ERRORLOG_FILE_NAME "error_log.txt"


namespace Core {

    // define to component name
    typedef size_t integer_id;

	struct RGBColor {
	public:
		Uint8 red;
		Uint8 green;
		Uint8 blue;
	};

	namespace Video {
		namespace ScaleType {
			enum Enum{
				NoRestrictions,
				MatchAspectRatio,
				NearestAspectRatio,
				NearestAspectRatio_WithAllScreen,
			};
		}
	}

    namespace ReturnStatus {
		enum Enum{
			Success,
			Failed,
		};
    }

    namespace GameState {
	enum Enum{
	    MainMenu,
	    MainGame,
            Intro,
            GameOver,
            Exit,
            Error,
	};
    }

    //typedef sf::Vector2f position_type;

    namespace ImageDirection {
	enum Enum{
	    Right   = 1 << 0,   // binary 00000001
	    Left    = 1 << 1,   // binary 00000010
	    Up      = 1 << 2,   // binary 00000100
	    Down    = 1 << 3,   // binary 00001000
	};
    }

    namespace MoveDirection {
	enum Enum{
	    Stand   = 0,        // binary 00000000
	    Right   = 1 << 0,   // binary 00000001
	    Left    = 1 << 1,   // binary 00000010
	    Up      = 1 << 2,   // binary 00000100
	    Down    = 1 << 3,   // binary 00001000
	};
    }

	namespace Layer {
		enum Enum {
			Background_SolidBlocks,
			Background_Objects,
			SolidBlocks,
		};
	}

	namespace Collision {
		namespace Type {
			enum Enum {
				Rect,
				Circle,
				Triangle,
				Rect_PerPixel,
				Circle_PerPixel,
				Triangle_PerPixel,
			};
		}

		namespace Depth {
			enum Enum {
				Deep_Background,
				Deep_Foreground,
				Back_Background,
				Back_Foreground,
				Front_Background,
				Front_Foreground,
			};
		}
	}

	namespace Event {
		namespace Type {
			enum Enum {
				Map,
			};
		}
	}

}

#endif // __Core_TypesDescription
