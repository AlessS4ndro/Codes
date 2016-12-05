//#include "clases.h"

class Nodo
{
public:
  Bala *Bala;
  Nodo *siguiente;
};

class ListaEnlazada
{
public:
  int contador;
  Nodo *cabeza;
  ListaEnlazada(){cabeza=NULL;contador=0;}
  ~ListaEnlazada(){}
  void borrarNodo();
  void insertarNodo(NaveGenerica);
};

void ListaEnlazada::insertarNodo(NavePro N)
{
  contador++;
  Bala *B=new(class Bala);
  B->modificarX(N.X());
  B->modificarY(N.Y());

  Nodo *t,*q=new( Nodo);
  q->Bala=B;
  q->siguiente=NULL;
  if(cabeza==NULL)
  {
    cabeza=q;
  }
  else
  {
    t=cabeza;
    while(t->siguiente!=NULL)
    {
      t=t->siguiente;
    }
    t->siguiente=q;
  }
}
void ListaEnlazada::borrarNodo()
{
  if(cabeza==NULL)
    ;
    //cout<<" ^^La lista enlazada se encuentra vacia^^ "<<endl;
  else{
      delete cabeza;
      cabeza=cabeza->siguiente;
  }
}
