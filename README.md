 ========================== TPGE (Tiny Platform Game Engine) v.0.3b =========================

> Developed by: Alfredo Magnani Sakatauskas
        Copyright (c) 2018 [RetroGameKnights]. All rights reserved.
 
    First Build: 26/06/2014
    Last Update: 02/03/2018

Update log:

**08/09/2014** - Created Core::Base, with the initialization of the engine and
        access to basic features, like windows management.

**11/01/2016** - Create a project to Visual Studio 2015, SDL 2.0.4 and pugixml 1.7.
        02/03/2018 - Files updated to first commit in GitHub.
 
 ==============================================================================================

#### About:
    This engine is created for development of the game Slice of Magic Work.
    The goal is to provide all the basics to a basic 2D game platformer.

#### Libraries used:
    SDL2
    SDL2_image

#### How to use:
**1**. Core::base, that is instantiated by Core::Base, provides all the basic
    to init and use the engine.

#### Build instructions:
    To build the game, you will need these libraries:
     *SDL2 2.0.4
     *SDL2_image
     *cmake 2.8
  	 *pugixml 1.8 (included)

    To build the linux version, use the cmake file:
      - Enter the "build" folder, type "cmake .." and press ENTER.
      - Then, type "make", and press ENTER.
   
    To build the MSWindows version, enter the VS2015_project folder, then open
            the Microsoft Visual C++ 2015 Community Edition project solution.
