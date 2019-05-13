#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"



//pour passer d'un backgroud(de niveau) à un autre il faut qu'un des personnage(deux personnages) resoud l'enigme

typedef struct back
{
SDL_Surface *back;
SDL_Rect backpos;
} back;
typedef struct pers
{
SDL_Surface *pers;
int vie ;
} pers;

void initback( back* back)
{
//creation background
back->back=IMG_Load("map.jpg");

back->backpos.x=0;
back->backpos.y=0;

}


void affichage( back back,SDL_Surface* fenetre,pers personnage)
{
  SDL_BlitSurface((back.back),NULL,fenetre,&(back.backpos));
SDL_Flip(fenetre);

}
void liberation_back(back* back)
{
SDL_FreeSurface(back->back);
}

int main ()
{
back back;
back.back=IMG_Load("map.jpg");
SDL_Surface *fenetre=NULL;
pers personnage;

//initiation de la video
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

putenv("SDL_VIDEO_CENTERED=1");//on centre la fenetre 

//creation fenetre
fenetre=SDL_SetVideoMode(1140,550,32,SDL_HWSURFACE);
SDL_Flip(fenetre);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));//pour remplir l'ecran
SDL_Flip(fenetre);

initback(&back);
affichage(back,fenetre,personnage);
liberation_back(&back);
SDL_Delay(5000);



}
