
#ifndef NODOG2_H
#define NODOG2_H


class NodoG{						//definicion de la clase a la que pertenecen los nodos de la lista
private:							
	Tipo dato;		
	int peso;						//atributo que almacena los pesos de cada arco del grafo
	NodoG* punt;					//atributo que permite enlazar este nodo con el siguiente
	
public:								//públicos: métodos
	NodoG();						//constructor
	NodoG(Tipo v);					//constructor con parametro dato
	NodoG(Tipo v, int q);			//constructor con parametro dato y el peso
	NodoG(Tipo v, NodoG* p);		//constructor con parametro dato y direccion a la cual apuntar
	NodoG(Tipo v, int q, NodoG* p);	//constructor con parametro dato, peso y direccion a la cual apuntar
	void setDato(Tipo v);			//actualiza el estado del atributo
	void setPeso(int v);			//actualiza el estado del atributo
	void setPunt(NodoG* v);  		//actualiza el estado del atributo
	Tipo getDato();					//devuelve el estado del atributo
	int getPeso();					//devuelve el estado del atributo
	NodoG* getPunt();				//devuelve el estado del atributo
};

NodoG::NodoG(){	
	setPunt(NULL);
}

NodoG::NodoG(Tipo v): NodoG(){
	setDato(v);
}

NodoG::NodoG(Tipo v, int q): NodoG(v){
	setPeso(q);
}

NodoG::NodoG(Tipo v, NodoG* p){
	setDato(v);
	setPunt(p);
}

NodoG::NodoG(Tipo v, int q, NodoG* p): NodoG(v, q) {
	setPunt(p);
}

void NodoG::setDato(Tipo v){
	dato = v;
}

void NodoG::setPeso(int v){ 
	peso = v;
}

void NodoG::setPunt(NodoG* v){
	punt = v;
}

Tipo NodoG::getDato(){
	return dato;
}

int NodoG::getPeso(){
	return peso;
}

NodoG* NodoG::getPunt(){
	return punt;
}
#endif
