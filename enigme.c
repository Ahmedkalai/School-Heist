#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"enigme.h"

void initialisation()
{
int continuer=1;

//initialisation
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());
//
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));

  tab[0]=IMG_Load("enigme1.png");
  tab[1]=IMG_Load("enigme2.png");
  tab[2]=IMG_Load("enigme3.png");
  tab[3]=IMG_Load("enigme4.png");
  tab[4]=IMG_Load("enigme5.png");
SDL_Rect posenig,reponsepos0,reponsepos1,reponsepos2,winpos,overpos;
posenig.x=0;
  posenig.y=0;

  
reponsepos0.x=0;
  reponsepos0.y=0;
   reponsepos1.x=0;
  reponsepos1.y=0;
   reponsepos2.x=0;
  reponsepos2.y=0;
  winpos.x=0;
  winpos.y=0;
  overpos.x=0;
  overpos.y=0;
SDL_Surface* reponse0;
SDL_Surface* reponse1;
SDL_Surface* reponse2;
SDL_Surface* win;
SDL_Surface* over;
  reponse0=IMG_Load("clic1.png");
  reponse1=IMG_Load("clic2.png");
  reponse2=IMG_Load("clic3.png");
  win=IMG_Load("win22.png");
  over=IMG_Load("over.png");

}

int afficher_enigme()
{
int continuer=1;
//numero aleatoire ddde l'image
int x;
x=rand()%4;


  SDL_BlitSurface(tab[x],NULL,fenetre,&posenig);
  SDL_Flip(fenetre);
  // resolution de l'enigme
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
Mix_Music *musique,*bip; //Création du pointeur de type Mix_Music
musique = Mix_LoadMUS("enigmemusique.mp3"); //Chargement de la musique
bip = Mix_LoadMUS("bip.mp3");

//repetition de la musique
Mix_PlayMusic(musique, -1);
return x;
}

void resolution_enigme()
{
int continuer=1;
int x;
x=afficher_enigme();

// resolution enigme 1
if (x==0)
{
while (continuer)
{

SDL_Event event;
SDL_WaitEvent(&event);


if(event.type==SDL_QUIT)
{


 continuer=0;
}

if(event.type==SDL_MOUSEMOTION)
{
if ( event.motion.x>10 && event.motion.x<240 && event.motion.y>500 && event.motion.y<580 )
	 {
		SDL_BlitSurface(reponse0,NULL,fenetre,&reponsepos0);
		SDL_Flip(fenetre);
		}
		else if ( event.motion.x>270 && event.motion.x<500 && event.motion.y>500 && event.motion.y<580 )
		{ 
		SDL_BlitSurface(reponse1,NULL,fenetre,&reponsepos1);
		SDL_Flip(fenetre);
		}
		else if ( event.motion.x>545 && event.motion.x<770 && event.motion.y>500 && event.motion.y<580)
		{
		SDL_BlitSurface(reponse2,NULL,fenetre,&reponsepos2);
		SDL_Flip(fenetre);
		}}
if(event.button.button==SDL_BUTTON_LEFT)
{
if(((event.button.x>10)&&(event.button.x<240))&&((event.button.y>500)&&
(event.button.y<580)))
{

Mix_PlayMusic(bip,1);
SDL_BlitSurface(win,NULL,fenetre,&winpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;

}

else if(((event.button.x>270)&&(event.button.x<500))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;

}
else if(((event.button.x>545)&&(event.button.x<770))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;
}
}

}
// resolution enigme 2
else if (x==1)
{
while (continuer)
{

SDL_Event event;
SDL_WaitEvent(&event);


if(event.type==SDL_QUIT)
{


 continuer=0;
}

if(event.type==SDL_MOUSEMOTION)
{
if ( event.motion.x>10 && event.motion.x<240 && event.motion.y>500 && event.motion.y<580 )
	 {
		SDL_BlitSurface(reponse00,NULL,fenetre,&reponsepos0);
		SDL_Flip(fenetre);
		}
		else if ( event.motion.x>270 && event.motion.x<500 && event.motion.y>500 && event.motion.y<580 )
		{ 
		SDL_BlitSurface(reponse11,NULL,fenetre,&reponsepos1);
		SDL_Flip(fenetre);
		}
		else if ( event.motion.x>545 && event.motion.x<770 && event.motion.y>500 && event.motion.y<580)
		{
		SDL_BlitSurface(reponse22,NULL,fenetre,&reponsepos2);
		SDL_Flip(fenetre);
		}}
if(event.button.button==SDL_BUTTON_LEFT)
{
if(((event.button.x>10)&&(event.button.x<240))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;


}

else if(((event.button.x>270)&&(event.button.x<500))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(win,NULL,fenetre,&winpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;

}
else if(((event.button.x>545)&&(event.button.x<770))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;
}
}

}
}

//resolution  3 enigme 

else if (x==2)
{
while (continuer)
{

SDL_Event event;
SDL_WaitEvent(&event);


if(event.type==SDL_QUIT)
{


 continuer=0;
}

if(event.type==SDL_MOUSEMOTION)
{
if ( event.motion.x>10 && event.motion.x<240 && event.motion.y>500 && event.motion.y<580 )
	 {
		SDL_BlitSurface(reponse000,NULL,fenetre,&reponsepos0);
		SDL_Flip(fenetre);
		}
		else if ( event.motion.x>270 && event.motion.x<500 && event.motion.y>500 && event.motion.y<580 )
		{ 
		SDL_BlitSurface(reponse111,NULL,fenetre,&reponsepos1);
		SDL_Flip(fenetre);
		}
		else if ( event.motion.x>545 && event.motion.x<770 && event.motion.y>500 && event.motion.y<580)
		{
		SDL_BlitSurface(reponse222,NULL,fenetre,&reponsepos2);
		SDL_Flip(fenetre);
		}}
//reponse A 

if(event.button.button==SDL_BUTTON_LEFT)
{
if(((event.button.x>10)&&(event.button.x<240))&&((event.button.y>500)&&
(event.button.y<580)))
{



Mix_PlayMusic(bip,1);
SDL_BlitSurface(win,NULL,fenetre,&winpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;


}

else if(((event.button.x>270)&&(event.button.x<500))&&((event.button.y>500)&&
(event.button.y<580)))
{
Mix_PlayMusic(bip,1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;


}
else if(((event.button.x>545)&&(event.button.x<770))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;
}
}

}
}

//resolution 4 enigme

else if (x==3)
{
while (continuer)
{

SDL_Event event;
SDL_WaitEvent(&event);


if(event.type==SDL_QUIT)
{


 continuer=0;
}

if(event.type==SDL_MOUSEMOTION)
{
if ( event.motion.x>10 && event.motion.x<240 && event.motion.y>500 && event.motion.y<580 )
	 {
		SDL_BlitSurface(reponse0000,NULL,fenetre,&reponsepos0);
		SDL_Flip(fenetre);
		}
		else if ( event.motion.x>270 && event.motion.x<500 && event.motion.y>500 && event.motion.y<580 )
		{ 
		SDL_BlitSurface(reponse1111,NULL,fenetre,&reponsepos1);
		SDL_Flip(fenetre);
		}
		else if ( event.motion.x>545 && event.motion.x<770 && event.motion.y>500 && event.motion.y<580)
		{
		SDL_BlitSurface(reponse2222,NULL,fenetre,&reponsepos2);
		SDL_Flip(fenetre);
		}}
if(event.button.button==SDL_BUTTON_LEFT)
{
//reponse 
if(((event.button.x>10)&&(event.button.x<240))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;


}

else if(((event.button.x>270)&&(event.button.x<500))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(win,NULL,fenetre,&winpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;

}
else if(((event.button.x>545)&&(event.button.x<770))&&((event.button.y>500)&&
(event.button.y<580)))
{


Mix_PlayMusic(bip,1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);
SDL_Delay(300);
continuer=0;
}
}

}
}

}











}

































