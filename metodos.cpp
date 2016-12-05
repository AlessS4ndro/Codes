#include<iostream>
#include<stdio.h>
using namespace std;

#include"clases.h"
#include"windows.h"
#include"conio.h"
#include"prototipos.h"

void NaveGenerica::pintar()
{
  GoPos(x,y);  printf("  %c",94);
  GoPos(x,y+1);printf(" %c%c%c",40,207,41);
  GoPos(x,y+2);printf("%c%c %c%c",60,190,190,62);
}

void NaveGenerica::mover()
{
    if(kbhit()){
      char tecla=getch();
      borrar();
      if(tecla==ARRIBA && y>4) y--;
      if(tecla==ABAJO && y<34) y++;
      if(tecla==IZQUIERDA && x>4) x--;
      if(tecla==DERECHA && x<141) x++;
      pintar();
    }
}
void NaveGenerica::borrar()
{
  GoPos(x,y);  printf("      ");
  GoPos(x,y+1);printf("      ");
  GoPos(x,y+2);printf("      ");
}

void Asteroide::choque(class NavePro &N)
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
void NavePro::pintar()
{
  if(kbhit()){
      d=getch();
  }
      switch(d){
        case ARRIBA:
                if(y>34)y=y-2;
                if(x<6)x=x+4;
                if(x>143)x=x-4;
                GoPos(x-2,y);  printf("  %c",94);
                GoPos(x-2,y+1);printf(" %c%c%c",179,207,179);
                GoPos(x-2,y+2);printf("%c%c %c%c",188,207,207,200);
                break;
        case ABAJO:
                if(y<6)y=y+2;
                if(x<6)x=x+4;
                if(x>143)x=x-4;
                GoPos(x-2,y-2);  printf("%c%c %c%c",187,207,207,201);
                GoPos(x-2,y-1);printf(" %c%c%c",179,207,179);
                GoPos(x-2,y);printf("  %c ",190);
                break;
        case DERECHA:
                if(x<6)x=x+2;
                if(y<6)y=y+3;
                if(y>34)y=y-3;
                GoPos(x-3,y-2);printf("%c",200);
                GoPos(x-3,y-1); printf(" %c%c",207,196);
                GoPos(x-3,y);   printf("  %c%c",207,62);
                GoPos(x-3,y+1); printf(" %c%c",207,196);
                GoPos(x-3,y+2); printf("%c",201);
                break;
        case IZQUIERDA:
                if(x>144)x=x-2;
                if(y<6)y=y+3;
                if(y>34)y=y-3;
                GoPos(x,y-2);printf("  %c",188);
                GoPos(x,y-1);printf(" %c%c",196,207);
                GoPos(x,y);printf("%c%c",60,207);
                GoPos(x,y+1);printf(" %c%c",196,207);
                GoPos(x,y+2);printf("  %c",187);
                break;
        case 'a':a=aux;d=a;break;
      }
      aux=d;
}

void NavePro::mover()
{
      borrar();
      if(a==ARRIBA && y>6)y--;
      if(a==ABAJO && y<34) y++;
      if(a==IZQUIERDA && x>7) x--;

      if(a==DERECHA && x<143) x++;
      //pintar();
      //pintar_corazones();


}
void NavePro::borrar()
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
void NavePro::pintar_corazones()
{
  GoPos(75,2);printf("VIDAS  %d",v);
  GoPos(87,2);printf("Salud: ");
  GoPos(95,2);printf("       ");
  for(int i=0;i<c;i++){
    GoPos(95+i,2);printf("%c",157);
  }
}

void NavePro::morir()
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
void Roca::pintar()
{
  GoPos(x-1,y-1);printf("%c%c%c",201,203,187);
  GoPos(x-1,y);printf("%c%c%c",204,184,185);
  GoPos(x-1,y+1);printf("%c%c%c",200,202,188);
}
void Roca::impenetrabilidad(NavePro &N)
{
  switch(N.A()){
    case ARRIBA:
      if(N.X()==x || N.X()==x-1 || N.X()==x+1){
        if(N.Y()<y+3 && N.Y()>y-2)N.modificarY(N.Y()+1);
      }
      break;
    case ABAJO:
    if(N.X()==x || N.X()==x-1 || N.X()==x+1){
      if(N.Y()>y-3 && N.Y()<y+2)N.modificarY(N.Y()-1);
    }
    break;
    case DERECHA:
    if((N.Y()<y+2) && (N.Y()>y-2)){
      if((N.X()>x-4) && (N.X()<x+2))N.modificarX(N.X()-1) ;
    }
    break;
    case IZQUIERDA:
    if(N.Y()==y || N.Y()==y-1 || N.Y()==y+1){
      if(N.X()<x+3 && N.X()>x-2)N.modificarX(N.X()+1);
    }
    break;
  }
}
void Bala::mover(NavePro N,Bala *b)
{
  switch(N.D()){
    case ARRIBA:;
    case ABAJO:;
    case IZQUIERDA:;
    case DERECHA:;
  }
}
//bool choque::Bala(Nave &N,Roca &R)
