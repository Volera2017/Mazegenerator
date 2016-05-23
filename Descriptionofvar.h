#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "Menu.h"
#include <vector>
#include <stack>
#include "Options.h"
#include "Difficulty.h"
#include "Cellstate.h"
#include "Restart.h"

static int num = 0;
static int opnum = 0;
static int number = 4;
static int difnum = 0;
static int fog = 0;
static int width = 10;
static int height = 10;
static bool booll = true;
static Cell **labyrinth;
static int switcher;
static Sprite spritemenu;
static Texture imagebackmenu;



extern void generate_level();
extern void menu_window();
extern void game_progress();
extern int main_implementation();