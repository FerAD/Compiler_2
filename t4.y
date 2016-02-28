%{
#include <stdio.h>
#include <string.h>
#include "tablaSimbolos.h"
#include "arbol.h"
//void recorreArbol();


/*se declara yytext como variable externa de este archivo*/
extern char * yytext;

/*extern int entero;
extern double doble;
extern char *str;	*/

/*inicializo la lista que utilizaremos para crear la tabla de simbolos*/
Lista *lista;

/*Datos en los que voy a guardar los valores*/
char *tipoID;	//guardo el tipo de la variable
char *nombreID;	//guardo el nomre de la variable
int datoEntero;	//guardo el valor entero
float datoFlotante;	//guardo el valor flotante
char *validaTipo;
float valorParaAsignar;	//guardo el valor de las sumas, restas, mult etc que se asignara a alguna variable

%}
%union{
	int entero;
	float flotante;
	char *str;
   	struct Arbol *abb;
}
/*Creo los tokens*/
%token  PARENI PAREND SUMA RESTA MULTI DIVIDE MAYORQ MENORQ 
%token IGUAL PTOYCOMA  THEN  DO BEG END  UNTIL  
%token<entero> NUMENT 
%token<flotante> NUMF
%token<str> INT
%token<str> FLOAT


%token<str> ASIGNACION
%token<str> IF
%token<str> WHILE
%token<str> REPEAT
%token<str> PRINT
%token<str> READ
%token<str> ID


%type<abb> expr
%type<abb> term
%type<abb> factor
%type<abb> expresion
%type<abb> stmt_lst
%type<abb> stmt
%type<abb> opt_stmts


%start prg 

%%
/*mostrarLista recorre la lista para mostrar la tabla de simbolos*/
prg : opt_decls BEG opt_stmts END {
			//interpreta el programa
			printf("\nSALIDA DEL PROGRAMA\n");
			interpreta($3);
			//muestra la lista
			mostrarLista(lista);
			//recorre el arbol
			//printf("...::::ARBOL EN POSTORDEN::::...\n");
			//postorden($3);
			//al terminar imprime la tabla de simbolos y recorre el arbol mostrando los elementos
			printf("\nTERMINO\n");
		}	
;

opt_decls : decls 
		  | {}
;

decls : decls PTOYCOMA dec
	  | dec 
;
/*agregarElemento envia la lista, nombre de id, el tipo de id y un valor*/
dec : tipo ID{
copiaYYtext("ID",yytext);
agregarElemento(lista,nombreID,tipoID,0.0);}
;

tipo : INT {copiaYYtext("TIPO",yytext);/*tipoID = yytext; printf("tipo:%s",yytext);*/}
	 | FLOAT {copiaYYtext("TIPO",yytext);/*tipoID = yytext; printf("tipo:%s",yytext);*/}
;

stmt : factor ASIGNACION expr {
			//controlador para ver si esta ID en la tabla de simbolos
			int control;
			//creo un nuevo arbol y guardo en el el valor de factor sino hago esto me marca error en $1
		   	Arbol aux2;
		   	aux2 = malloc(sizeof(NodoAbb));
		   	aux2 = $1;
		   	//asgino a el arbol el valor de expr
		   	aux2->valor = valorParaAsignar;
		   	//guardo la variable de factor en nombreID
		   	copiaYYtext("ID",aux2->nombre);
		   	//asigno el valor ya sea 0 o 1, 0 si si esta y 1 si no esta 
		   	control = buscar(lista,nombreID); 
		   	//asigno el valor de expr a la lista ligada de la tabla de simbolos
		   	//buscarYasignar(lista,nombreID,aux2);
		   	if(control == 0){
		   		//creo un nuevo nodo y se lo asigno a factor
		   		//nuevo_nodo(1); ---1 es operando
		   		$$ = nuevo_nodo(2,":=");
		   		//inserto
		   		inserta($1,$$,$3);
		   	}
	   		else{
	   			printf("*****ERROR %s no esta declarada\n",yytext);
	   			break;
	   		}


		}
     | IF expresion THEN stmt {
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"if");
     		inserta($2,aux,$4);
     		$$ = aux;
     		
     	}
     | WHILE expresion DO stmt{
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"while");
     		inserta($2,aux,$4);
     		$$ = aux;
     	}
     | REPEAT stmt UNTIL expresion{
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"repeat");
     		inserta($2,aux,$4);
     		$$ = aux;
     	}
     | BEG opt_stmts END {
     		$$ = $2;
     	}
     | PRINT expr {
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"print");
     		inserta($2,aux,NULL);
     		$$ = aux;
     	}
     | READ expr {
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"read");
     		inserta($2,aux,NULL);
     		$$ = aux;
     	}
;

opt_stmts : stmt_lst {
				$$ = $1
			}
		  | {}
;

stmt_lst :  stmt_lst PTOYCOMA stmt {
				//creo un nuevo nodo con valor de nombre ;
				Arbol aux;
				aux = malloc(sizeof(NodoAbb));
				aux = nuevo_nodo(2,";");
				$$ = aux;
				inserta($1,aux,$3);
	 			
		 	}
		 | stmt {
		 		$$ = $1;
		 	}
;

expresion : expr MENORQ expr{
				//variable de control para ver si los tipos son iguales o no
		 		int control;
		 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
		 		control = validaTipos($1,$3);
		 		if(control == 0){
		 			//se crea un nuevo nodo Operador
		 			$$ = nuevo_nodo(2,"<");
		 			inserta($1,$$,$3);
		 			
		 		}else{
		 			printf("*****Error, Conflicto de tipos\n");
		 		}
			}
 		  | expr MAYORQ expr {
				//variable de control para ver si los tipos son iguales o no
		 		int control;
		 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
		 		control = validaTipos($1,$3);
		 		if(control == 0){
		 			//se crea un nuevo nodo Operador
		 			$$ = nuevo_nodo(2,">");
		 			inserta($1,$$,$3);
		 			
		 		}else{
		 			printf("*****Error, Conflicto de tipos\n");
		 		}
			}
 		  | expr IGUAL expr{
				//variable de control para ver si los tipos son iguales o no
		 		int control;
		 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
		 		control = validaTipos($1,$3);
		 		if(control == 0){
		 			//se crea un nuevo nodo Operador
		 			$$ = nuevo_nodo(2,"=");
		 			inserta($1,$$,$3);
		 			
		 		}else{
		 			printf("*****Error, Conflicto de tipos\n");
		 		}
			}
 		  	
		  
;

expr : expr SUMA term{
			//variable de control para ver si los tipos son iguales o no
	 		int control;
	 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
	 		control = validaTipos($1,$3);
	 		if(control == 0){
	 			//se crea un nuevo nodo Operador
	 			$$ = nuevo_nodo(2,"+");
	 			inserta($1,$$,$3);
	 			//checo si es entero o flotante para hacer la suma y guardar el valor
	 			if(validaTipo == "int"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = $1;
     				aux2 = $3;
     				valorParaAsignar = aux1->valor + aux2->valor;
	 			}
	 			if(validaTipo == "float"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = $1;
     				aux2 = $3;
     				valorParaAsignar = aux1->valor + aux2->valor;
	 			}

	 		}else{
	 			printf("*****Error, Conflicto de tipos\n");
	 		}
	 		
		}
	 | expr RESTA term{
	 		//variable de control para ver si los tipos son iguales o no
	 		int control;
	 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
	 		control = validaTipos($1,$3);
	 		if(control == 0){
	 			//se crea un nuevo nodo Operador
	 			$$ = nuevo_nodo(2,"-");
	 			inserta($1,$$,$3);

	 			//checo si es entero o flotante para hacer la suma y guardar el valor
	 			if(validaTipo == "int"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = $1;
     				aux2 = $3;
	 				valorParaAsignar = aux1->valor - aux2->valor;
	 			}else if(validaTipo == "float"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = $1;
     				aux2 = $3;
	 				valorParaAsignar = aux1->valor - aux2->valor;
	 			}

	 			
	 		}else{
	 			printf("*****Error, Conflicto de tipos\n");
	 		}
	 	}
	 | term{$$ = $1;}
;

term : term MULTI factor {
			//variable de control para ver si los tipos son iguales o no
	 		int control;
	 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
	 		control = validaTipos($1,$3);
	 		if(control == 0){
	 			//se crea un nuevo nodo Operador
	 			$$ = nuevo_nodo(2,"*");
	 			inserta($1,$$,$3);
	 			//checo si es entero o flotante para hacer la suma y guardar el valor
	 			if(validaTipo == "int"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = $1;
     				aux2 = $3;
	 				valorParaAsignar = aux1->valor * aux2->valor;
	 			}else if(validaTipo == "float"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = $1;
     				aux2 = $3;
	 				valorParaAsignar = aux1->valor * aux2->valor;
	 			}

	 			
	 		}else{
	 			printf("*****Error, Conflicto de tipos\n");
	 		}
		}
	 | term DIVIDE factor {
	 		//variable de control para ver si los tipos son iguales o no
	 		int control;
	 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
	 		control = validaTipos($1,$3);
	 		if(control == 0){
	 			//se crea un nuevo nodo Operador
	 			$$ = nuevo_nodo(2,"/");
	 			inserta($1,$$,$3);
	 			//checo si es entero o flotante para hacer la suma y guardar el valor
	 			if(validaTipo == "int"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = $1;
     				aux2 = $3;
	 				valorParaAsignar = aux1->valor / aux2->valor;
	 			}else if(validaTipo == "float"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = $1;
     				aux2 = $3;
	 				valorParaAsignar = aux1->valor / aux2->valor;
	 			}

	 			
	 		}else{
	 			printf("*****Error, Conflicto de tipos\n");
	 		}
	 	}
	 | factor 	{
	 				$$ = $1;
	 			}
;

factor : PARENI expr PAREND {$$ = $2}
	   | ID {
	   		//variable d econtrol para ver si esta o no la variable dentro de la tabla de simbolos
		   	int control;
		   	//asigno el valor ya sea 0 o 1, 0 si si esta y 1 si no esta 
		   	control = buscar(lista,yytext); 
		   	if(control == 0){
		   		//creo un nuevo nodo y se lo asigno a factor
		   		//nuevo_nodo(1); ---1 es operando
		   		$$ = nuevo_nodo(1,nombreID);
		   		inserta(NULL,$$,NULL);
		   	}
	   		else{
	   			printf("*****ERROR %s no esta declarada\n",yytext);
	   			break;
	   		}
   		}
	   | NUMENT {

	   		//guardo el valor de yytext en una variable global entera 
	   		copiaYYtext("NUMENT",yytext);
	   		//creo un nodo 
	   		//nuevo_nodo(1); ---1 es operando
	   		$$ = nuevo_nodo(1,nombreID);
	   		inserta(NULL,$$,NULL);
	   		
		}
	   | NUMF {
	   		//guardo el valor de yytext en una variable golbal flotante 
	   		copiaYYtext("NUMF",yytext);
	   		//creo el nodo
	   		//nuevo_nodo(1); ---1 es operando
	   		$$ = nuevo_nodo(1,nombreID);
	   		inserta(NULL,$$,NULL);
	   		
		}
;

%%

int yyerror(char const * s) {
  fprintf(stderr, "%s\n", s);
}

/*********METODOS DE LA LISTA**********/

//***Metodo para inicializar la lista de la tabla de simbolos***
void inicializar(Lista *lista){
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->tamanio = 0;
}

//***Metodo para agregar un elemento a la lista de la tabla de simbolos****
int agregarElemento(Lista *lista, char *nomb,char *tip, double val){
	//Creo un nuevo elemento
	Elemento *e;
	//Asigno espacio a dicho elemento nuevo
	if((e = (Elemento *) malloc(sizeof(Elemento))) == NULL){
		printf("Error asignar espacio a un nuevo elemento de la tabla de simbolos\n");
		//error al asignar memoria regresa 1
		return 1;	
	}else{
		//asigno a ese nuevo elemento, el nombre, el tipo y el valor
		e->nombre = nomb;
		e->tipo = tip;
		e->valor = val;
		//si es el primer elemento de la lista entre en el if
		if(lista->inicio == NULL){
			e->siguiente = NULL;
			lista->inicio = e;
			lista->fin = e;
			lista->tamanio++;
			return 0;
		}
		//si no es el primer elemento de la lista entrea en el else
		else{	
			e->siguiente = lista->inicio;
			lista->inicio = e;
			lista->tamanio++;
			return 0;

		}
		
	}
}
/****Metodo que muestra la lista de la tabla de simbolos***/
void mostrarLista(Lista *lista){
	//creo un elemento auxiliar para recorrer la lista
	Elemento *aux;
	//lo igualo a el nodo de inicio
	aux = lista->inicio;
	//encabezado de la tabla de simbolos
	printf("******TABLA DE SIMBOLOS******\nTIPO\tNOMBRE\tVALOR\n");
	//mientras haya valores imprime el tipo,nombre y valor de cada elemento y avanza
	while(aux != NULL){
		printf("%s\t%s\t%.f\n",aux->tipo,aux->nombre,aux->valor);
		aux = aux->siguiente;
	}
}

/****Metodo que copia el valor de yytext en cualquiera de las variables globales
 dependiendo que es ya que si lo hago sin este metodo copia todo el codigo***/
void copiaYYtext(char * x,char * valorActual){
	int tamanio;	//variable en la que guardo el tamaño de el valor acutal de yytext
	tamanio = strlen(valorActual);	
	if(x == "ID"){	//si es un ID reservo memoria y copio yytext(valor actual) a nombreID
		nombreID = (char *) malloc(sizeof(tamanio));
		strcpy(nombreID,valorActual);	
	}else if(x == "TIPO"){	//si es un tipo reservo memoria y copio yytext(valor actual) a tipoID
		tipoID = (char *) malloc(sizeof(tamanio));
		strcpy(tipoID,valorActual);
	}else if(x == "NUMENT"){	//si es un entero convierto el valorActual a entero y lo guardo en datoEntero y tambien en nombreID y en tipoID
		datoEntero = atoi(valorActual);
		nombreID = (char *) malloc(sizeof(tamanio));
		strcpy(nombreID,valorActual);
		tipoID = "int";

	}else if(x == "NUMF"){	//si es un flotante convierto el valorActual a float y lo guardo en datoFlotante, tambien guardo su nombre y su tipo como string
		datoFlotante = atof(valorActual);
		nombreID = (char *) malloc(sizeof(tamanio));
		strcpy(nombreID,valorActual);
		tipoID = "float";
	}
	
}
/***Metodo que busca la variable dentro de la tabla de simbolos***/
int buscar(Lista * lista, char * variable){
	//creo un elemento auxiliar para recorrer la lista
	Elemento *aux;
	//lo igualo a el nodo de inicio
	aux = lista->inicio;
	//Mientras aux recorre revisa si hay o no un ID con ese nombre
	while(aux != NULL){
		//si hay un valor con ese nombre en la tabla de simbolos regresa 0
		if(strcmp(variable,aux->nombre)==0){
			//guardo el nombre del dato buscado en la variable global nombreID
			nombreID = aux->nombre;	
			//guardo el tipo del dato buscado en la variable global tipoID
			tipoID = aux->tipo;
			return 0;
		}else{
			aux = aux->siguiente;	
		}
		
	}

	return 1;	//si no encuentra un valor con el mismo nombre regresa 1
}

int buscarYasignar(Lista * lista, char * variable, Arbol a){
	//creo un elemento auxiliar para recorrer la lista
	Elemento *aux;
	//lo igualo a el nodo de inicio
	aux = lista->inicio;
	//Mientras aux recorre revisa si hay o no un ID con ese nombre
	while(aux != NULL){
		//si hay un valor con ese nombre en la tabla de simbolos regresa 0
		if(strcmp(variable,aux->nombre)==0){
			//guardo el valor del arbol en el valor de la variable
			aux->valor = a->valor;
			lista = aux;	
			return 0;
		}else{
			aux = aux->siguiente;	
		}
		
	}

	return 1;	//si no encuentra un valor con el mismo nombre regresa 1
}

/***********METODOS DEL ARBOL***********/

/***Metodo que agrega un nuevo nodo dependiendo si es operador, operando o sentencia***/
Arbol nuevo_nodo(int tipoN,char *n){

	Arbol nodo;
	nodo = malloc(sizeof(NodoAbb));
	
	switch(tipoN){
		//caso de que sean operando no uso la variable n porque ya esta el nombre y el tipo guardadas en nombreID y en tipoID
		case 1:
			nodo->nombre = nombreID;
			nodo->tipoNodo = "Operando";
			nodo->tipoDato = tipoID;
			if(nodo->tipoDato == "int"){
				nodo->valor = datoEntero;
			}else if(nodo->tipoDato == "float"){
				nodo->valor = datoFlotante;
			}
			nodo->izq = NULL;
			nodo->der = NULL;
			return nodo;
			break;
		//caso de que sean operadores si uso la variable n
		case 2:
			nodo->nombre = n;
			nodo->tipoNodo = "Operador";
			nodo->tipoDato = tipoID;
			nodo->izq = NULL;
			nodo->der = NULL;
			break;
		case 3:
			nodo->nombre = n;
			nodo->tipoNodo = "Sentencia";
			nodo->tipoDato = tipoID;
			nodo->izq = NULL;
			nodo->der = NULL;
			break;
	}
	
}
/***Metodo que inserta un arbol con sus respectivas ramas arboles***/
void inserta(Arbol i, Arbol c, Arbol d){
	//ligo los arboles
	c->izq = i;
	c->der = d;
}
/***Metodo que recorre el arbol en postorden***/
void postorden(Arbol a){

	if(a != NULL){
		postorden(a->izq);
		postorden(a->der);
		printf("%s => ",a->nombre);
	}
	
}
/***Metodo que valida los tipos de datos de dos arboles diferentes***/
int validaTipos(Arbol a, Arbol b){
	if(strcmp(a->tipoDato,b->tipoDato) == 0){
		validaTipo = a->tipoDato;
		return 0;
	}
		
			
	return 1;
}
/***Metodo que interpreta el programa***/
void interpreta(Arbol a){
	if(a!=NULL){
		//si lo que lee es un ; recorre el arbol en postorden 
		if(strcmp (a->nombre,";") == 0){
			interpreta(a->izq);
			interpreta(a->der);
		//si lo que lee es un := entonces se manda la funcion asigna para asignar valores
		}else if(strcmp(a->nombre,":=") == 0){
			asigna(a);
		//si lo que se lele es un if entonces manda a llamar a la funcion miif que regresa 0 si es correcto y 1 si es incorrecto
		}else if(strcmp( a->nombre,"if") == 0){
			int res;
			res = miif(a);
			
		}else if(strcmp(a->nombre,"while") == 0){
			int res;
			res = miwhile(a);
			
		}else if(strcmp(a->nombre, "repeat" )==0){
			int res;
			res = mirepeat(a);
			
		}else if(strcmp(a->nombre, "print" )==0){
			int res;
			res = miprint(a);

		}else if(strcmp(a->nombre, "read" )==0){
			int res;
			res = miread(a);
		}
				
		
	}
}

/*Metodo que recupera el valor de un elemento de la lista o tabla de simbolos*/
float recuperaValorDeLista(Lista * lista, char * nombre){
	//creo un elemento auxiliar para recorrer la lista
	Elemento *aux;
	//lo igualo a el nodo de inicio
	aux = lista->inicio;
	//Mientras aux recorre revisa si hay o no un ID con ese nombre
	while(aux != NULL){
		//si hay un valor con ese nombre en la tabla de simbolos regresa 0
		if(strcmp(nombre,aux->nombre)==0){
			return aux->valor;
		}else{
			aux = aux->siguiente;	
		}
		
		
	}

	return 1.0;	//si no encuentra un valor con el mismo nombre regresa 1
}
/*Metodo que guarda un valor leeido de teclado en una variable*/
int miread(Arbol a){
	//variable auxiliar para saber que variable resivira el valor
	Arbol aux;
	aux = malloc(sizeof(NodoAbb));
	//variable auxiliar para guardar el valor leeido
	float val;

	aux = a->izq;
	printf("Read %s...\n",aux->nombre);
	x("%d",&val);
	aux->valor = val;
	buscarYasignar(lista,aux->nombre,aux);
	
	return 0;
}

/*Metodo que imprime*/
int miprint(Arbol a){
	//variable donde se almacenara el valor
	float x;
	//variable arbol auxiliar
	Arbol aux;
	aux = malloc(sizeof(NodoAbb));
	//igualo aux al valor que se imprimira
	aux = a->izq;
	//se recupera el valor del resultado
	x = recuperaValorDeLista(lista,aux->nombre);
	//imprimo
	printf("%.2f\n",x);
}

/*Metodo que simula un if*/
int miif(Arbol a){
	int res;	
	//alido la expresion del lado izquierdo del if
	res = validaExpresion(a->izq);
	//si es correcto entonces interpreto el lado derecho 
	if(res == 0){
		interpreta(a->der);
		return 0;
	//si no es correcto entonces me salgo de la funcion
	}else{
		return 1;
	}
}
/*Ciclo que hace el repeat*/
int mirepeat(Arbol a){
	Arbol aux;
	aux = malloc(sizeof(NodoAbb));

	aux = a->izq;
	int res;
	res = validaExpresion(a->der);
	while (res == 1){
		interpreta(aux);
		res = validaExpresion(a->der);
	}
}
/*Ciclo que hace el while*/
int miwhile(Arbol a){
	//creo un arbol auxiliar
	Arbol aux;
	aux = malloc(sizeof(NodoAbb));
	//lo igualo a la expr del while
	aux = a->der;
	//variable donde voy a guardar si cumple o no la expresion
	int res;
	//valido la expresion del while 
	res = validaExpresion(a->izq);
	while (res == 0){
		interpreta(aux);
		res = validaExpresion(a->izq);
	}
	return res;
}

/*Metodo que valida una expresion*/
int validaExpresion(Arbol a){
	//declaro las variables donde guardare los valores si son ID
	float v1,v2;
	//se crean dos arboles auxiliares
	Arbol val1;
	val1 = malloc(sizeof(NodoAbb));
	Arbol val2;
	val2 = malloc(sizeof(NodoAbb));
	//se guardan los valores del lado izquierdo y derecho del > o < o =
	val1 = a->izq;
	val2 = a->der;
	//declaro las variables para saber si es o no un id
	int res1, res2;
	//busco si el val1 se encuentra en la lista para saber si es un id o un numero
	//si si regesa 0 si no regresa 1
	res1 = buscar(lista,val1->nombre);
	if(res1 == 0){
		//si si es un id recupero su valor de la lsita y lo guardo en v1
		v1 = recuperaValorDeLista(lista, val1->nombre);
	}else if(res1 == 1){
		//si no es un id recupero el valor directamente de val1->valor
		v1 = val1->valor;
	}
	//busco si el val2 se encuentra en la lista para saber si es un id o un numero
	res2 = buscar(lista,val2->nombre);
	//si es un id regresa 0 sino regresa 1
	if(res2 == 0){
		//si es un id entonces recupero su valor de la lista (tabla de simbolos)
		v2 = recuperaValorDeLista(lista,val2->nombre);
	}else if(res2 == 1){
		//si es un numero entonces simplemente lo asigno a v2
		v2 = val2->valor;
	}	

	//si el operador es un <
	if(strcmp(a->nombre,"<") == 0){
		//se evaluan los dos valores si es correcto regresa 0 sino 1
		if(v1 < v2)
			return 0;
		else return 1;
	//si el operador es un >
	}else if(strcmp(a->nombre,">") == 0){
		//se evaluan los dos valores si es correcto regresa 0 sino 1
		if(v1 > v2)
			return 0;
		else return 1;
	//si el operador es un =
	}else if(strcmp(a->nombre,"=") == 0){
		//se evaluan los dos valores si es correcto regresa 0 sino 1
		if(v1 == v2)
			return 0;
		else return 1;
	}
}

/*Metodo que recorre el lado derecho de una asignacion 
para sacar el valor de la variable ENTERA*/
int iExpr(Arbol a){
	//creo dos arboles auxiliares donde guardare el valor izquierdo y el valor derecho
	Arbol val1;
	val1 = malloc(sizeof(NodoAbb));
	Arbol val2;
	val2 = malloc(sizeof(NodoAbb));
	Arbol operador;
	operador = malloc(sizeof(NodoAbb));
		//guardo los valores del operador, el valor izquierdo y el valor derecho
		operador = a;
		val1 = a->izq;
		val2 = a->der;
		// si dentro del valor existe otra expresion entonces hace recursion 
		if(strcmp(val1->tipoNodo,"operador") == 0){
			iExpr(val1);
		}else {
			int res = -1;
			//si no hay mas expresiones entonces busca en la lista para ver si es un ID o un numero 
			res = buscar(lista,val1->nombre);
			//si es un id entonces recupero el valor de ese ID y lo guardo en valorParaAsignar
			if(res == 0){
				int x = (int) recuperaValorDeLista(lista, val1->nombre);
				valorParaAsignar = (float)x;
			}else if(res == 1){
			//si no es un ID entonces simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = val1->valor;
			}

		}	
		//pasamos con el segundo valor, hago un if para saber si el lado derecho tiene una expr
		if(strcmp(val2->tipoNodo,"operador") == 0){
			//si si hago recursion
			iExpr(val2);
		//si no entonces si el operado es una suma
		}else if(strcmp(operador->nombre,"+") == 0){	
			//checo que el segundo valore no sea un ID
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0 
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				int x = (int) recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar + (float)x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar + val2->valor;
			}
			//retorno el valor
			return (int)valorParaAsignar;
		//si el operador es una resta
		}else if(strcmp(operador->nombre,"-") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				int x = (int) recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar - (float)x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar - val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
			//si el operador es una multiplicacion
		}else if(strcmp(operador->nombre,"*") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				int x = (int) recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar * (float)x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar *  val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
			//si el operador es una div
		}else if(strcmp(operador->nombre,"/") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				int x = (int) recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar / (float)x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar / val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
		}

	return 1;
}

/*Metodo que recorre el lado derecho de una asignacion 
para sacar el valor de la variable FLOTANTE*/
float fExpr(Arbol a){
	//creo 3 variables arbol auxiliares
	Arbol val1;
	val1 = malloc(sizeof(NodoAbb));
	Arbol val2;
	val2 = malloc(sizeof(NodoAbb));
	Arbol operador;
	operador = malloc(sizeof(NodoAbb));

		//guardo los valores que me importan 
		operador = a;
		val1 = a->izq;
		val2 = a->der;
		//si el valor del lado izquierdo es una expresion hago recursion
		if(strcmp(val1->tipoNodo,"operador") == 0){
			iExpr(val1);
		}else {
			int res = -1;
			//si no hay mas expresiones entonces busca en la lista para ver si es un ID o un numero 
			res = buscar(lista,val1->nombre);
			//si es un id entonces recupero el valor de ese ID y lo guardo en valorParaAsignar
			if(res == 0){
				float x =  recuperaValorDeLista(lista, val1->nombre);
				valorParaAsignar = x;
			}else if(res == 1){
			//si no es un ID entonces simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = val1->valor;
			}
		}
		
		if(strcmp(val2->tipoNodo,"operador") == 0){
			iExpr(val2);
		}else if(strcmp(operador->nombre,"+") == 0){
			//checo que el segundo valore no sea un ID
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0 
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				float x = recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar + x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar + val2->valor;
			}
			//retorno el valor
			return (int)valorParaAsignar;
		//si el operador es una resta
		}else if(strcmp(operador->nombre,"-") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				float x = recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar - x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar -=  val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
			//si el operador es una multiplicacion
		}if(strcmp(operador->nombre,"*") == 0){
						//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				float x = recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar * x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar *  val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
			//si el operador es una div
		}if(strcmp(operador->nombre,"/") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				float x = recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar / x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar / val2->valor;
			}
			//retorno el valor
			return valorParaAsignar;
		}

	
	
	return 1.0;
}

/*Metodo que asigna una expresion a una variable*/
void asigna(Arbol a){
	valorParaAsignar = 0;
	Arbol variable;	//variable Arbol en la que guardo el valor de la variable 
	variable = malloc(sizeof(NodoAbb));
	if(a->izq != NULL){
		variable = a->izq;
		//si es una expresion de tipo entero 
		if(strcmp(a->tipoDato,"int") == 0){
			int x;
			x = iExpr(a->der);
			variable->valor = x;
		//si es una expresion de tipo flotante
		}else if(strcmp(a->tipoDato,"float") == 0){
			float x;
			x = fExpr(a->der);
			variable->valor = x;
		}

		buscarYasignar(lista,variable->nombre,variable);

	}
	
}



int main(){
	
	if((lista = (Lista *) malloc(sizeof(Lista))) == NULL)
		return -1;
	inicializar(lista);

	yyparse();
}