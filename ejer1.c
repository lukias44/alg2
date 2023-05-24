#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo {
    int num;
    struct nodo *sig;
} *nodo;

void crearNodo(nodo *p){
	*p = (nodo)malloc(sizeof(struct nodo));
}

bool esVacia(nodo p){
    return (p == NULL);
}           

void apilar(nodo *p, int x) {
    nodo nuevo;
    crearNodo(&nuevo);
    nuevo->num = x;
    nuevo->sig = *p;
    *p = nuevo;
}

int desapilar(nodo *p) {
    if (esVacia(*p)) {
        printf("\nAviso! La pila esta vacia.\n");
        exit(1);
    }
    nodo nodoAEliminar = *p;
    int elementoAEliminar = (*p)->num;
    *p = (*p)->sig;
    free(nodoAEliminar);
    return elementoAEliminar;
}

void mostrar(nodo p){
	printf("\nContenido Pila: ");
	if(!esVacia(p)){
		while(!esVacia(p)){
			printf("[%d] ",p->num);
			p = p->sig;
		}
	} else {
		printf("La pila esta vacia.");
	}
	printf("\n");
}

void invertir(nodo *p){
	nodo aux = NULL;
	while(*p != NULL){
		apilar(&aux, desapilar(&(*p)));
	}
	mostrar(aux);
	while(aux != NULL){
		apilar(&(*p), desapilar(&aux));
	}
}

int main(int argc, char const *argv[])
{
	nodo cab = NULL;
	int cant = 0, num = 0;

	if(esVacia(cab)){
		printf("\nAviso! La pila esta vacia.\n");
	} else{
		printf("\nAviso! La pila NO esta vacia.\n");
	}

	printf("\nDigite cant. de datos a cargar: "); scanf("%d",&cant);
	printf("_________________________________\n");

	for (int i = 0; i < cant; ++i) {
		printf("Digite el (%d) elemento: ",(i+1)); scanf("%d",&num);
		apilar(&cab, num);
	}

	printf("\nPila Original >");
	mostrar(cab);

	printf("\nPila Inversa >");
	invertir(&cab);

	return 0;
}