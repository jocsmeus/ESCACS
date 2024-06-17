#include <iostream>
#include <fstream>
//#include "mov_posibles2.h"
#include "partida.h"

using namespace std;

void llegir_tauler(){
    string a;
    ifstream archiu("tauler");
    for(int x=0; x<8; x++){
	getline(archiu, a);
	for(int y=0; y<8; y++)
	    tauler[x][y] = a[y];
    }
    getline(archiu, a);
    if(a[0] == '1') torn = true;
    else torn = false;
}

void dibuixar_tauler(){
    cout << "    0   1   2   3   4   5   6   7  " << endl;
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    for(int x=0; x<8; ++x){
        cout << x << " | ";
	for(auto y : tauler[x]){
            cout << y << " | ";
        }
        cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
    }
}

void mostrar_moviments(){
    char peca;
	if(torn)
    for(int f=0; f<8; f++){
    	for(int g=0; g<8; g++){
	    peca = tauler[f][g];
	    if(peca != '_')
    	    if(peca == 'R'){
	    	for(int x=0; x<8; x++)
		    if(mov_torre(f,g,x,g,true)) cout <<"la torre de "<<f<<" "<<g<<" es pot moure a: "<<x<<" "<<g<< endl;
	    	for(int y=0; y<8; y++)
	    	    if(mov_torre(f,g,f,y,true)) cout <<"la torre de "<<f<<" "<<g<<" es pot moure a: " <<f<<" "<<y<< endl;
	    }else if(peca == 'B'){
		for(int x=0; x<8; x++)
		for(int y=0; y<8; y++)
		    if(mov_alfil(f,g,x,y,true)) cout <<"l'alfil de "<<f<<" "<<g<<" es pot moure a: "<<x<<" "<<y<< endl;
	    }else if(peca == 'Q'){
		for(int x=0; x<8; x++)
		for(int y=0; y<8; y++)
		    if(mov_reina(f,g,x,y,true)) cout <<"la reina de "<<f<<" "<<g<<" es pot moure a: "<<x<<" "<<y<< endl;
	    }else if(peca == 'N'){
		
	        if(mov_caball(f,g,f+2,g+1,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f+2<<" "<<g+1<<endl;
	        if(mov_caball(f,g,f+2,g-1,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f+2<<" "<<g-1<<endl;
	        if(mov_caball(f,g,f-2,g+1,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f-2<<" "<<g+1<<endl;
	        if(mov_caball(f,g,f-2,g-1,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f-2<<" "<<g-1<<endl;
	        if(mov_caball(f,g,f+1,g+2,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f+1<<" "<<g+2<<endl;
	        if(mov_caball(f,g,f+1,g-2,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f+1<<" "<<g-2<<endl;
	        if(mov_caball(f,g,f-1,g+2,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f-1<<" "<<g+2<<endl;
	        if(mov_caball(f,g,f-1,g-2,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f-1<<" "<<g-2<<endl;
	    }else if(peca == 'P'){
		if(mov_peo(f,g,f-1,g,true)) cout <<"el peo de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<" "<<g<<endl;
		if(mov_peo(f,g,f-2,g,true)) cout <<"el peo de "<<f<<" "<<g<<" es pot moure a: "<<f-2<<" "<<g<<endl;
		if(mov_peo(f,g,f-1,g+1,true)) cout <<"el peo de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<" "<<g+1<<endl;
		if(mov_peo(f,g,f-1,g-1,true)) cout <<"el peo de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<" "<<g-1<<endl;
	    }else if(peca == 'K'){
		if(mov_rei(f,g,f+1,g,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f+1<<' '<<g<<endl;
		if(mov_rei(f,g,f-1,g,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<' '<<g<<endl;
		if(mov_rei(f,g,f,g+1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f<<' '<<g+1<<endl;
		if(mov_rei(f,g,f,g-1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f<<' '<<g-1<<endl;

		if(mov_rei(f,g,f+1,g+1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f+1<<' '<<g+1<<endl;
		if(mov_rei(f,g,f+1,g-1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f+1<<' '<<g-1<<endl;
		if(mov_rei(f,g,f-1,g+1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<' '<<g+1<<endl;
		if(mov_rei(f,g,f-1,g-1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<' '<<g-1<<endl;
	    }
	}
    }
	else
	for(int f=0; f<8; f++){
    	for(int g=0; g<8; g++){
	    peca = tauler[f][g];
	    if(peca != '_')
    	    if(peca == 'r'){
	    	for(int x=0; x<8; x++)
		    if(mov_torre(f,g,x,g,true)) cout <<"la torre de "<<f<<" "<<g<<" es pot moure a: "<<x<<" "<<g<< endl;
	    	for(int y=0; y<8; y++)
	    	    if(mov_torre(f,g,f,y,true)) cout <<"la torre de "<<f<<" "<<g<<" es pot moure a: " <<f<<" "<<y<< endl;
	    }else if(peca == 'b'){
		for(int x=0; x<8; x++)
		for(int y=0; y<8; y++)
		    if(mov_alfil(f,g,x,y,true)) cout <<"l'alfil de "<<f<<" "<<g<<" es pot moure a: "<<x<<" "<<y<< endl;
	    }else if(peca == 'q'){
		for(int x=0; x<8; x++)
		for(int y=0; y<8; y++)
		    if(mov_reina(f,g,x,y,true)) cout <<"la reina de "<<f<<" "<<g<<" es pot moure a: "<<x<<" "<<y<< endl;
	    }else if(peca == 'n'){	
	        if(mov_caball(f,g,f+2,g+1,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f+2<<" "<<g+1<<endl;
	        if(mov_caball(f,g,f+2,g-1,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f+2<<" "<<g-1<<endl;
	        if(mov_caball(f,g,f-2,g+1,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f-2<<" "<<g+1<<endl;
	        if(mov_caball(f,g,f-2,g-1,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f-2<<" "<<g-1<<endl;
	        if(mov_caball(f,g,f+1,g+2,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f+1<<" "<<g+2<<endl;
	        if(mov_caball(f,g,f+1,g-2,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f+1<<" "<<g-2<<endl;
	        if(mov_caball(f,g,f-1,g+2,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f-1<<" "<<g+2<<endl;
	        if(mov_caball(f,g,f-1,g-2,true)) cout <<"el caball de "<<f<<" "<<g<<" es pot more a: "<<f-1<<" "<<g-2<<endl;
	    }else if(peca == 'p'){
		if(mov_peo(f,g,f-1,g,true)) cout <<"el peo de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<" "<<g<<endl;
		if(mov_peo(f,g,f-2,g,true)) cout <<"el peo de "<<f<<" "<<g<<" es pot moure a: "<<f-2<<" "<<g<<endl;
		if(mov_peo(f,g,f-1,g+1,true)) cout <<"el peo de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<" "<<g+1<<endl;
		if(mov_peo(f,g,f-1,g-1,true)) cout <<"el peo de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<" "<<g-1<<endl;
	    }else if(peca == 'k'){
		if(mov_rei(f,g,f+1,g,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f+1<<' '<<g<<endl;
		if(mov_rei(f,g,f-1,g,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<' '<<g<<endl;
		if(mov_rei(f,g,f,g+1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f<<' '<<g+1<<endl;
		if(mov_rei(f,g,f,g-1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f<<' '<<g-1<<endl;

		if(mov_rei(f,g,f+1,g+1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f+1<<' '<<g+1<<endl;
		if(mov_rei(f,g,f+1,g-1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f+1<<' '<<g-1<<endl;
		if(mov_rei(f,g,f-1,g+1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<' '<<g+1<<endl;
		if(mov_rei(f,g,f-1,g-1,true))cout <<"el rei de "<<f<<" "<<g<<" es pot moure a: "<<f-1<<' '<<g-1<<endl;
	    }
	}
    }
};

int input(){
	int a=0;
	cin >> a;
	return a;
};

void jugar(){
    bool partida=true;
    int x, y, x1, y1;
    while(partida){
	//trobarrei();
	dibuixar_tauler();
	cout << "el rei esta a: " << xrei << " "<< yrei << endl;
	if(torn)cout << "juguen les blanques" << endl;
	else cout << "juguen les negres" << endl;
	if(escac()){
	    cout << "es escac" << endl;
	    if(posible_moure()){cout << "es mat" << endl; partida=false; break;}
	}else if(posible_moure()){cout << "ofegat" << endl; partida=false; break;}
	// trirar
	
	while(true){
	    cout << "peca1 (x, y): ";
	    cin >> x >> y;
	    cout << "peca2 (x, y): ";
	    cin >> x1 >> y1;
	    if(partida1(x,y,x1,y1,true))break;
	    else cout << "ILEGAL" << endl;
	}
	
    }
};

int main(){
	llegir_tauler();
	trobarrei();
	bool sessio = true;
	int a;
	cout << "========= ESCACS ========" << endl;
	cout << "    1: mostrar posicio" << endl;
	cout << "    2: jugar" << endl;
	cout << "    3: mostrar moviments" << endl;
	cout << "    4: importar posicio" << endl;
	cout << "    5: sortir" << endl;
	while(sessio){
		cout << ">";
		a = input();
		if(a == 1){
			dibuixar_tauler();
			if(torn)cout << "juguen les blanques" << endl;
			else cout << "juguen les negres" << endl;
			trobarrei();
			if(escac()) cout << "es escac" << endl;
			else cout << "no es escac" << endl;
		}else if(a == 2){
			//cout << "error" << endl;
			jugar();
		}else if(a == 3){
			mostrar_moviments();
		}else if(a == 4){
			llegir_tauler();
		}else if(a == 5){
			cout << "ADEU" << endl;
			sessio = false;
		}else cout << "ERROR";
	}
	
    return 0;
}
