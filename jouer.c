#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
typedef struct back 
{
SDL_Surface *back ;


SDL_Rect backpos ; 
SDL_Rect campos ; 

}back,b ; 

typedef struct perso

{
SDL_Surface* image[2][2];
SDL_Surface* img_int;
SDL_Rect pospersonnage;

}perso;

typedef struct obstacle 
{
SDL_Surface *ob ; 
SDL_Rect posob ; 
} obstacle  ; 

typedef struct obstacl 
{
SDL_Surface *obi ; 
SDL_Rect posob ; 
} obstacl ; 
typedef struct score
{
SDL_Surface *score[6] ; 
SDL_Surface *imgi ; 
SDL_Rect position;

}score;



int main ()
{


//initialisation
int x=0;
SDL_Surface *fenetre=NULL ;
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
 
 if (SDL_Init(SDL_INIT_VIDEO))
  fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

putenv("SDL_VIDEO_CENTERED=1");//on centre la fenetre 

fenetre=SDL_SetVideoMode(704,430,32,SDL_HWSURFACE);
SDL_Flip(fenetre);

SDL_Surface *vie[4], *img ; 

back b;
score s ; 
int si=0;
s.score[0]=IMG_Load("8.png") ; 
s.score[1]=IMG_Load("1.png") ; 
s.score[2]=IMG_Load("2.png") ; 
s.score[3]=IMG_Load("3.png") ; 
s.score[4]=IMG_Load("4.png") ; 
s.score[5]=IMG_Load("5.png") ; 
s.score[6]=IMG_Load("6.png") ; 
s.position.x= 0; 
s.position.y= 0; 
s.imgi=s.score[0] ;
//initback(&b) ;
b.back=IMG_Load("map.jpg") ; 


b.backpos.x=0;
b.backpos.y=0; 
b.campos.x=0;
b.campos.y=0;
b.campos.w=704 ;
b.campos.h=430;

vie[0]=IMG_Load("vie0.png") ; 
vie[1]=IMG_Load("vie1.png") ; 
vie[2]=IMG_Load("vie2.png") ; 
vie[3]=IMG_Load("GameOver.png") ; 
img=vie[0] ; 

 SDL_BlitSurface(img,NULL,fenetre,&b.backpos);       
SDL_BlitSurface(b.back,NULL,fenetre,&b.backpos);
//afficher_Map(b,fenetre) ; 

         perso p; 
//initialiser(&p) ; 
         p.image[0][0]= IMG_Load("persoright.png");
         p.image[0][1]= IMG_Load("persoright2.png");
         
         p.image[1][0]= IMG_Load("persoleft.png");
         p.image[1][1]= IMG_Load("persoleft1.png");
        
         p.pospersonnage.x=0;
         p.pospersonnage.y=300;
         
            p.img_int=p.image[0][0] ;

//afficher(fenetre,p) ;
SDL_BlitSurface(p.img_int,NULL,fenetre,&p.pospersonnage);
SDL_Flip(fenetre);
int continuer=1 ;
int i=0;;
obstacle ob ; 
obstacl ob1,ob2 ; 

ob.ob=IMG_Load("rock.png");
ob.posob.x=400;
ob.posob.y=300; 

ob1.obi=IMG_Load("rocki.png");
ob1.posob.x=900;
ob1.posob.y=300; 

ob2.obi=IMG_Load("rocki1.png");
ob2.posob.x=1500;
ob2.posob.y=300; 


int m=0 ,n=0 ;
SDL_Surface *lv ; 
SDL_Rect poslv ; 

lv=IMG_Load("lv.png") ;  
poslv.x=0 ;
poslv.y=0 ;


while(continuer)
{
SDL_Event event;
SDL_PollEvent(&event);

switch(event.type)
{
    case SDL_QUIT:
        continuer = 0;
        break;

 case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             continuer=0;
             break;


 case SDLK_RIGHT:
       
       if((p.pospersonnage.x>=300)&&(b.campos.x<7000))
         {

           
           
            b.campos.x+=10;
             ob.posob.x-=10;
              ob1.posob.x-=10;
           ob2.posob.x-=10; 

          }else
          {
           
           p.pospersonnage.x+=100;
 

 }
if ( b.campos.x>1830)
{
n=1 ; 

}


if (ob.posob.x==p.pospersonnage.x)
 {

m=1 ; 


  if (p.pospersonnage.y>=280)
 {
m=2;
i++;
s.imgi=s.score[0];
} 
}

printf("%d \n",p.pospersonnage.x) ;
printf("%d pos q\n",b.campos.x) ;
if (ob1.posob.x==p.pospersonnage.x)
 {

m=3; 

s.imgi=s.score[2];
  if (p.pospersonnage.y>=280)
 {
m=4;
i++;
s.imgi=s.score[1];
} 
}
if (ob2.posob.x==p.pospersonnage.x)
 {

s.imgi=s.score[3];
m=5; 
  if (p.pospersonnage.y>=280)
 {
m=6;
i++;
s.imgi=s.score[2];

} 
}
  if(x==0)
 {
x=1 ; 

}
else 
{
x=0 ;
}
p.img_int=p.image[0][x] ;

    
break;

 case SDLK_LEFT:
if(b.campos.x>0)
{

             b.campos.x-=10;
             ob.posob.x+=10;
             ob1.posob.x+=10;
              ob2.posob.x+=10; 

}

else
{
         
             p.pospersonnage.x--;
      
      
}

if(x==0)
 {
x=1 ; 

}
else 
{
x=0 ;
}
p.img_int=p.image[1][x] ;






break ;

case SDLK_UP:


 b.campos.y-=1;
p.pospersonnage.y-=10;
p.img_int=p.image[0][0] ;
break ; 


case SDLK_DOWN:


 b.campos.y+=1;
p.pospersonnage.y+=10;

p.img_int=p.image[0][0] ;
break ; 
}

if ( p.pospersonnage.x < 0 ) {
      p.pospersonnage.x= 0;
    }
    else if ( p.pospersonnage.x > 704-95.72) {
     p.pospersonnage.x = 704-95.72;
    } 


SDL_BlitSurface(b.back,&b.campos,fenetre,NULL) ;
SDL_Delay(50);
if (m==0)
{
 SDL_BlitSurface(ob.ob,NULL,fenetre,&ob.posob);

}
if( (m==1)||(m==2))
{
 SDL_BlitSurface(ob1.obi,NULL,fenetre,&ob1.posob);

}
if( (m==1)||(m==2)||(m==3)||(m==4))
{
 SDL_BlitSurface(ob2.obi,NULL,fenetre,&ob2.posob);

}
if(m==2) 
{

img=vie[i] ; 
}
if(m==4) 
{

img=vie[i] ; 
}
if(m==6) 
{

img=vie[i] ; 
}
printf("%d \n", m)  ; 

SDL_BlitSurface(img,NULL,fenetre,&b.backpos);

SDL_BlitSurface(s.imgi,NULL,fenetre,&s.position);

if(i!=3) 
{
SDL_BlitSurface(p.img_int,NULL,fenetre,&p.pospersonnage);
}
if(n==1)
{
SDL_BlitSurface(lv,NULL,fenetre,&poslv);
}
  
        

SDL_Flip(fenetre);
SDL_Delay(50);
}

}
int j ; 
SDL_FreeSurface(fenetre) ; 
//liberer_player(&p) ;

for (i=0;i<=1;i++) 
{
for (j=0;j<=1;j++) 
{
SDL_FreeSurface(p.image[i][j]) ; 
}
}
SDL_FreeSurface(b.back) ; 
SDL_Quit;
return 0 ; 

}
