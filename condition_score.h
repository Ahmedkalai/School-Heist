#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


struct Score
{
TTF_Font *police ;
SDL_Surface* texte;
SDL_Rect pos;
int compteur;
char temps[20];

};
typedef struct Score Score;


void liberer_score(Score* s);

void afficher_score(SDL_Surface* fenetre,Score s);

void initialiser_score(Score* s);

