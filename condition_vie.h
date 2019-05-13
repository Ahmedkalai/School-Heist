#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


struct vie
{
SDL_Rect position;
SDL_Surface* fond1;
SDL_Surface* fond2;
SDL_Surface* fond3;
SDL_Surface* fond4;
int nb;

};
typedef struct vie vie;

void initialiservie(vie *v);
void affichervie(vie v,SDL_Surface *fenetre);
void liberervie(vie* v);
