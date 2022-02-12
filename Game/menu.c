#include "header.h"

void initButtons(image *A,image *B)
{
	A->img = IMG_Load("./src/optionsmenu.png");
		if (A->img== NULL) {
			return ;
		}
	A->pos.x = 100;
	A->pos.y = 200;
	
	B->img = IMG_Load("./src/name.png");
		if (B->img== NULL) {
			return ;
		}
	B->pos.x =200;
	B->pos.y = 50;
	
}
void initBackground(image *Backg)
{
Backg->img= IMG_Load("./src/Backgroun.png");
	if (Backg->img == NULL) {
		printf("Unable to load : %s\n", SDL_GetError());
		return;
		}
	Backg->pos.x=0;
	Backg->pos.y=0;
	Backg->pos.w=SCREEN_W; 
	Backg->pos.h=SCREEN_H;
}
void afficher(image p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.img,NULL,screen,&p.pos);
}
void libererButtons(image A,image B, image C)
{
	SDL_FreeSurface(A.img); 
	SDL_FreeSurface(B.img);
	SDL_FreeSurface(C.img);
}

