#include "menu.h"

int play(SDL_Surface * ecran, etat *etat)
{
SDL_Surface *game = NULL;

SDL_Rect positionGame, positionClic;
SDL_Event event;
int continuer=3;


putenv("SDL_VIDEO_CENTERED = 1");
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    //load icon
    SDL_WM_SetIcon(IMG_Load("logo.jpg"),NULL);
    ecran = SDL_SetVideoMode(1228,768,32, SDL_HWSURFACE  |   SDL_DOUBLEBUF);
    SDL_WM_SetCaption("THE SEARCH", NULL);
// load menu
game = IMG_Load("./src/pictures/menu.png");

positionGame.x = 0;
positionGame.y = 0;

SDL_Flip(ecran);

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)<0)
    printf("error : %s", Mix_GetError());
Mix_Music *bgm = Mix_LoadMUS("./src/sounds/bg.mp3");
Mix_Chunk *soundeffect = Mix_LoadMUS("./src/sounds/chunk.mp3"); // <-- sound effect load



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
            main();
        break;
        }
}
SDL_BlitSurface(game, NULL,ecran, &positionGame);
SDL_Flip(ecran);
}
Mix_FreeMusic(bgm);
SDL_FreeSurface(menu);

return EXIT_SUCCESS;
}
