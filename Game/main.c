#include"header.h"
int main(int argc, char** argv)
{ 
	SDL_Init ( SDL_INIT_VIDEO );
	SDL_Surface* screen;
	image start,settings,exit,backg,music;
	SDL_Event event;
	int position = 1,settingsverif=0,playverif=0;
    	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE|SDL_HWSURFACE);
	if ( !screen ) {
		printf("Unable to set 1920x1080video: %s\n", SDL_GetError());
		return 1;}
	SDL_WM_SetCaption("MYSTERIOUS-CORNER", NULL);
	initBackground(&backg);
	initButtons(&start,&settings);
	while (1)
	{
		afficher(backg,screen);
		afficher(start,screen);
		afficher(settings,screen);

		

		SDL_Flip(screen);
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
		{
			SDL_FreeSurface(screen);
			libererButtons(start,settings,backg);
			
			return 0;
		}
}
}
