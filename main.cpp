//#include <iostream>
#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include "types.h"
//#include <conio.h>
//#include <stdlib.h>
//using namespace std;
#include"prototipos.h"
#include"clases.h"

int main()
{

  OcultarCursor();
  Interfaz();

  NavePro N1(10,7,3,3,DERECHA);
  N1.pintar();
  N1.pintar_corazones();

  /*Asteroide as1(10,20);
  as1.pintar();
  Asteroide as2(10,20);
  as2.pintar();
  Asteroide as3(10,20);
  as3.pintar();
  Asteroide as4(10,20);
  as4.pintar();
*/
  Roca R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,R12,R13,R14,R15,R16,R17,R18,R19,R20;
  Roca conjunto[4][5]={{R1,R2,R3,R4,R5},{R6,R7,R8,R9,R10},{R11,R12,R13,R14,R15},
  {R16,R17,R18,R19,R20}};
  posicion_y y=8;
  for(int i=0;i<4;i++){
    posicion_x x=60;
    y+=5;
    for(int j=0;j<5;j++){
      conjunto[i][j].ingresarX(x);
      conjunto[i][j].ingresarY(y);
      conjunto[i][j].pintar();
      x+=6;
    }
  }

  bool game_over=false;
  while(!game_over){
    N1.mover();
    N1.pintar();
    N1.pintar_corazones();
    R1.impenetrabilidad(N1);R2.impenetrabilidad(N1);R3.impenetrabilidad(N1);
    R4.impenetrabilidad(N1);R5.impenetrabilidad(N1);R6.impenetrabilidad(N1);
    R7.impenetrabilidad(N1);R8.impenetrabilidad(N1);R9.impenetrabilidad(N1);
    R10.impenetrabilidad(N1);R11.impenetrabilidad(N1);R12.impenetrabilidad(N1);
    R13.impenetrabilidad(N1);R14.impenetrabilidad(N1);

    /*
    if(kbhit){
      tecla t=getch();
      if(t=='s'){
        L.insertarNodo(N1);
      }
    }
    */
    //L.insertarNodo(N1);


    /*
    as1.mover();as1.choque(N1);
    as2.mover();as2.choque(N1);
    as3.mover();as3.choque(N1);
    as4.mover();as4.choque(N1);
    */
    N1.morir();
    Sleep(55);
  }

  return 0;
}
