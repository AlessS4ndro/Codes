#include<iostream>
#include<stdio.h>
using namespace std;

#include"clases.h"
#include"windows.h"
#include"conio.h"
#include"prototipos.h"


void Asteroide::choque(class Nave &N)
{
  if(x>=N.X() && x<=N.X()+6 && y>=N.Y() && y<=N.Y()+2){
    N.corazon();
    N.borrar();
    N.pintar();
    x=rand()%142+4;
    y=4;
  }

}
void Asteroide::pintar()
{
  GoPos(x,y);printf("%c",184);
}
void Asteroide::mover()
{
  GoPos(x,y);printf(" ");
  y++;
  if(y>36){
    x=rand()%142+4;
    y=4;
  }
  pintar();
}



void Nave::pintar()
{
  if(kbhit()){
      d=getch();
  }
      switch(d){
        case ARRIBA:
                if(y>34)y=y-2;
                GoPos(x-2,y);  printf("  %c",94);
                GoPos(x-2,y+1);printf(" %c%c%c",179,207,179);
                GoPos(x-2,y+2);printf("%c%c %c%c",188,207,207,200);
                break;
        case ABAJO:
                if(y<6)y=y+2;
                GoPos(x-2,y-2);  printf("%c%c %c%c",187,207,207,201);
                GoPos(x-2,y-1);printf(" %c%c%c",179,207,179);
                GoPos(x-2,y);printf("  %c ",190);
                break;
        case DERECHA:
                if(x<6)x=x+2;
                GoPos(x-3,y-2);printf("%c",200);
                GoPos(x-3,y-1); printf(" %c%c",207,196);
                GoPos(x-3,y);   printf("  %c%c",207,62);
                GoPos(x-3,y+1); printf(" %c%c",207,196);
                GoPos(x-3,y+2); printf("%c",201);
                break;
        case IZQUIERDA:
                if(x>144)x=x-2;
                GoPos(x,y-2);printf("  %c",188);
                GoPos(x,y-1);printf(" %c%c",196,207);
                GoPos(x,y);printf("%c%c",60,207);
                GoPos(x,y+1);printf(" %c%c",196,207);
                GoPos(x,y+2);printf("  %c",187);
                break;
        case 'a':a=b;d=a;break;
      }
      b=d;
}

void Nave::mover()
{
      borrar();
      if(a==ARRIBA && y>4) y--;
      if(a==ABAJO && y<36) y++;
      if(a==IZQUIERDA && x>4) x--;

      if(a==DERECHA && x<146) x++;
      if(d=='g') c--;
      //pintar();
      //pintar_corazones();


}
void Nave::borrar()
{
  switch(d){
    case ARRIBA:GoPos(x-2,y);  printf("      ");
                GoPos(x-2,y+1);printf("      ");
                GoPos(x-2,y+2);printf("      ");
                break;
    case ABAJO:GoPos(x-2,y-2);printf("      ");
              GoPos(x-2,y-1); printf("      ");
              GoPos(x-2,y);   printf("      ");
              break;
    case DERECHA:GoPos(x-3,y-2);printf("   ");
                  GoPos(x-3,y-1);printf("   ");
                  GoPos(x-3,y);printf("    ");
                  GoPos(x-3,y+1);printf("   ");
                  GoPos(x-3,y+2);printf("   ");
                  break;
    case IZQUIERDA:GoPos(x,y-2);   printf("   ");
                  GoPos(x,y-1);printf("   ");
                  GoPos(x,y);printf("    ");
                  GoPos(x,y+1);printf("   ");
                  GoPos(x,y+2);printf("   ");
                  break;


  }

}
void Nave::pintar_corazones()
{
  GoPos(75,2);printf("VIDAS  %d",v);
  GoPos(87,2);printf("Salud: ");
  GoPos(95,2);printf("       ");
  for(int i=0;i<c;i++){
    GoPos(95+i,2);printf("%c",157);
  }
}

void Nave::morir()
{
  if(c==0){
    v--;
    borrar();
    GoPos(x,y);	 printf("  **  ");
    GoPos(x,y+1);printf(" ****  ");
    GoPos(x,y+2);printf("  **  ");
    Sleep(250);

    borrar();
    GoPos(x,y);	 printf("* ** *");
    GoPos(x,y+1);printf(" **** ");
    GoPos(x,y+2);printf("* ** *");
    Sleep(250);

    GoPos(x,y);	 printf("      ");
    GoPos(x,y+1);printf("      ");
    GoPos(x,y+2);printf("      ");

    pintar();
    c=3;
    pintar_corazones();
  }
}
void Roca::dibujar()
{
  GoPos(x-1,y-1);printf("%c%c%c",201,203,187);
  GoPos(x-1,y);printf("%c%c%c",204,184,185);
  GoPos(x-1,y+1);printf("%c%c%c",200,202,188);
}
