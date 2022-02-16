#include "menu.h"



int menu(etat *etat)
{

SDL_Surface *ecran = NULL;
SDL_Surface *menu = NULL;

parameter *p ;

SDL_Rect positionMenu, positionClic;
SDL_Event event;
int continuer=3;
parameter parameter;

putenv("SDL_VIDEO_CENTERED = 1");
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    //load icon
    SDL_WM_SetIcon(IMG_Load("icon.bmp"),NULL);
    ecran = SDL_SetVideoMode(1920,1080,32, SDL_HWSURFACE  |   SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Fall of Rome", NULL);
// load menu
menu = IMG_Load("./menu.png");
positionMenu.x = 0;
positionMenu.y = 0;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)<0)
    printf("error : %s", Mix_GetError());
Mix_Music *bgm = Mix_LoadMUS("./sonMenu.ogg");
//Mix_Chunk *soundeffect   <-- sound effect load


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

            play(&ecran, &etat);

        break;
        case SDLK_s:

            settings(&ecran, &p, &etat);
        break;
        }
    case SDL_MOUSEBUTTONUP:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
        // hethi te5ou position mta3 il souris wa9tli il clic bich in compariw
            positionClic.x = event.button.x;
            positionClic.y - event.button.y;
            //play
            if (event.button.x > 200 && event.button.x < 430 & event.button.y > 510 && event.button.x < 625 )
            {
                play(&ecran, &etat);
            }
            //settings
            if (event.button.x > 100 && event.button.x < 540 & event.button.y > 690 && event.button.x < 820 )
            {
                settings(&ecran, &p, &etat);
            }
            //exit
            if (event.button.x > 210 && event.button.x < 420 & event.button.y > 880 && event.button.x < 1000 )
            {
                continuer =0;
            }
        }
    break;
    case SDL_MOUSEMOTION:
            //play
            if (event.motion.x > 180 && event.motion.x < 450 & event.motion.y > 490 && event.motion.x < 645 )
            {
                //change button
            }
            //settings
            if (event.motion.x > 80 && event.motion.x < 560 & event.button.y > 670 && event.motion.x < 840 )
            {
                //change button
            }
            //exit
            if (event.motion.x > 190 && event.motion.x < 440 & event.motion.y > 860 && event.motion.x < 1020 )
            {
                //change button
            }

    break;
}

SDL_BlitSurface(menu, NULL,ecran, &positionMenu);
    SDL_Flip(ecran);

}
Mix_FreeMusic(bgm);
SDL_FreeSurface(menu);
SDL_Quit();
Mix_Quit();

return EXIT_SUCCESS;

}
