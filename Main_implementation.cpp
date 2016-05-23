#include "Descriptionofvar.h"

int main_implementation()
{
	switcher = 0;
	do
	{
		menu_window();
		Cell** a = generate_level();
		game_progress(a);
	} while (switcher == 0);
	return 0;
}