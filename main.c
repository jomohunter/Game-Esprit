#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "khalil.h"

int main()
{ 
	SDL_Surface *screen ;
	enigme  e;
        e.num_enigme=-1;
	int s,r=0,run =1,running=1,alea;
	char image[30]="";
	 SDL_Event event;
	 
	 SDL_Init ( SDL_INIT_EVERYTHING) ;

	 screen=SDL_SetVideoMode(1280,720,32 ,SDL_HWSURFACE  |  SDL_DOUBLEBUF  );

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError()); 
}
Mix_Music *music ; 
music = Mix_LoadMUS("sound.mp3");
Mix_PlayMusic(music,-1); 
	 
	 while (run)
	 {
         int prevt=SDL_GetTicks();
         	 init_enigme(&e,"enigme.txt");
             afficherEnigme(e,screen); // afficher enigme //

	     SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                run = 0;
	        break ;
        }

        int time=0;
       	r=0;
   do{     	
        time=(SDL_GetTicks()-prevt)/1000;	// entre 0 et 30 generate //       
        SDL_BlitSurface(e.anim.spritesheet,&e.anim.clips[e.anim.cliploaded],screen,&e.anim.pos); // afficher l animation //
        SDL_Flip(screen);
        printf("%d\n",time);

switch (time)
        {
    case 5:
        animer(&e);
    break;

    case 10:
        animer(&e);
    break;

    case 15:
        animer(&e);
    break;

    case 20:
        animer(&e);
    break;

    case 25:
        animer(&e);
    break;

    case 30:
        animer(&e);
    break;
        }
    r=resolution (&running,&run); // r donc feha reponse mtaak //


   } while(time<=30 && (r>3 || r<1) && running!=0);
			
      while(running) // sig different de 1 running //
      {
          afficher_resultat(screen,e.reponsevrai,r,&e); // e.reponsevrai hiaa s fel fonction y9rha mel fichier enigme.txt // 
          
			  SDL_WaitEvent(&event);
        switch(event.type)
            {
			case SDL_QUIT :
                        running =0 ;
			run=0 ;
					  break ;

            case SDL_KEYDOWN :
						    
                switch( event.key.keysym.sym )
                {
	             case  SDLK_ESCAPE: 
		        running= 0 ;
			            break ;

                        case SDLK_SPACE:
                          running=0;
                        break;
			  
			   
			    }
		break ;
            }
				
		}
 }
	 
      SDL_FreeSurface(screen);
      SDL_Quit();
      return 0;
}
