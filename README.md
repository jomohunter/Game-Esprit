# Game-Esprit
2D game SDL 1.2

chabeb awel hkaya bch nkhdmou creaction d'une fenetre et background 
-) STEP 1 : creation 'un fichier 'game' mbad a3ml fyh fichier main.c ektb fyh code source hdha :

#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
int main(int argc,char *argv[])
{

SDL_Surface * ecran=NULL;
SDL_Surface *menu=NULL;
SDL_Rect posMenu;
int continuer =3;
SDL_Event event ;

//initalisation
SDL_Init(SDL_INIT_VIDEO);
//making window
ecran = SDL_SetVideoMode(1366,768,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
menu=SDL_LoadBMP("./src/Background.bmp");
posMenu.x=0;
posMenu.y=0;
posMenu.w=0;
posMenu.h=0;



//boucle
while(continuer)
{
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer=0;
break;


case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_ESCAPE:
continuer=0;
break;
}
break;

}
SDL_BlitSurface(menu,NULL,ecran,&posMenu);
SDL_Flip(ecran);
}}

-) STEP 2 : fy nefs dossier 'game' a3mlou dossier jdid esmh 'src' 7oto fyh les images (.bmp type mt3hom) :
les images lihbthom youssef type .png lzmhom conversion , odkhlou site hdha o a3mlou conversion selon l taille lt7bouh 
https://image.online-convert.com/convert-to-bmp hdha link mt3 site upload image hdhika png mbaad start .
-) STEP 3 : mbaad image (.mbp) 7otoha fy wast dossier 'src'
##N.B## :
dossier 'src' bch n7oto fyh les images audio ... mt3 jeux mt3na . 
-) STEP 3 : creation file Makefile mbaad gedit Makefile fy wast dossier 'game' o ektb code hdha :
prog:main.c
	gcc -c main.c
	gcc main.o -o prog -lSDL
	./prog
-) STEP 4 : verfication l nom mt3 image nafsh limwjoud fel main.c : 
menu=SDL_LoadBMP("./src/Background.bmp");
Background : nom image 
-) STEP 5 : compilation 
1)gcc main.c -o image -lSDL -lSDL_image 
2)make 

Game coded by Esprit Students for first year Project.
