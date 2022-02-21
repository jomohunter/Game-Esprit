#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>
#include <SDL/SDL_mixer.h>

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define WIDTH 1920
#define HEIGHT 1080

typedef enum etat
{
    MENU,
    SETTINGS,
    GAME,

}etat;

typedef enum etatson
{
    MUTE,
    NOTMUTE,

}etatson;

typedef struct parameter{
    Mix_Music *music;
    Mix_Chunk *click;
    int fullscreen;
    int volume;
    Mix_Chunk *keyboard_click;
    int mute;

}parameter;

int play(SDL_Surface * ecran, etat *etat);
int menu(etat *etat, etatson *etatson);
int settings(SDL_Surface * ecran, parameter *p, etat *etat, etatson *etatson);
void initialiser_parameters(parameter *p);



#endif

#endif // MENU_H_INCLUDED
