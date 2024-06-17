/* mobiments possibles d'escacs des'de una posició
 * 
 * peces:
 * 	'p': peó blanc
 * 	'r': torre negre
 * 	'n': caball negre
 * 	'b': alfil negre
 * 	'q': reina negre
 * 	'k': rei negre
 *
 *	'P': peó blanc
 *	'R': torre blanc
 *	'N': caball blanc
 *	'B': alfil blanc
 *	'Q': reina blanc
 *	'K': rei blanc
*/

char tauler[8][8];

int xrei, yrei;

bool torn; // = true; // true: juguen les blanques false: jugen les negres
//bool jac = false;
int mov_ant[2][2]; // { {x,y}, {xant,yant} }

bool negre_blanc(int x, int y, int px, int py){
    char peca1 = tauler[x][y];
    if(peca1 != '_' && x >= 0 && y >= 0 && x<8 && y<8 && px >= 0 && py >= 0 && px<8 && py<8){
      char peca = tauler[px][py]; bool blanc = true;
      if(peca1=='p' || peca1=='r' || peca1=='n' || peca1=='b' || peca1=='k' || peca1=='q') blanc = false;
      if(blanc){
	  if(peca=='P' ||  peca=='R' || peca=='N' || peca=='B' || peca=='K' || peca == 'Q')return false;
	  else return true;
      }else{
	  if(peca=='p' ||  peca=='r' || peca=='n' || peca=='b' || peca=='k' || peca=='q')return false;
	  else return true;
      }
    }else return false;
}

bool escac();

bool legal_escac(int x, int y, int px, int py){
    bool gf = true;
    char peca_menjada = tauler[px][py];
    tauler[px][py] = tauler[x][y];
    tauler[x][y] = '_';

    if(escac()) gf = false;
    else gf = true;

    tauler[x][y] = tauler[px][py];
    tauler[px][py] = peca_menjada;
    return gf;
}

bool mov_alfil(int x, int y, int px, int py, bool real){
   if(negre_blanc(x,y,px,py)){
      if(px+py == x+y){
         if(py+1 == y || py-1 == y){
	     if(real)return legal_escac(x,y,px,py);
	     else return true;
	 }else{
	     int inici_bucle=0; int fi_bucle=0; bool a = true;
	     if(py > y){inici_bucle=y; fi_bucle=py;}
	     else{inici_bucle=py; fi_bucle=py;}
	     for(int i=inici_bucle+1; i<fi_bucle; ++i){
	         if(tauler[x+y-i][i] != '_'){a=false; break;}
	     }
	     if(real && a) return legal_escac(x, y, px, py);
	     else return a;
	 }
      }else if(px-py == x-y){
         if(py+1 == y || py-1 == y)return true;
	 else{
             int inici_bucle=0; int fi_bucle=0; bool a = true;
	     if(py > y){inici_bucle=y; fi_bucle=py;}
	     else{inici_bucle=py; fi_bucle=y;}
	     for(int i=inici_bucle+1; i<fi_bucle; ++i){
	         if(tauler[x-y+i][i] != '_'){a=false; break;}
	     }
	     if(real && a) return legal_escac(x, y, px, py);
	     else return a;
	 }
      }else return false;
   }else return false;
}

bool mov_caball(int x, int y, int px, int py, bool real){
  if(negre_blanc(x,y,px,py)){
    if(px+2 == x || px-2 == x){
        if(py-1 == y || py+1 == y){
	    if(real) return legal_escac(x, y, px, py);
	    else return true;
	}else return false;
    }else if(py+2 == y || py-2 == y){
        if(px-1 == x || px+1 == x){
	    if(real) return legal_escac(x, y, px, py);
	    else return true;
        }else return false;
    }else return false;
  }else return false;
}

bool mov_torre(int x, int y, int px, int py, bool real){
  if(negre_blanc(x,y,px,py)){
      int inici_bucle; int fi_bucle; int resta; bool a = true;
      if(px == x && py != y){
          resta = py-y;
          if(resta == 1 || resta == -1) return true;
          else{
              //peces entre mitg
              if(resta < -1){inici_bucle = py; fi_bucle = y;}
              else{inici_bucle = y; fi_bucle = py;}
              for(int i=inici_bucle+1; i<fi_bucle; ++i){
                  if(tauler[x][i] != '_'){a=false; break;}
              }
	      if(real && a) return legal_escac(x, y, px, py);
	      else return a;
          }
      }else if(py == y){
          int resta = px-x;
          if(resta == 1 || resta == -1) return true;
          else{
              //peces entre mitg
              if(resta < -1){inici_bucle = px; fi_bucle = x;}
              else{inici_bucle = x; fi_bucle = px;}
              for(int i=inici_bucle+1; i<fi_bucle; ++i){
                  if(tauler[i][y] != '_'){a=false; break;}
              }
	      if(real && a) return legal_escac(x, y, px, py);
 	      else return a;
          }
      }else return false;
  }else return false;
}

bool mov_reina(int x, int y, int px, int py, bool real){
    if(mov_torre(x,y,px,py,false)) //return true;
	if(real) return legal_escac(x, y, px, py);
 	else return true;
    else if(mov_alfil(x,y,px,py,false))
	if(real) return legal_escac(x, y, px, py);
 	else return true;
    else return false;
}

bool mov_rei(int x, int y, int px, int py, bool real){
    if(negre_blanc(x,y,px,py)){
        if(px-1 == x || px+1 == x || px == x){
            if(py-1 == y || py+1 == y || py == y)
		if(real){xrei=px; yrei=py; return legal_escac(x, y, px, py);}
 		 else return true;
            else return false;
        }else return false;
    }else return false;
}
bool mov_peo(int x, int y, int px, int py, bool real){
    if(x>=0 && x<8 && y>=0 && y<8 && px>=0 && px<8 && py>=0 && py<8){
    char peca = tauler[x][y];
    char peca1 = tauler[px][py];
    bool blanc, a=true;
    if(peca == 'P')blanc = true;
    else if(peca == 'p')blanc = false;
    else return false;

    if(blanc){
        if(peca1 == '_'){
          if(py == y){
            //doble pas
            if(px == 4 && x == 6 && tauler[5][y] == '_'){} //return true;
            else if(px+1 == x){} //return true;
            else return false;
          }else return false;
        }else if(py-1 == y || py+1 == y){
            //captures
            if(px+1 == x){
                if(peca1 == 'p' || peca1 == 'n' || peca1 == 'r' || peca1 == 'n' || peca1 == 'q' || peca1 == 'k'){} //return true;
                else return false;
            }else return false;
        }else return false;
    }else{
        if(peca1 == '_'){
            if(py==y){
              if(px == 3 && x == 1 && tauler[2][y] == '_'){} //return true;
              else if(px-1 == x){} //return true;
              else return false;
            }else return false;
        }else if(py-1 == y || py+1 == y){
            if(px-1 == x){
                if(peca1 == 'P' || peca1 == 'N' || peca1 == 'R' || peca1 == 'N' || peca1 == 'Q' || peca1 == 'K'){} //return true;
                else return false;
            }else return false;
        }else return false;
    }
    if(real) return legal_escac(x, y, px, py);
    else return true;
    }else return false;
}

void trobarrei(){
    bool fi_bucle = false;
    if(torn){
	for(int x=0; x<8; x++){
	    for(int y=0; y<8; y++)
		if(tauler[x][y] == 'K'){xrei=x; yrei=y; fi_bucle = true; break;}
	    if(fi_bucle)break;
	}
    }else{
	for(int x=0; x<8; x++){
	    for(int y=0; y<8; y++)
		if(tauler[x][y] == 'k'){xrei=x; yrei=y; fi_bucle = true; break;}
	    if(fi_bucle)break;
	}
    }
}

bool escac(){
    char peca; bool fi_bucle=false; bool a=false;
    if(torn){
	for(int x=0; x<8; ++x){
	    for(int y=0; y<8; ++y){
		peca = tauler[x][y];
	        if(peca == 'p' && mov_peo(x,y,xrei,yrei,false)){ a=true; break;
		}else if(peca == 'r' && mov_torre(x,y,xrei,yrei,false)){ a=true; break;
		}else if(peca == 'n' && mov_caball(x,y,xrei,yrei,false)){ a=true; break;
		}else if(peca == 'b' && mov_alfil(x,y,xrei,yrei,false)){ a=true; break;
		}else if(peca == 'q' && mov_reina(x,y,xrei,yrei,false)){ a=true; break;
		}else if(peca == 'k' && mov_rei(x,y,xrei,yrei,false)){ a=true; break;
		}
	    }
	    if(a)break;
	}
    }else{
	for(int x=0; x<8; ++x){
	    for(int y=0; y<8; y++){
		peca=tauler[x][y];
		if(
		    peca == 'P' && mov_peo(x,y,xrei,yrei,false)    ||
		    peca == 'R' && mov_torre(x,y,xrei,yrei,false)  ||
		    peca == 'B' && mov_alfil(x,y,xrei,yrei,false)  ||
		    peca == 'N' && mov_caball(x,y,xrei,yrei,false) ||
		    peca == 'Q' && mov_reina(x,y,xrei,yrei,false)  ||
		    peca == 'K' && mov_rei(x,y,xrei,yrei,false)
		){a = true; break;}
	    }
	    if(a)break;
	}
    }
    return a;
}

bool posible_moure(){
	char peca;
	bool fi_joc = true;
	if(torn)
    for(int f=0; f<8; f++){
    	for(int g=0; g<8; g++){
	    peca = tauler[f][g];
	    if(peca != '_')
    	    if(peca == 'R'){
	    	for(int x=0; x<8; x++)
		    if(mov_torre(f,g,x,g,true))fi_joc = false;
	    	for(int y=0; y<8; y++)
	    	    if(mov_torre(f,g,f,y,true)) fi_joc = false;
	    }else if(peca == 'B'){
		for(int x=0; x<8; x++)
		for(int y=0; y<8; y++)
		    if(mov_alfil(f,g,x,y,true)) fi_joc = false;
	    }else if(peca == 'Q'){
		for(int x=0; x<8; x++)
		for(int y=0; y<8; y++)
		    if(mov_reina(f,g,x,y,true))fi_joc = false;
	    }else if(peca == 'N'){
	        if(mov_caball(f,g,f+2,g+1,true)) fi_joc = false;
	        if(mov_caball(f,g,f+2,g-1,true)) fi_joc = false;
	        if(mov_caball(f,g,f-2,g+1,true)) fi_joc = false;
	        if(mov_caball(f,g,f-2,g-1,true)) fi_joc = false;
	        if(mov_caball(f,g,f+1,g+2,true)) fi_joc = false;
	        if(mov_caball(f,g,f+1,g-2,true)) fi_joc = false;
	        if(mov_caball(f,g,f-1,g+2,true)) fi_joc = false;
	        if(mov_caball(f,g,f-1,g-2,true)) fi_joc = false;
	    }else if(peca == 'P'){
		if(mov_peo(f,g,f-1,g,true)) fi_joc = false;
		if(mov_peo(f,g,f-2,g,true)) fi_joc = false;
		if(mov_peo(f,g,f-1,g+1,true)) fi_joc = false;
		if(mov_peo(f,g,f-1,g-1,true)) fi_joc = false;
	    }else if(peca == 'K'){
		if(mov_rei(f,g,f+1,g,true))fi_joc = false;
		if(mov_rei(f,g,f-1,g,true))fi_joc = false;
		if(mov_rei(f,g,f,g+1,true))fi_joc = false;
		if(mov_rei(f,g,f,g-1,true))fi_joc = false;

		if(mov_rei(f,g,f+1,g+1,true))fi_joc = false;
		if(mov_rei(f,g,f+1,g-1,true))fi_joc = false;
		if(mov_rei(f,g,f-1,g+1,true))fi_joc = false;
		if(mov_rei(f,g,f-1,g-1,true))fi_joc = false;
	    }
	    if(!fi_joc)break;
	}
	if(!fi_joc)break;
    }
	else
	for(int f=0; f<8; f++){
    	for(int g=0; g<8; g++){
	    peca = tauler[f][g];
	    if(peca != '_')
    	    if(peca == 'r'){
	    	for(int x=0; x<8; x++)
		    if(mov_torre(f,g,x,g,true))fi_joc = false;
	    	for(int y=0; y<8; y++)
	    	    if(mov_torre(f,g,f,y,true)) fi_joc = false;
	    }else if(peca == 'b'){
		for(int x=0; x<8; x++)
		for(int y=0; y<8; y++)
		    if(mov_alfil(f,g,x,y,true)) fi_joc = false;
	    }else if(peca == 'q'){
		for(int x=0; x<8; x++)
		for(int y=0; y<8; y++)
		    if(mov_reina(f,g,x,y,true))fi_joc = false;
	    }else if(peca == 'n'){
	        if(mov_caball(f,g,f+2,g+1,true)) fi_joc = false;
	        if(mov_caball(f,g,f+2,g-1,true)) fi_joc = false;
	        if(mov_caball(f,g,f-2,g+1,true)) fi_joc = false;
	        if(mov_caball(f,g,f-2,g-1,true)) fi_joc = false;
	        if(mov_caball(f,g,f+1,g+2,true)) fi_joc = false;
	        if(mov_caball(f,g,f+1,g-2,true)) fi_joc = false;
	        if(mov_caball(f,g,f-1,g+2,true)) fi_joc = false;
	        if(mov_caball(f,g,f-1,g-2,true)) fi_joc = false;
	    }else if(peca == 'p'){
		if(mov_peo(f,g,f-1,g,true)) fi_joc = false;
		if(mov_peo(f,g,f-2,g,true)) fi_joc = false;
		if(mov_peo(f,g,f-1,g+1,true)) fi_joc = false;
		if(mov_peo(f,g,f-1,g-1,true)) fi_joc = false;
	    }else if(peca == 'k'){
		if(mov_rei(f,g,f+1,g,true))fi_joc = false;
		if(mov_rei(f,g,f-1,g,true))fi_joc = false;
		if(mov_rei(f,g,f,g+1,true))fi_joc = false;
		if(mov_rei(f,g,f,g-1,true))fi_joc = false;

		if(mov_rei(f,g,f+1,g+1,true))fi_joc = false;
		if(mov_rei(f,g,f+1,g-1,true))fi_joc = false;
		if(mov_rei(f,g,f-1,g+1,true))fi_joc = false;
		if(mov_rei(f,g,f-1,g-1,true))fi_joc = false;
	    }
	    if(!fi_joc)break;
	}
	if(!fi_joc)break;
    }
    return fi_joc;
}
