#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"

SDL_Surface*  tab[5];
SDL_Rect posenig,reponsepos0,reponsepos1,reponsepos2,winpos,overpos;
SDL_Surface* reponse0;
SDL_Surface* reponse1;
SDL_Surface* reponse2;
SDL_Surface* win;
SDL_Surface* over;
SDL_Surface *fenetre=NULL;

void initialisation();
int afficher_enigme();
void resolution_enigme();
