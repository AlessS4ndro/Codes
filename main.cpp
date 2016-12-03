//#include <iostream>
#include <stdio.h>
#include <windows.h>
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

  Nave N1(10,7,3,3,DERECHA);
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
Roca conjunto[4][5]={{R1,R2,R3,R4,R5},{R6,R7,R8,R9,R10},{R11,R12,R13,R14,R15},{R16,R17,R18,R19,R20}};
posicion_y y=8;
for(int i=0;i<4;i++){
  posicion_x x=60;
  y+=5;
  for(int j=0;j<5;j++){
    conjunto[i][j].ingresarX(x);
    conjunto[i][j].ingresarY(y);
    conjunto[i][j].dibujar();
    x+=6;
  }
}
  bool game_over=false;
  while(!game_over){
    N1.morir();
    N1.mover();

    N1.pintar();
    N1.pintar_corazones();
    /*
    as1.mover();as1.choque(N1);
    as2.mover();as2.choque(N1);
    as3.mover();as3.choque(N1);
    as4.mover();as4.choque(N1);
    */
    Sleep(45);
  }

  return 0;
}
