//Estrucutra del elemmento de la tabla de simbolos
typedef struct ElementoLista{
	char *nombre;
	char *tipo;
	float valor;
	struct ElementoLista *siguiente;
}Elemento;
//Estrucutra de la lista que dara seguimiento a la lista de la tabla de simbolos
typedef struct ListaI{
	Elemento *inicio;
	Elemento *fin;
	int tamanio;
}Lista;
//***Metodo para inicializar la lista***
void inicializar(Lista *);
//***Metodo para agregar un elemento a la lista***
int agregarElemento(Lista *, char *, char*, double);
//***Metodo para mostrar la lista***
void mostrarLista(Lista *);
/***Metodo que busca un valor***/
int buscar(Lista *,char *);
/***Metodo copiar yytext a variables globales dependiendo que son 
para que no me copie todo el codigo***/
void copiaYYtext(char *, char *);