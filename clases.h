#include<iostream>
#include<list>
#include"types.h"
#include"prototipos.h"


using namespace std;

class Bala{
  posicion_x x;
  posicion_y y;
  direccionales direccion;
public:
  Bala(posicion_x xb,posicion_y yb,direccionales d):x(xb),y(yb),direccion(d){}
  posicion_x X(){return x;}
  posicion_y Y(){return y;}
  void mover();
  bool fuera();
};
class NaveGenerica
{
  friend ostream &operator<< (ostream &o,const NaveGenerica &p);
protected:
  posicion_x x;
  posicion_y y;
public:
  NaveGenerica(posicion_x X,posicion_y Y):x(X),y(Y){}
  virtual void pintar();
  virtual void mover(direccionales);
  virtual void borrar();
  void disparo(list<Bala*> P,list <Bala*>::iterator ite);
  posicion_x X(){return x;}
  posicion_y Y(){return y;}
  void modificarX(posicion_x a){x=a;}
  void modificarY(posicion_y b){y=b;}
};

class NavePro:public NaveGenerica
{
protected:
  corazones c;
  vidas v;
  direccionales d,a,aux;
public:
  NavePro(posicion_x X,posicion_y Y,corazones cor,vidas vid,direccionales dir)
  :NaveGenerica(X,Y){
  c=cor;v=vid;d=dir;a=dir;aux=dir;
  }
  direccionales A(){return a;}
  direccionales D(){return d;}
  void corazon(){ c--;}
  virtual void pintar(list<Bala*>&);
  void borrar();
  void mover();
  void pintar_corazones();
  void morir(list<Bala*>);
};

class NaveAI:public NavePro
{
public:
  NaveAI(posicion_x X,posicion_y Y,corazones cor,vidas vid,direccionales dir)
  :NavePro(X,Y,cor,vid,dir){};
  void pintar(direccionales,list<Bala*>&);
  char automatizacion(NavePro);
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
