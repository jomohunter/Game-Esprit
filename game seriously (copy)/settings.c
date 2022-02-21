#include "menu.h"

int settings(SDL_Surface *ecran, parameter *p, etat *etat, etatson *etatson)
{
SDL_Surface *background = NULL,  *btn_on = NULL , *btn_off = NULL , *btn_return = NULL ;

SDL_Rect positionGame, positionClic;
SDL_Event event;

Mix_Chunk *click;


int continuer = 3;

putenv("SDL_VIDEO_CENTERED = 1");
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    //load icon
    SDL_WM_SetIcon(IMG_Load("logo.jpg"),NULL);
    ecran = SDL_SetVideoMode(1228,768,32, SDL_HWSURFACE  |   SDL_DOUBLEBUF);
    SDL_WM_SetCaption("THE SEARCH", NULL);

background = IMG_Load("./src/pictures/menu.png");

    positionGame.x = 0;
    positionGame.y = 0;

if(etatson = MUTE){
    btn_on = IMG_Load("./src/pictures/ON.png");
    btn_off = IMG_Load("./src/pictures/OFF_click.png");
}
else{
    btn_on = IMG_Load("./src/pictures/ON_click.png");
    btn_off = IMG_Load("./src/pictures/OFF.png");

}


    btn_return =IMG_Load("./src/pictures/RETURN.png");
// load menu


    SDL_Rect position_btn_off, position_btn_on, position_btn_return;
	position_btn_off.x=500;
	position_btn_off.y=250;
	SDL_BlitSurface(btn_off,NULL,ecran,&position_btn_off);
	position_btn_off.x=700;
	position_btn_off.y=250;
	SDL_BlitSurface(btn_on,NULL,ecran,&position_btn_off);
	position_btn_return.x=200;
	position_btn_return.y=550;
	SDL_BlitSurface(btn_return,NULL,ecran,&position_btn_return);

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)<0)
    printf("error : %s", Mix_GetError());
Mix_Music *bgm = Mix_LoadMUS("./src/sounds/bg.mp3");
Mix_Chunk *soundeffect  = Mix_LoadMUS("./src/sounds/chunk.mp3");   //<-- sound effect load



Mix_PlayMusic(bgm, -1);

while(continuer){
SDL_WaitEvent(&event);
switch(event.type){
    case SDL_QUIT:
        continuer = 0;
    break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            case SDLK_ESCAPE:
                menu(etat, etatson);
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
            if (event.button.x > 500 && event.button.x < 700 & event.button.y > 250 && event.button.x < 325 )
            {

            }
            //settings
            if (event.button.x > 500 && event.button.x < 700 & event.button.y > 350 && event.button.x < 425 )
            {

            }
            //exit
            if (event.button.x > 500 && event.button.x < 700 & event.button.y > 450 && event.button.x < 550 )
            {

            }
        }
    break;
    case SDL_MOUSEMOTION:
            //play
            if (event.motion.x > 475 && event.motion.x < 725 & event.motion.y > 225 && event.motion.x < 325 )
            {
                btn_on = IMG_Load("./src/pictures/NEW GAME_click.png");
                //change button
            }
            //settings
            if (event.motion.x > 475 && event.motion.x < 725 & event.button.y > 330 && event.motion.x < 425 )
            {
                //change button
                btn_off = IMG_Load("./src/pictures/OPTIONS_click.png");
            }
            //exit
            if (event.motion.x > 475 && event.motion.x < 725 & event.motion.y > 430 && event.motion.x < 550 )
            {
                btn_return = IMG_Load("./src/pictures/QUIT_click.png");
                //change button
            }

    break;





			}
        SDL_BlitSurface(background, NULL, ecran, &positionGame);
        SDL_Flip(ecran);
		}

        Mix_FreeMusic(bgm);
        SDL_FreeSurface(menu);
}


void initialiser_parameters(parameter *p)
{
	p->mute = 0;
	p->volume = 120;
	p->fullscreen = 0;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}
	p->music = Mix_LoadMUS("../sfx/game_menu_music.wav");
	p->click = Mix_LoadWAV("../sfx/click.wav");
	//p->keyboard_click=Mix_LoadWAV("../sfx/keyboard_click.wav");
	Mix_PlayMusic(p->music, -1);
	Mix_VolumeMusic(p->volume);
}
