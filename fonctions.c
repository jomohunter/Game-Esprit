#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h> 
#include<time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>  
#include <SDL/SDL_ttf.h>
#include "khalil.h" 

//////////////////////////////
void generate_afficher (int *alea) //random enigms from 1 engims to 3 engims //
{
	int test=*alea ;
       srand(SDL_GetTicks()); // SDL_gettick to generate nummber //   

 do
  {
     *alea = 1+ rand()%3; 
  }
while(*alea==test) ; 
}

/////////////////////////////////////
void init_enigme(enigme * e, char *nomfichier) // e pointeur sur struct engime declare dans .h et char *nomfichier : variable pour un fichier texte //
{ 
int j , y ;
	e->anim.pos.x=100; // position de l'animation sur l'axe x //
	e->anim.pos.y=20; // position de l'animation sur l'axe y //
	e->anim.spritesheet=IMG_Load("ourglasse1.png"); // load image of animation // 
	e->anim.cliploaded=1; 
 
	 for(j=0,y=0;j<6;j++,y+=20) // boucle pour l'animation //
	 {
		 e->anim.clips[j].x=6; 
		 e->anim.clips[j].y=y+6;
		 e->anim.clips[j].w=200; 
		 e->anim.clips[j].h=20;
	 }	
	int i=1;

	e->p.x=0;
	e->p.y=0;
	e->img=NULL;
	 
	 generate_afficher(&e->num_enigme);
	char nomimage[20];
	FILE *f=fopen("enigme.txt","r");
	if(f!=NULL)
	{

		while(fscanf(f,"%s %d\n",nomimage,&e->reponsevrai)!=EOF && i!=e->num_enigme)
		{
			i++;
		}
		printf("%s",nomimage);
		e->img=IMG_Load(nomimage);
		fclose(f);
	}
	else printf("erreur");
} 

 
/////////////////////////////////////////////
void afficherEnigme(enigme e, SDL_Surface * screen) // afficher l'enigme //
{
	SDL_BlitSurface(e.img,NULL,screen,&e.p); 
	SDL_Flip(screen); // La mise à jour de l’écran consiste à rafraîchir l'écran après avoir effectué plusieurs collages//
}



 ////////////////////////////////
int resolution (int * running,int *run )
{
        Mix_Chunk *son; 
	SDL_Event event ;
        int r=0 ;
	SDL_PollEvent(&event);
        son= Mix_LoadWAV( "click_effect.wav" );
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
              		        *run = 0;
				break ;

       case SDL_KEYDOWN :
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a:
Mix_PlayChannel( -1, son, 0 ); 
			   r= 1;
			   break ;
			   case  SDLK_z:
Mix_PlayChannel( -1, son, 0 ); 
			   r= 2;
			   break;
			   case SDLK_e:
Mix_PlayChannel( -1, son, 0 ); 
			   r=3 ;
			   break;

			    }
       break ;
	}
  return r ;
}

/////////////////////////////////////////////////////
 void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
 {

 	if (r==s)
 	{
 		en->img=IMG_Load("win.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
 		en->img=IMG_Load("lose.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 }


///////////////////////
 void animer (enigme * e)
{
	e->anim.cliploaded++;
	if(e->anim.cliploaded>=6)
	e->anim.cliploaded=1;
}


