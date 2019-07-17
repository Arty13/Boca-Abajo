#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include "auxiliar.h"
#include <string.h>
#define MAXTAM 2048

struct Pila{
	char* linea;
	struct Pila *siguiente;
};
typedef struct Pila elem;
elem *anterior;

int main (int argc, char *argv[]){
	FILE *fichero;
	char fila [MAXTAM];
	int i = 0;
	char* cursor;
	argv0 = "bocabajo";
if (argc == 1){
        while(fgets(fila,MAXTAM,stdin)!= NULL){
		while (!feof(stdin)){
			cursor = (char *) malloc (strlen(fila));
			if(cursor==NULL){
				Error (EX_OSERR,"No se pudo ubicar la memoria dinámica necesaria.");
				exit(EX_OSERR);
			}
			cursor=strdup(fila);
			elem *nuevaLinea;
			nuevaLinea = (elem*) malloc (sizeof (elem));
			if(nuevaLinea != NULL){
				nuevaLinea->linea=cursor;
				nuevaLinea->siguiente= anterior;
				anterior=nuevaLinea;
			}
			fgets(fila,MAXTAM,stdin);
		}
		while (anterior != NULL){
			elem *aux;
			if(anterior != NULL){
				cursor = anterior->linea;
				aux = anterior;
				anterior = anterior->siguiente;
				free (aux);
			}
			printf("%s",cursor);
			free(cursor);
		}
	}
}
if(argc > 1){
	if((strcmp(argv[1],"-h")==0) || (strcmp(argv[1],"--help")==0)){
		printf ("bocabajo: Uso: bocabajo [ fichero... ]\n");
		printf("bocabajo: Invierte el orden de las lı́neas de los ficheros (o de la entrada).\n");
		exit(EX_OK);	
	} else {
		for(i=1;i<argc;i++){
			fichero = fopen(argv[i],"r");
			if(fichero==NULL){
				Error (EX_NOINPUT,"El fichero \"%s\" no puede ser leido",argv[i]);
				exit(EX_NOINPUT);
			}
			while(fgets(fila,MAXTAM,fichero)!='\0'){
				while(!feof(fichero)){
					cursor = (char *) malloc ( strlen(fila));
					if(cursor!=NULL){
						elem *nuevaLinea;
						cursor=strdup(fila);
						nuevaLinea = (elem*) malloc (sizeof (elem));
						if(nuevaLinea != NULL){
							nuevaLinea->linea=cursor;
							nuevaLinea->siguiente= anterior;
							anterior=nuevaLinea;
						}
						fgets(fila,MAXTAM,fichero);
					} else {
						Error(EX_OSERR,"No se pudo ubicar la memoria dinámica necesaria.");
						exit(EX_OSERR);
					}
				}
			}
		}
	}
	while (anterior != NULL){
		elem *aux;
		if(anterior != NULL){
			cursor = anterior->linea;
			aux = anterior;
			anterior = anterior->siguiente;
			free (aux);
		}
		printf("%s",cursor);
		free(cursor);
	}	
}
exit(EX_OK);
}
