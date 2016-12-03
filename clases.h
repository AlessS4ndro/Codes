#include"types.h"
#include"prototipos.h"


class Nave
{
  posicion_x x;
  posicion_y y;
  corazones c;
  vidas v;
  direccionales d,a,b;
public:
  Nave(posicion_x X,posicion_y Y,corazones C,vidas V,direccionales D):
  x(X),y(Y),c(C),v(V),d(D),a(D),b(D){}
  posicion_x X(){ return x;}
  posicion_y Y(){ return y;}
  direccionales D(){return d;}
  void corazon(){ c--;}
  void pintar();
  void borrar();
  void mover();
  void pintar_corazones();
  void morir();
};

class Asteroide
{
  int x,y;
public:
  Asteroide(int _x,int _y):x(_x),y(_y){}
  void pintar();
  void mover();
  void choque(class Nave &N);

};
class Roca
{
  posicion_x x;
  posicion_y y;
public:
  Roca(){}
  Roca(posicion_x a,posicion_y b){
    x=a;y=b;
    GoPos(x-1,y-1);printf("%c%c%c",201,203,187);
    GoPos(x-1,y);printf("%c%c%c",204,184,185);
    GoPos(x-1,y+1);printf("%c%c%c",200,202,188);
  }
  void ingresarX(posicion_x a){x=a;}
  void ingresarY(posicion_y b){y=b;}
  posicion_x llamarX(){return x;}
  posicion_y llamarY(){return y;}
  void dibujar();
};
