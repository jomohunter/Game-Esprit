#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>

typedef struct 
{
    SDL_Rect pos; // SDL_Rect -- Defines a rectangular area //
    SDL_Surface *spritesheet; 
    SDL_Rect clips[6]; // tableau clips de 6 cases dans chaque case  on trouve struct SDL_rect //
    int cliploaded; 
}animation;


typedef struct 
{
    SDL_Surface *img;
    SDL_Rect p; 
    int reponsevrai; // reponse vrai //
    int reponsejoueur;
    int num_enigme; // 1 to 3 //
    animation anim;
}enigme;

void init_enigme(enigme * e, char *nomfichier); // declaration et initiliasation enigme //
void  generate_afficher (int *alea) ; // alea randon between numbers of enigms u have in ur code exemple 3 //
void afficherEnigme(enigme e, SDL_Surface * screen); // afficher l'enigme dans votre ecran //
int resolution (int * running,int *run); // comparer between ur reponse(choice) and the true reponse //
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en);
void animer (enigme * e); // animation dans chaque enigme // 

#endif

