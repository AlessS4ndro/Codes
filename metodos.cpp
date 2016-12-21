#include<iostream>
#include<stdio.h>
#include<math.h>
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

void NaveGenerica::mover(direccionales tecla)
{
      borrar();
      if(tecla==ARRIBA && y>4) y--;
      if(tecla==ABAJO && y<34) y++;
      if(tecla==IZQUIERDA && x>4) x--;
      if(tecla==DERECHA && x<141) x++;
      pintar();

}
void NaveGenerica::borrar()
{
  GoPos(x,y);  printf("      ");
  GoPos(x,y+1);printf("      ");
  GoPos(x,y+2);printf("      ");
}
void NaveGenerica::disparo(list<Bala *> P,list<Bala *>::iterator ite)
{
  for(ite=P.begin();ite!=P.end();ite++){
    (*ite)->mover();
    if((*ite)->fuera()){
      GoPos((*ite)->X(),(*ite)->Y());cout<<" ";
      delete (*ite);
      ite=P.erase(ite);
    }
  }
}
void Asteroide::choque(class NavePro &N)
{
  if(x>=N.X() && x<=N.X()+6 && y>=N.Y() && y<=N.Y()+2){
    N.corazon();
    N.borrar();
    //N.pintar();
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
void NavePro::pintar(list<Bala*> &bala)
{
  if(kbhit()){
      d=getch();
  }
  if(d!=ARRIBA&&d!=ABAJO&&d!=IZQUIERDA&&d!=DERECHA&&d!='a'&&d!='s'){
    d=aux;
  }
      switch(d){
        arr: case ARRIBA:
                if(y>34)y=y-2;
                if(x<6)x=x+4;
                if(x>143)x=x-4;
                GoPos(x-2,y);  printf("  %c",94);
                GoPos(x-2,y+1);printf(" %c%c%c",179,207,179);
                GoPos(x-2,y+2);printf("%c%c %c%c",188,207,207,200);
                aux=d;break;
        aba: case ABAJO:
                if(y<6)y=y+2;
                if(x<6)x=x+4;
                if(x>143)x=x-4;
                GoPos(x-2,y-2);  printf("%c%c %c%c",187,207,207,201);
                GoPos(x-2,y-1);printf(" %c%c%c",179,207,179);
                GoPos(x-2,y);printf("  %c ",190);
                aux=d;break;
        dere: case DERECHA:
                if(x<6)x=x+2;
                if(y<6)y=y+3;
                if(y>34)y=y-3;
                GoPos(x-3,y-2);printf("%c",200);
                GoPos(x-3,y-1); printf(" %c%c",207,196);
                GoPos(x-3,y);   printf("  %c%c",207,62);
                GoPos(x-3,y+1); printf(" %c%c",207,196);
                GoPos(x-3,y+2); printf("%c",201);
                aux=d;break;
        izq: case IZQUIERDA:
                if(x>144)x=x-2;
                if(y<6)y=y+3;
                if(y>34)y=y-3;
                GoPos(x,y-2);printf("  %c",188);
                GoPos(x,y-1);printf(" %c%c",196,207);
                GoPos(x,y);printf("%c%c",60,207);
                GoPos(x,y+1);printf(" %c%c",196,207);
                GoPos(x,y+2);printf("  %c",187);
                aux=d;break;
        case 'a':a=aux;d=a;
                if(a==ARRIBA)goto arr;
                if(a==ABAJO)goto aba;
                if(a==DERECHA)goto dere;
                if(a==IZQUIERDA)goto izq;

        case 's':d=aux;
                bala.push_back(new Bala(x,y,d));
                if(d==ARRIBA)goto arr;
                if(d==ABAJO)goto aba;
                if(d==DERECHA)goto dere;
                if(d==IZQUIERDA)goto izq;

      }
}
void NavePro::mover()
{
      borrar();
      if(a==ARRIBA && y>6)y--;
      if(a==ABAJO && y<34) y++;
      if(a==IZQUIERDA && x>7) x--;
      if(a==DERECHA && x<143) x++;
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

void NavePro::morir(list<Bala*> P)
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

    pintar(P);
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
void Bala::mover()
{
  switch(direccion){
    case ARRIBA:GoPos(x,y);
        cout<<" ";
        if(y>6){
          y--;
          GoPos(x,y);
          cout<<"*";
        }
        break;
    case ABAJO:GoPos(x,y);
        cout<<" ";
        if(y<34){
           y++;
           GoPos(x,y);
           cout<<"*";
        }
        break;
    case IZQUIERDA:GoPos(x,y);
        cout<<" ";
        if(x>5){
          x--;
          GoPos(x,y);
          cout<<"*";
        }
          break;
    case DERECHA:GoPos(x,y);
        cout<<" ";
        if(x<145){
          x++;
          GoPos(x,y);
          cout<<"*";
        }
        break;
  }
}
bool Bala::fuera()
{
  switch(direccion){
    case ARRIBA:if(y<6)return true;else return false;break;
    case ABAJO:if(y>34)return true;else return false;break;
    case IZQUIERDA:if(x<5)return true;else return false;break;
    case DERECHA:if(x>145)return true;else return false;break;
  }
}
void NaveAI::pintar(direccionales dir,list<Bala*>&bala)
{
  d=dir;
  switch(d){
    arr: case ARRIBA:
            if(y>34)y=y-2;
            if(x<6)x=x+4;
            if(x>143)x=x-4;
            GoPos(x-2,y);  printf("  %c",94);
            GoPos(x-2,y+1);printf(" %c%c%c",179,207,179);
            GoPos(x-2,y+2);printf("%c%c %c%c",188,207,207,200);
            aux=d;break;
    aba: case ABAJO:
            if(y<6)y=y+2;
            if(x<6)x=x+4;
            if(x>143)x=x-4;
            GoPos(x-2,y-2);  printf("%c%c %c%c",187,207,207,201);
            GoPos(x-2,y-1);printf(" %c%c%c",179,207,179);
            GoPos(x-2,y);printf("  %c ",190);
            aux=d;break;
    dere: case DERECHA:
            if(x<6)x=x+2;
            if(y<6)y=y+3;
            if(y>34)y=y-3;
            GoPos(x-3,y-2);printf("%c",200);
            GoPos(x-3,y-1); printf(" %c%c",207,196);
            GoPos(x-3,y);   printf("  %c%c",207,62);
            GoPos(x-3,y+1); printf(" %c%c",207,196);
            GoPos(x-3,y+2); printf("%c",201);
            aux=d;break;
    izq: case IZQUIERDA:
            if(x>144)x=x-2;
            if(y<6)y=y+3;
            if(y>34)y=y-3;
            GoPos(x,y-2);printf("  %c",188);
            GoPos(x,y-1);printf(" %c%c",196,207);
            GoPos(x,y);printf("%c%c",60,207);
            GoPos(x,y+1);printf(" %c%c",196,207);
            GoPos(x,y+2);printf("  %c",187);
            aux=d;break;
    case 'a':a=aux;d=a;
            if(a==ARRIBA)goto arr;
            if(a==ABAJO)goto aba;
            if(a==DERECHA)goto dere;
            if(a==IZQUIERDA)goto izq;

    case 's':d=aux;
            bala.push_back(new Bala(x,y,d));
            if(d==ARRIBA)goto arr;
            if(d==ABAJO)goto aba;
            if(d==DERECHA)goto dere;
            if(d==IZQUIERDA)goto izq;
  }
}
char NaveAI::automatizacion(NavePro N)
{
  int num=rand()%100;
  int dif_x=(N.X()-x);
  int dif_y=(N.Y()-y);
  int menor;if(abs(dif_x)<abs(dif_y))menor=dif_x; else menor=dif_y;

  if(num>=20 && num<40)return 'a';
  if(num>=0 && num<20)return 's';
  if(x<8 && y<9)return DERECHA;
  if(x>142&&y<9)return ABAJO;
  if(x<8 && y>31)return ARRIBA;
  if(x>142&&y>31)return IZQUIERDA;

  if(menor==dif_x){
    if(dif_x>0 && dif_y>0)return ABAJO;
    else
      if(dif_x<0 && dif_y<0)return ARRIBA;
      else
        if(dif_x<0 && dif_y>0)return ABAJO;
        else
          return ARRIBA;
  }
  else{
    if(dif_x>0 && dif_y>0)return DERECHA;
    else
      if(dif_x<0 && dif_y<0)return IZQUIERDA;
      else
        if(dif_x<0 && dif_y>0)return IZQUIERDA;
        else
          return DERECHA;
  }
}
