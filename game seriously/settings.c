#include "menu.h"

int settings(SDL_Surface *ecran, parameter *p, etat *etat)
{
SDL_Surface *background = NULL;

SDL_Rect positionGame, positionClic;
SDL_Event event;
int continuer=3, f = 0, m = 0, b = 0;
SDL_Surface *full = NULL, *mute = NULL, *back = NULL, *screen_mode = NULL, *sound = NULL, *volume_bar = NULL, *plus = NULL, *moins = NULL;
SDL_Rect pos_mute, pos_full, pos_back, pos_sound, pos_screen, pos_vol_bar, pos_plus, pos_moins;

Mix_Chunk *click;

putenv("SDL_VIDEO_CENTERED = 1");
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    //load icon
    SDL_WM_SetIcon(IMG_Load("icon.bmp"),NULL);
    ecran = SDL_SetVideoMode(1920,1080,32, SDL_HWSURFACE  |   SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Fall of Rome", NULL);
// load menu
background = IMG_Load("./firstmenu.png");


    TTF_Font *police = NULL;
	police = TTF_OpenFont("./MisterBoring.ttf", 15);
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Color couleurRouge = {255, 0, 0};

	plus = TTF_RenderText_Blended(police, "+", couleurBlanche);
	moins = TTF_RenderText_Blended(police, "-", couleurBlanche);


positionGame.x = 0;
positionGame.y = 0;
pos_sound.x = 200;
pos_sound.y = 219;
pos_mute.x = 280;
pos_mute.y = pos_sound.y;
pos_screen.x = 200;
pos_screen.y = 260;
pos_full.x = 320;
pos_full.y = pos_screen.y - 10;
pos_back.x = 200;
pos_back.y = 300;
pos_vol_bar.x = 340;
pos_vol_bar.y = 212;
pos_plus.x = 405;
pos_plus.y = 220;
pos_moins.x = 425;
pos_moins.y = 220;


SDL_Flip(ecran);

switch (p->volume)
	{
	case 0:
		p->mute = 1;
		volume_bar = NULL;
		break;
	case 24:
		volume_bar = IMG_Load("../img/menu/buttons/1_bar.png");
		break;
	case 48:
		volume_bar = IMG_Load("../img/menu/buttons/2_bars.png");
		break;
	case 72:
		volume_bar = IMG_Load("../img/menu/buttons/3_bars.png");
		break;
	case 96:
		volume_bar = IMG_Load("../img/menu/buttons/4_bars.png");
		break;
	case 120:
		volume_bar = IMG_Load("../img/menu/buttons/5_bars.png");
		break;
	}
	sound = IMG_Load("../img/menu/buttons/sound.png");
	if (p->mute == 0)
		mute = IMG_Load("../img/menu/buttons/mute.png");
	else
		mute = IMG_Load("../img/menu/buttons/mute_tick.png");
	screen_mode = IMG_Load("../img/menu/buttons/screen.png");
	if (p->fullscreen == 0)
		full = IMG_Load("../img/menu/buttons/full.png");
	else
		full = IMG_Load("../img/menu/buttons/full_tick.png");
	back = IMG_Load("../img/menu/buttons/back.png");

	click = Mix_LoadWAV("../sfx/click.wav");

	background = SDL_LoadBMP("../img/menu/background/ZEUUN.bmp");

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)<0)
    printf("error : %s", Mix_GetError());
Mix_Music *bgm = Mix_LoadMUS("./sonMenu.ogg");
//Mix_Chunk *soundeffect   <-- sound effect load



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
					continuer = 0;
					break;
				case SDLK_LEFT:
					if (m == 1)
					{
						p->volume -= 24;
						switch (p->volume)
						{
						case 0:
							p->mute = 1;
							volume_bar = NULL;
							break;
						case 24:
							volume_bar = IMG_Load("../img/menu/buttons/1_bar.png");
							break;
						case 48:
							volume_bar = IMG_Load("../img/menu/buttons/2_bars.png");
							break;
						case 72:
							volume_bar = IMG_Load("../img/menu/buttons/3_bars.png");
							break;
						case 96:
							volume_bar = IMG_Load("../img/menu/buttons/4_bars.png");
							break;
						case 120:
							volume_bar = IMG_Load("../img/menu/buttons/5_bars.png");
							break;
						}
					}
					break;
				case SDLK_RIGHT:
					if (m == 1)
					{
						p->volume += 24;
						p->mute = 0;
						switch (p->volume)
						{
						case 0:
							p->mute = 1;
							volume_bar = NULL;
							break;
						case 24:
							volume_bar = IMG_Load("../img/menu/buttons/1_bar.png");
							break;
						case 48:
							volume_bar = IMG_Load("../img/menu/buttons/2_bars.png");
							break;
						case 72:
							volume_bar = IMG_Load("../img/menu/buttons/3_bars.png");
							break;
						case 96:
							volume_bar = IMG_Load("../img/menu/buttons/4_bars.png");
							break;
						case 120:
							volume_bar = IMG_Load("../img/menu/buttons/5_bars.png");
							break;
						}
					}
					break;
				case SDLK_RETURN:
					if (b == 1)
					{
						Mix_PlayChannel(-1, p->click, 0);
						continuer = 0;
						*etat = MENU;
					}
					if (f == 1 && p->fullscreen == 0)
					{
						Mix_PlayChannel(-1, p->click, 0);
						ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
						full = IMG_Load("../img/menu/buttons/full_active_tick.png");
						//SDL_Flip(screen);
						p->fullscreen = 1;
					}
					else if (f == 1 && p->fullscreen == 1)
					{
						Mix_PlayChannel(-1, p->click, 0);
						ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
						full = IMG_Load("../img/menu/buttons/full_active.png");
						//SDL_Flip(screen);
						p->fullscreen = 0;
					}
					if (m == 1 && p->mute == 0)
					{
						Mix_PauseMusic();
						mute = IMG_Load("../img/menu/buttons/mute_active_tick.png");
						p->mute = 1;
					}
					else if (m == 1 && p->mute == 1)
					{
						Mix_ResumeMusic();
						mute = IMG_Load("../img/menu/buttons/mute_active.png");
						p->mute = 0;
					}
					break;
				case SDLK_DOWN:
					if (m == 0 && f == 0 && b == 0)
					{

						Mix_PlayChannel(-1, p->click, 0);
						if (p->mute == 0)
							mute = IMG_Load("../img/menu/buttons/mute_active.png");
						else
							mute = IMG_Load("../img/menu/buttons/mute_active_tick.png");
						if (p->fullscreen == 0)
							full = IMG_Load("../img/menu/buttons/full.png");
						else
							full = IMG_Load("../img/menu/buttons/full_tick.png");
						m = 1;
						f = 0;
						b = 0;
					}
					else if (m == 1 && f == 0 && b == 0)
					{
						Mix_PlayChannel(-1, p->click, 0);
						if (p->mute == 0)
							mute = IMG_Load("../img/menu/buttons/mute.png");
						else
							mute = IMG_Load("../img/menu/buttons/mute_tick.png");
						if (p->fullscreen == 0)
							full = IMG_Load("../img/menu/buttons/full_active.png");
						else
							full = IMG_Load("../img/menu/buttons/full_active_tick.png");
						m = 0;
						f = 1;
						b = 0;
					}
					else if (m == 0 && f == 1 && b == 0)
					{
						Mix_PlayChannel(-1, p->click, 0);
						if (p->fullscreen == 0)
							full = IMG_Load("../img/menu/buttons/full.png");
						else
							full = IMG_Load("../img/menu/buttons/full_tick.png");
						if (p->mute == 0)
							mute = IMG_Load("../img/menu/buttons/mute.png");
						else
							mute = IMG_Load("../img/menu/buttons/mute_tick.png");
						back = IMG_Load("../img/menu/buttons/back_active.png");
						m = 0;
						f = 0;
						b = 1;
					}
					break;
				case SDLK_UP:
					if (m == 0 && f == 0 && b == 1)
					{
						Mix_PlayChannel(-1, p->click, 0);
						if (p->fullscreen == 0)
							full = IMG_Load("../img/menu/buttons/full_active.png");
						else
							full = IMG_Load("../img/menu/buttons/full_active_tick.png");
						if (p->mute == 0)
							mute = IMG_Load("../img/menu/buttons/mute.png");
						else
							mute = IMG_Load("../img/menu/buttons/mute_tick.png");
						back = IMG_Load("../img/menu/buttons/back.png");
						m = 0;
						f = 1;
						b = 0;
					}
					else if (m == 0 && f == 1 && b == 0)
					{
						Mix_PlayChannel(-1, p->click, 0);
						if (p->fullscreen == 0)
							full = IMG_Load("../img/menu/buttons/full.png");
						else
							full = IMG_Load("../img/menu/buttons/full_tick.png");
						if (p->mute == 0)
							mute = IMG_Load("../img/menu/buttons/mute_active.png");
						else
							mute = IMG_Load("../img/menu/buttons/mute_active_tick.png");
						back = IMG_Load("../img/menu/buttons/back.png");
						m = 1;
						f = 0;
						b = 0;
					}
					break;
				}
				break;
			case SDL_MOUSEMOTION:
				if (event.motion.x > pos_plus.x && event.motion.x < pos_plus.x + plus->w && event.motion.y > pos_plus.y && event.motion.y < pos_plus.y + plus->h)
				{
					plus = TTF_RenderText_Blended(police, "+", couleurRouge);
					if (p->mute == 0)
						mute = IMG_Load("../img/menu/buttons/mute.png");
					else
						mute = IMG_Load("../img/menu/buttons/mute_tick.png");
					if (p->fullscreen == 0)
						full = IMG_Load("../img/menu/buttons/full.png");
					else
						full = IMG_Load("../img/menu/buttons/full_tick.png");
					moins = TTF_RenderText_Blended(police, "-", couleurBlanche);
				}
				else if (event.motion.x > pos_moins.x && event.motion.x < pos_moins.x + moins->w && event.motion.y > pos_moins.y && event.motion.y < pos_moins.y + moins->h)
				{
					moins = TTF_RenderText_Blended(police, "-", couleurRouge);
					if (p->mute == 0)
						mute = IMG_Load("../img/menu/buttons/mute.png");
					else
						mute = IMG_Load("../img/menu/buttons/mute_tick.png");
					if (p->fullscreen == 0)
						full = IMG_Load("../img/menu/buttons/full.png");
					else
						full = IMG_Load("../img/menu/buttons/full_tick.png");
					plus = TTF_RenderText_Blended(police, "+", couleurBlanche);
				}
				else if (event.motion.x > pos_mute.x && event.motion.x < pos_mute.x + mute->w && event.motion.y > pos_mute.y && event.motion.y < pos_mute.y + mute->h)
				{
					if (p->mute == 0)
						mute = IMG_Load("../img/menu/buttons/mute_active.png");
					else
						mute = IMG_Load("../img/menu/buttons/mute_active_tick.png");
					if (p->fullscreen == 0)
						full = IMG_Load("../img/menu/buttons/full.png");
					else
						full = IMG_Load("../img/menu/buttons/full_tick.png");
					back = IMG_Load("../img/menu/buttons/back.png");
					plus = TTF_RenderText_Blended(police, "+", couleurBlanche);
					moins = TTF_RenderText_Blended(police, "-", couleurBlanche);
				}
				else if (event.motion.x > pos_full.x && event.motion.x < pos_full.x + full->w && event.motion.y > pos_full.y && event.motion.y < pos_full.y + full->h)
				{
					if (p->fullscreen == 0)
						full = IMG_Load("../img/menu/buttons/full_active.png");
					else
						full = IMG_Load("../img/menu/buttons/full_active_tick.png");
					if (p->mute == 0)
						mute = IMG_Load("../img/menu/buttons/mute.png");
					else
						mute = IMG_Load("../img/menu/buttons/mute_tick.png");
					back = IMG_Load("../img/menu/buttons/back.png");
					plus = TTF_RenderText_Blended(police, "+", couleurBlanche);
					moins = TTF_RenderText_Blended(police, "-", couleurBlanche);
				}
				else if (event.motion.x > pos_back.x && event.motion.x < pos_back.x + back->w && event.motion.y > pos_back.y && event.motion.y < pos_back.y + back->h)
				{
					if (p->mute == 0)
						mute = IMG_Load("../img/menu/buttons/mute.png");
					else
						mute = IMG_Load("../img/menu/buttons/mute_tick.png");
					if (p->fullscreen == 0)
						full = IMG_Load("../img/menu/buttons/full.png");
					else
						full = IMG_Load("../img/menu/buttons/full_tick.png");
					back = IMG_Load("../img/menu/buttons/back_active.png");
					plus = TTF_RenderText_Blended(police, "+", couleurBlanche);
					moins = TTF_RenderText_Blended(police, "-", couleurBlanche);
				}
				else
				{
					if (p->mute == 0)
						mute = IMG_Load("../img/menu/buttons/mute.png");
					else
						mute = IMG_Load("../img/menu/buttons/mute_tick.png");
					if (p->fullscreen == 0)
						full = IMG_Load("../img/menu/buttons/full.png");
					else
						full = IMG_Load("../img/menu/buttons/full_tick.png");
					back = IMG_Load("../img/menu/buttons/back.png");
					plus = TTF_RenderText_Blended(police, "+", couleurBlanche);
					moins = TTF_RenderText_Blended(police, "-", couleurBlanche);
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (event.motion.x > pos_plus.x && event.motion.x < pos_plus.x + plus->w && event.motion.y > pos_plus.y && event.motion.y < pos_plus.y + plus->h)
					{
						p->volume += 24;
						p->mute = 0;
						switch (p->volume)
						{
						case 0:
							p->mute = 1;
							volume_bar = NULL;
							break;
						case 24:
							volume_bar = IMG_Load("../img/menu/buttons/1_bar.png");
							break;
						case 48:
							volume_bar = IMG_Load("../img/menu/buttons/2_bars.png");
							break;
						case 72:
							volume_bar = IMG_Load("../img/menu/buttons/3_bars.png");
							break;
						case 96:
							volume_bar = IMG_Load("../img/menu/buttons/4_bars.png");
							break;
						case 120:
							volume_bar = IMG_Load("../img/menu/buttons/5_bars.png");
							break;
						}
					}
					else if (event.motion.x > pos_moins.x && event.motion.x < pos_moins.x + moins->w && event.motion.y > pos_moins.y && event.motion.y < pos_moins.y + moins->h)
					{

						p->volume -= 24;
						switch (p->volume)
						{
						case 0:
							p->mute = 1;
							volume_bar = NULL;
							break;
						case 24:
							volume_bar = IMG_Load("../img/menu/buttons/1_bar.png");
							break;
						case 48:
							volume_bar = IMG_Load("../img/menu/buttons/2_bars.png");
							break;
						case 72:
							volume_bar = IMG_Load("../img/menu/buttons/3_bars.png");
							break;
						case 96:
							volume_bar = IMG_Load("../img/menu/buttons/4_bars.png");
							break;
						case 120:
							volume_bar = IMG_Load("../img/menu/buttons/5_bars.png");
							break;
						}
					}
					else if (event.motion.x > pos_mute.x && event.motion.x < pos_mute.x + mute->w && event.motion.y > pos_mute.y && event.motion.y < pos_mute.y + mute->h)
					{
						Mix_PlayChannel(-1, p->click, 0);
						if (p->mute == 0)
						{
							Mix_PauseMusic();
							mute = IMG_Load("../img/menu/buttons/mute_active_tick.png");
							p->mute = 1;
						}
						else
						{
							Mix_ResumeMusic();
							mute = IMG_Load("../img/menu/buttons/mute_active.png");
							p->mute = 0;
						}
					}
					else if (event.motion.x > pos_full.x && event.motion.x < pos_full.x + full->w && event.motion.y > pos_full.y && event.motion.y < pos_full.y + full->h)
					{
						Mix_PlayChannel(-1, p->click, 0);
						if (p->fullscreen == 0)
						{
							ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
							full = IMG_Load("../img/menu/buttons/full_active_tick.png");
							p->fullscreen = 1;
						}
						else
						{
							ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
							full = IMG_Load("../img/menu/buttons/full_active.png");
							p->fullscreen = 0;
						}
					}
					else if (event.motion.x > pos_back.x && event.motion.x < pos_back.x + back->w && event.motion.y > pos_back.y && event.motion.y < pos_back.y + back->h)
					{
						Mix_PlayChannel(-1, p->click, 0);
						continuer = 0;
						*etat = MENU;
					}
				}
				break;
			}
        SDL_BlitSurface(background, NULL, ecran, &positionGame);
		SDL_BlitSurface(screen_mode, NULL, ecran, &pos_screen);
		SDL_BlitSurface(full, NULL, ecran, &pos_full);
		SDL_BlitSurface(sound, NULL, ecran, &pos_sound);
		SDL_BlitSurface(mute, NULL, ecran, &pos_mute);
		SDL_BlitSurface(back, NULL, ecran, &pos_back);
		SDL_BlitSurface(volume_bar, NULL, ecran, &pos_vol_bar);
		SDL_BlitSurface(plus, NULL, ecran, &pos_plus);
		SDL_BlitSurface(moins, NULL, ecran, &pos_moins);
		Mix_VolumeMusic(p->volume);
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
