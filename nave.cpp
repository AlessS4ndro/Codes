#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

void GoPos(int x,int y);
void OcultarCursor();
void Interfaz();


class NAVE
{
	int x,y;
	int corazones,vidas;
public:
	NAVE(int _x,int _y,int _corazones,int _vidas):x(_x),y(_y),corazones(_corazones),vidas(_vidas){}
	int X(){ return x;}
	int Y(){ return y;}
	void corazon(){ corazones--;}
	void pintar();
	void borrar();
	void mover();
	void pintar_corazones();
	void morir();
};

class AST
{
	int x,y;
public:
	AST(int _x,int _y):x(_x),y(_y){}
	void pintar();
	void mover();
	void choque(class NAVE &N);

};
void AST::choque(class NAVE &N)
{
	if(x>=N.X() && x<=N.X()+6 && y>=N.Y() && y<=N.Y()+2){
		N.corazon();
		N.borrar();
		N.pintar();
		x=rand()%142+4;
		y=4;
	}

}
void AST::pintar()
{
	GoPos(x,y);printf("%c",184);
}
void AST::mover()
{
	GoPos(x,y);printf(" ");
	y++;
	if(y>36){
		x=rand()%142+4;
		y=4;
	}
	pintar();
}


void NAVE::pintar()
{
	GoPos(x,y);  printf("  %c",94);
	GoPos(x,y+1);printf(" %c%c%c",40,207,41);
	GoPos(x,y+2);printf("%c%c %c%c",60,190,190,62);
}

void NAVE::mover()
{

		if(kbhit()){
			char tecla=getch();
			borrar();
			if(tecla==ARRIBA && y>4) y--;
			if(tecla==ABAJO && y<34) y++;
			if(tecla==IZQUIERDA && x>4) x--;
			if(tecla==DERECHA && x<141) x++;
			if(tecla=='g') corazones--;
			pintar();
			pintar_corazones();

		}
}
void NAVE::borrar()
{

	GoPos(x,y);  printf("      ");
	GoPos(x,y+1);printf("      ");
	GoPos(x,y+2);printf("      ");
}
void NAVE::pintar_corazones()
{
	GoPos(75,2);printf("VIDAS  %d",vidas);
	GoPos(87,2);printf("Salud: ");
	GoPos(95,2);printf("       ");
	for(int i=0;i<corazones;i++){
		GoPos(95+i,2);printf("%c",157);
	}
}

void NAVE::morir()
{
	if(corazones==0){
		vidas--;
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
		borrar();
		pintar();
		corazones=3;
		pintar_corazones();
	}
}
int main()
{

    OcultarCursor();
    Interfaz();

    NAVE N1(75,34,3,3);
    N1.pintar();
    N1.pintar_corazones();

    AST as1(10,20);
    as1.pintar();
    AST as2(10,20);
    as1.pintar();
    AST as3(10,20);
    as1.pintar();
    AST as4(10,20);
    as4.pintar();

	bool game_over=false;
	while(!game_over){
		N1.morir();
		N1.mover();

		as1.mover();as1.choque(N1);
        as2.mover();as2.choque(N1);
        as3.mover();as3.choque(N1);
		as4.mover();as4.choque(N1);

		Sleep(30);
	}

	return 0;
}

void GoPos(int x,int y)
{

	HANDLE Hcon;
	Hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos;
	Pos.X=x;
	Pos.Y=y;

	SetConsoleCursorPosition(Hcon,Pos);

}

void OcultarCursor()
{
	HANDLE Hcon;
	Hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize=100;
	cci.bVisible=FALSE;

	SetConsoleCursorInfo(Hcon,&cci);
}

void Interfaz()
{
	for (int i=3;i<=147;i++){
		GoPos(i,3);printf("%c",205);
		GoPos(i,37);printf("%c",205);
	}
	for (int i=4;i<=36;i++){
		GoPos(3,i);printf("%c",186);
		GoPos(147,i);printf("%c",186);
	}
	GoPos(3,3);printf("%c",201);GoPos(147,3);printf("%c",187);
	GoPos(3,37);printf("%c",200);GoPos(147,37);printf("%c",188);


}
