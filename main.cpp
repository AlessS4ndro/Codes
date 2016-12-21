#include <iostream>
#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include<list>
#include "types.h"
#include"prototipos.h"
#include"clases.h"

using namespace std;

ostream &operator<< (ostream &o,const NaveGenerica &p);

int main()
{
  list<Bala *> B;
  list< Bala *> C;
  list<Bala *>::iterator it;
  list<Bala *>::iterator et;

  NaveGenerica Apache(20,15);
  NavePro Nexus(10,10,3,3,DERECHA);
  NaveAI AI(70,35,2,2,ARRIBA);

  OcultarCursor();
  Interfaz();
  Nexus.pintar(B);
  Nexus.pintar_corazones();
  AI.pintar(ARRIBA,C);

  bool game_over=false;
  while(!game_over){
    AI.mover();
    AI.pintar(AI.automatizacion(Nexus),C);
    AI.disparo(C,et);
    AI.morir(C);
    Nexus.mover();
    Nexus.pintar(B);
    Nexus.pintar_corazones();
    Nexus.disparo(B,it);
    Nexus.morir(B);
    Sleep(55);
  }

  return 0;
}
