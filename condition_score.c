#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "score.h"



void initialiser_score(Score *s)
{

  TTF_Init();
s->compteur = 0;
s->pos.x=500;
s->pos.y=0;

SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};


s->police = TTF_OpenFont("font_chrono.ttf", 65);
s->texte = TTF_RenderText_Shaded(s->police,s->temps, couleurNoire,couleurBlanche);

strcpy(s->temps,"");

}




void afficher_score(SDL_Surface* fenetre,Score s)
{


SDL_BlitSurface(s.texte,NULL,fenetre, &s.pos);
SDL_Flip(fenetre);

        
}

void liberer_score(Score* s)
{
SDL_FreeSurface(s->texte);
 TTF_CloseFont(s->police);


}










