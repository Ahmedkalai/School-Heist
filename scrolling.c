#include "scrolling.h"
BackGround InitBackGround(background back,char lvl[50],char calque[50])
{
  back.image=IMG_Load(lvl);
  back.position.x=0;
  back.position.y=0;
  back.camera.x=0;
  back.camera.y=10;
  back.camera.h=600;
  back.camera.w=1000;
  back.calque=IMG_Load(calque);
  return back;
}
BackGround ScorllingBackGround(BackGround back,int direction,SDL_Rect *pos1,SDL_Rect *pos2,SDL_Rect *Bonus)
{
  if(direction==0)
  {
    if(back.camera.x<6119)
    {
      back.camera.x+=20;
      pos1->x-=20;
      pos2->x-=20;
      Bonus->x-=20;
    }
  }
  else if(direction==1)
  {
    if(back.camera.x>0)
    {
      back.camera.x-=20;
      pos1->x+=20;
      pos2->x+=20;
      Bonus->x+=20;
    }

  }

  return map;
}
void AfficherBackGround(BackGround back,SDL_Surface *screen)
{
  SDL_BlitSurface(map.image,&map.camera,screen,&map.position);
}
