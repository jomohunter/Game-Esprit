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
ecran = SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
menu=SDL_LoadBMP("./src/Background.bmp");
posMenu.x=0;
posMenu.y=0;
posMenu.w=1920;
posMenu.h=1080;



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
