#include <stdio.h>
#include <stdlib.h>

int main()
{


//initialisation
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());
//
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));
SDL_Flip(fenetre);
//
SDL_Surface*  tab[5];
  tab[0]=IMG_Load("enigme1.png");
  tab[1]=IMG_Load("enigme2.png");
  tab[2]=IMG_Load("enigme3.png");
  tab[3]=IMG_Load("enigme4.png");
  tab[4]=IMG_Load("enigme5.png");
SDL_Rect posenig,reponsepos0,reponsepos1,reponsepos2,winpos;
 posenig.x=0;
  posenig.y=0;
  reponsepos0.x=10;
  reponsepos0.y=500;
   reponsepos1.x=270;
  reponsepos1.y=500;
   reponsepos2.x=545;
  reponsepos2.y=500;
  winpos.x=0;
  winpos.y=0;
  overpos.x=0;
  overpos.y=0;
  reponse0=IMG_Load("clic.png");
  reponse1=IMG_Load("clic.png");
  reponse2=IMG_Load("clic.png");
  win=IMG_Load("win.png");
  over=IMG_Load("over.png");



  //affichage de l'enigme
int x=rand() % 5;
  SDL_BlitSurface(tab[x],NULL,fenetre,&posenig)
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
while (continuer)
{
SDL_Event event;
SDL_WaitEvent(&event);

if(event.button.button==SDL_BUTTON_LEFT)
{
if(((event.button.x>10)&&(event.button.x<240))&&((event.button.y>500)&&
(event.button.y<580))|| (SDLK_A ) ||(SDLK_a))
{
{

Mix_PlayMusic(bip,1);
SDL_BlitSurface(reponse0,NULL,fenetre,&reponsepos0);
SDL_BlitSurface(win,NULL,fenetre,&winpos);
SDL_Flip(fenetre);
}

else if(((event.button.x>270)&&(event.button.x<500))&&((event.button.y>500)&&
(event.button.y<580))|| (SDLK_B ) ||(SDLK_b))
{
{

Mix_PlayMusic(bip,1);
SDL_BlitSurface(reponse1,NULL,fenetre,&reponsepos1);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);

}
else if(((event.button.x>545)&&(event.button.x<770))&&((event.button.y>500)&&
(event.button.y<580))|| (SDLK_C ) ||(SDLK_c))
{
{

Mix_PlayMusic(bip,1);
SDL_BlitSurface(reponse2,NULL,fenetre,&reponsepos2);
SDL_BlitSurface(over,NULL,fenetre,&overpos);
SDL_Flip(fenetre);

}
;

  /********************************************************************************************************/

    return
}
