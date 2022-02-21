#include "menu.h"



int menu(etat *etat, etatson *etatson)
{

SDL_Surface *ecran = NULL;
SDL_Surface *menu = NULL, *btn_play = NULL , *btn_options = NULL , *btn_quit = NULL ;

parameter *p ;

SDL_Rect positionMenu, positionClic;
SDL_Event event;
int continuer=3;
parameter parameter;

putenv("SDL_VIDEO_CENTERED = 1");
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    //load icon
    SDL_WM_SetIcon(IMG_Load("logo.jpg"),NULL);
    ecran = SDL_SetVideoMode(1228,768,32, SDL_HWSURFACE  |   SDL_DOUBLEBUF);
    SDL_WM_SetCaption("THE SEARCH", NULL);
// load menu

	//creer une position de l image
	positionMenu.x=0;
	positionMenu.y=0;
	menu = IMG_Load("./src/pictures/menu.png");//chargement de l image
	SDL_BlitSurface(menu,NULL,ecran,&positionMenu);

	SDL_Rect position_btn_play;//creer une position de l image
	position_btn_play.x=500;
	position_btn_play.y=250;
	btn_play = IMG_Load("./src/pictures/PLAY.png");
	SDL_BlitSurface(btn_play,NULL,ecran,&position_btn_play);

	SDL_Rect position_btn_options;//creer une position de l image
        position_btn_options.x=500;
        position_btn_options.y=350;
        btn_options = IMG_Load("./src/pictures/OPTIONS.png");
        SDL_BlitSurface(btn_options,NULL,ecran,&position_btn_options);

	SDL_Rect position_btn_quit;//creer une position de l image
        position_btn_quit.x=500;
        position_btn_quit.y=450;
        btn_quit = IMG_Load("./src/pictures/QUIT.png");
        SDL_BlitSurface(btn_quit,NULL,ecran,&position_btn_quit);


if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)<0)
    printf("error : %s", Mix_GetError());
Mix_Music *bgm = Mix_LoadMUS("./src/sounds/bg.mp3");
Mix_Chunk *soundeffect  = Mix_LoadMUS("./src/sounds/chunk.mp3"); //  <-- sound effect load


initialiser_parameters(&parameter);
Mix_PlayMusic(bgm, -1);

while(continuer){
SDL_WaitEvent(&event);
switch(event.type){
    case SDL_QUIT:
        continuer = 0;
    break;


    case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
        case SDLK_ESCAPE:

            continuer =0;
        break;
        case SDLK_p:

            play(ecran, &etat);

        break;
        case SDLK_s:

            settings(ecran, &p, &etat,etatson);
        break;
        case SDLK_m:

            if(Mix_PlayingMusic())
                Mix_HaltMusic();
            else
                Mix_PlayMusic(bgm, -1);
        break;
        }
    case SDL_MOUSEBUTTONUP:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
        // hethi te5ou position mta3 il souris wa9tli il clic bich in compariw
            positionClic.x = event.button.x;
            positionClic.y - event.button.y;
            //play
                        if (event.button.x > 0 && event.button.x < 250 & event.button.y > 0 && event.button.y < 200 )
            {
                Mix_PlayMusic(soundeffect, 1);

                //change button
            }
            if (event.button.x > 572 && event.button.x < 655 & event.button.y > 290 && event.button.y < 310 )
            {
                Mix_PlayMusic(soundeffect, -1);
                btn_play = IMG_Load("./src/pictures/PLAY_click.png");
                play(ecran, &etat);
            }
            //settings
            if (event.button.x > 500 && event.button.x < 700 & event.button.y > 350 && event.button.y < 425 )
            {
                Mix_PlayMusic(soundeffect, -1);
                btn_options = IMG_Load("./src/pictures/OPTIONS_click.png");
                settings(ecran, &p, &etat, etatson);
            }
            //exit
            if (event.button.x > 500 && event.button.x < 700 & event.button.y > 450 && event.button.y < 550 )
            {
                Mix_PlayMusic(soundeffect, -1);
                btn_quit = IMG_Load("./src/pictures/QUIT_click.png");
                continuer =0;
            }
        }
    break;
    case SDL_MOUSEMOTION:
            //play

            if (event.motion.x > 560 && event.motion.x < 665 & event.motion.y > 280 && event.motion.y < 325 )
            {
                btn_play = IMG_Load("./src/pictures/PLAY_motion.png");
                //change button
            }
            //settings
            if (event.motion.x > 475 && event.motion.x < 725 & event.button.y > 330 && event.motion.y < 425 )
            {
                //change button
                btn_options = IMG_Load("./src/pictures/OPTIONS_motion.png");
            }
            //exit
            if (event.motion.x > 475 && event.motion.x < 725 & event.motion.y > 430 && event.motion.y < 550 )
            {
                btn_quit = IMG_Load("./src/pictures/QUIT_motion.png");
                //change button
            }

    break;
}


    SDL_Flip(ecran);

}
Mix_FreeMusic(bgm);
Mix_FreeChunk(soundeffect);
SDL_FreeSurface(menu);
SDL_FreeSurface(btn_options);
SDL_FreeSurface(btn_quit);
SDL_FreeSurface(btn_play);
SDL_Quit();
Mix_Quit();

return EXIT_SUCCESS;

}
