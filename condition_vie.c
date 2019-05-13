#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "vie.h"

void initialiservie(vie *v)
{
v->nb=3;
v->position.x =150;
v->position.y = 50 ;

v->fond1 = IMG_Load("v1.png");
v->fond2 = IMG_Load("v2.png");
v->fond3 = IMG_Load("v3.png");
v->fond4 = IMG_Load("v4.png");
}

void affichervie(vie v,SDL_Surface *fenetre)
{

if(v.nb==3)
{
SDL_BlitSurface(v.fond4,NULL, fenetre,&v.position);

}
if(v.nb==2)
{
SDL_BlitSurface(v.fond3,NULL, fenetre,&v.position);

}
if(v.nb==1)
{
SDL_BlitSurface(v.fond2,NULL, fenetre,&v.position);
}
if(v.nb==0)
{
SDL_BlitSurface(v.fond1,NULL, fenetre,&v.position);


}
}
void liberervie(vie* v)
{
SDL_FreeSurface(v->fond1);
SDL_FreeSurface(v->fond2);
SDL_FreeSurface(v->fond3);
SDL_FreeSurface(v->fond4);


}





