#ifndef Text_H
#define Text_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_H 770
#define SCREEN_W 988
typedef struct{
	SDL_Rect pos;
	SDL_Surface *img;
}image;
/*typedef struct {
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
} text;*/

void initButtons(image *A,image *B);
void initBackground(image *Backg);
void afficher(image A,SDL_Surface *screen);
void libererButtons(image A,image B, image C);

/*void initText(text *t);
void freeText(text A);
void displayText(text t,SDL_Surface *screen);*/
#endif
