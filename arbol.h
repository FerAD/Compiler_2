
/*
tipos de nodos:
	operando: variables, int, float
	operacion: +,-,x,/
	instruccion(stmat) = while,if,do,etc
*/



typedef struct NodoAbb_tag NodoAbb;
typedef NodoAbb * Arbol; 
struct NodoAbb_tag{
	float valor;
	char *nombre;	//nombre de el nodo
	char *tipoNodo; //operador,operando,stmt
	char *tipoDato;	//tipo de dato (int float)
	struct Arbol *izq; // El hijo izquierdo
	struct Arbol *der; // El hijo derecho
};

/* La función nuevo_nodo crea un nuevo nodo que tendrá como dato el número que
   recibe como argumento.
 */
/*Metodo que crea un nuevo nodo, enviando que tipo de nodo es y su nombre*/
Arbol nuevo_nodo(int,char*);

/* La función inserta toma un dato (número entero) y un árbol y hace la
   inserción del dato en el árbol.

   Nota: Observe que el tipo del segundo parámetro no es un árbol sino un
   apuntador a un árbol.
*/
/*Metodo que inserta un arbol con dos arboles ya creados*/
void inserta(Arbol,Arbol,Arbol);

void postorden(Arbol);
/*Metodo que valida los tipos de datos para realizar las operaciones o mandar error 0 si son igulaes 1 si son diferentes*/
int validaTipos(Arbol,Arbol);
