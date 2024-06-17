#include "mov_posibles2.h"
#include <vector>
using namespace std;
char coronarblanc = 'Q', coronarnegre = 'q';

struct moviment{
public:
    int x, y, px, py;
    char peca_menjada;
};
vector<moviment> llista_mov(0);

void guardar_mov(int x, int y,int px,int py){
    moviment jugada;
    jugada.x = x;
    jugada.y = y;
    jugada.px = px;
    jugada.py = py;
    jugada.peca_menjada = tauler[px][py];
    llista_mov.push_back(jugada);
};

void moure(int x,int y, int x1, int y1){
    guardar_mov(x,y,x1,y1);
    tauler[x1][y1] = tauler[x][y];
    tauler[x][y] = '_';
    if(torn) torn = false;
    else torn = true;
};

void tornar_enraderre(){
    moviment j = llista_mov.back();
    tauler[j.x][j.y] = tauler[j.px][j.py];
    tauler[j.px][j.py] = j.peca_menjada;
    llista_mov.pop_back();
    if(torn) torn = false;
    else torn = true;
};

bool partida1(int x, int y, int px, int py, bool moure1){
    int xreib=7, yreib=4, xrein=0, yrein=4;
    bool partida = true, moviment_legal = false;
    char peca;
    if(x>=0 && x<8 && y>=0 && y<8 && px>=0 && px<8 && py>=0 && py<8)
    {
	peca = tauler[x][y];
	if(torn)
	{
	    if(peca == 'P' && mov_peo(x,y,px,py,true)){
		if(moure1)
		if(x == 1){
		    guardar_mov(x,y,px,py);
		    tauler[px][py] = coronarblanc;
		    tauler[x][y] = '_';
		    if(torn)torn = false;
		    else torn = true;
		}else moure(x,y,px,py);
		moviment_legal = true;
	    }else if(peca == 'K' && mov_peo(x,y,px,py,true)){
		if(moure1){
		    xreib = px; yreib = py;
		    moure(x,y,px,py);
		}
		moviment_legal = true;
	    }else if(
		    peca == 'R' && mov_reina(x,y,px,py,true)  ||
		    peca == 'N' && mov_caball(x,y,px,py,true) ||
		    peca == 'B' && mov_alfil(x,y,px,py,true)  ||
		    peca == 'Q' && mov_reina(x,y,px,py,true)
		)
	    {
		if(moure1) moure(x,y,px,py);
		moviment_legal = true;
	    }
	    if(moure1){xrei = xrein; yrei=yrein;}
	}
	else
	{
	    if(peca == 'p' && mov_peo(x,y,px,py,true)){
		if(moure1)
		if(x == 6){
		    guardar_mov(x,y,px,py);
		    tauler[px][py] = coronarblanc;
		    tauler[x][y] = '_';
		    if(torn) torn = false;
		    else torn = true;
		}else moure(x,y,px,py);
		moviment_legal = true;
	    }else if(peca == 'k'){
		if(moure1){
		    xrein = px; yrein = py;
		    moure(x,y,px,py);
		}
		moviment_legal = true;
	    }else if(
		    peca == 'r' && mov_reina(x,y,px,py,true)  ||
		    peca == 'n' && mov_caball(x,y,px,py,true) ||
		    peca == 'b' && mov_alfil(x,y,px,py,true)  ||
		    peca == 'q' && mov_reina(x,y,px,py,true)
		)
	    {
		if(moure1) moure(x,y,px,py);
		moviment_legal = true;
	    }
	    if(moure1){xrei=xreib; yrei=yreib;}
	}
    }
    return moviment_legal;
};
