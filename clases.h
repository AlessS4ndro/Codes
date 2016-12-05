#include"types.h"
#include"prototipos.h"

class NaveGenerica
{
protected:
  posicion_x x;
  posicion_y y;
  corazones c;
public:
  NaveGenerica(posicion_x X,posicion_y Y):x(X),y(Y){}
  virtual void pintar();
  virtual void mover();
  virtual void borrar();
};

class NavePro:public NaveGenerica
{
  corazones c;
  vidas v;
  direccionales d,a,aux;
public:
  NavePro(posicion_x X,posicion_y Y,corazones cor,vidas vid,direccionales dir)
  :NaveGenerica(X,Y){
  c=cor;v=vid;d=dir;a=dir;aux=dir;
  }
  posicion_x X(){ return x;}
  posicion_y Y(){ return y;}
  direccionales A(){return a;}
  void modificarX(posicion_x a){x=a;}
  void modificarY(posicion_y b){y=b;}
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
  void choque(class NavePro &N);

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
  void pintar();
  void impenetrabilidad(NavePro &);
};
class Bala{
  posicion_x xb;
  posicion_y yb;
public:
  Bala(posicion_x x,posicion_y y):xb(x),yb(y){}
  Bala(){}
  void modificarX(posicion_x a){xb=a;}
  void modificarY(posicion_y b){yb=b;}
  void mover(NavePro ,Bala *);
  //bool choque(Nave &,Roca &);

};
