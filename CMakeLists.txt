CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#set the compiler for every platform (if required)
IF (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET (CMAKE_CXX_COMPILER "clang++")
    SET (CMAKE_C_COMPILER "clang")
ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

PROJECT(base_sdlEngine)

#set the sources to be compiled
FILE(GLOB MAIN_SOURCE "source/*.cpp" "source/*.hpp")
FILE(GLOB CORE_SOURCE "source/core/*.cpp" "source/core/*.hpp" "source/core/utils/*.cpp" "source/core/utils/*.hpp" "source/core/graphics/*.cpp" "source/core/graphics/*.hpp")
FILE(GLOB IMAGES_COLLECTIONS_SOURCE "source/collections/images/*.cpp" "source/collections/images/*.hpp")
FILE(GLOB GRAPHICS_COMPONENTS_SOURCE "source/eobjects/components/graphics/*.cpp" "source/eobjects/components/graphics/*.hpp")
FILE(GLOB MAINGAME_SOURCE "source/game/*.cpp" "source/game/*.hpp")
FILE(GLOB EOBJECTS_SOURCE "source/eobjects/*.cpp" "source/eobjects/*.hpp" "source/eobjects/components/*.cpp" "source/eobjects/components/*.hpp")
FILE(GLOB PUGIXML_SOURCE "source/common/pugixml/*.cpp" "source/common/pugixml/*.hpp")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
ADD_EXECUTABLE(${PROJECT_NAME} ${MAIN_SOURCE} ${PUGIXML_SOURCE} ${IMAGES_COLLECTIONS_SOURCE} ${GRAPHICS_COMPONENTS_SOURCE} ${CORE_SOURCE} ${MAINGAME_SOURCE} ${EOBJECTS_SOURCE})
 
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2 sdl2_image)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)


INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
