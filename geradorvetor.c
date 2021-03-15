/*
 * Conteudo: Arquivo de metodos para gerar vetores
 * Autor: Esdras La-Roque
 * Data: 09/04/2015
 * Versão: 0.1
 */
#include <stdio.h>
#include <stdlib.h>
#include "geradorvetor.h"

void printArray(int A[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int* vetorAleatorio(int qtd, char print) {
	time_t t;
	int i, j, k;
	int* a = (int*) malloc(qtd * sizeof(int));
	int* v = (int*) malloc(qtd * sizeof(int));

	srand((unsigned) time(&t));

	for ( i = 0 ; i < qtd ; i++ ) {
		a[i] = i;
		v[i] = i;
	}

	for ( i = 0 ; i < qtd ; i++ ) {
		j = rand() % qtd;
		k = rand() % qtd;

		if ( a[j] != a[k] ) {
			v[j] = a[k];
			v[k] = a[j];
			a[j] = v[j];
			a[k] = v[k];
		}
	}

	if ( print == 's' ) {
		printf("v[%d] aleatorio:\n", qtd);
		printArray(v,qtd);
	}

	return v;
}

int* vetorOrdenado(int qtd, char print) {
        int i;
	int* v = (int*) malloc(qtd * sizeof(int));

	for ( i = 0 ; i < qtd ; i++ ) {
		v[i] = i; 
	}

        if ( print == 's' ) {
                printf("v[%d] ordenado:\n", qtd);
                printArray(v,qtd);
        }
	
	return v;
}

int* vetorSemiOrdenado(int qtd, char print) {
	time_t t;
	int i, j, k, p;
	int* v = (int*) malloc(qtd * sizeof(int));
	int* a = (int*) malloc(qtd * sizeof(int));

	srand((unsigned) time(&t));

        for ( i = 0 ; i < qtd ; i++ ) {
		a[i] = i;
                v[i] = i;
        }

	p = (qtd * 10) / 100;

	if ( p != 0 ) {

	        for ( i = 0 ; i < p ; i++ ) {
        	        j = rand() % qtd;
	                k = rand() % qtd;
	
        	        if ( a[j] != a[k] ) {
                	        v[j] = a[k];
                        	v[k] = a[j];
	                        a[j] = v[j];
        	                a[k] = v[k];
                	}
	        }
		
	} else {

		j = rand() % qtd;
                k = rand() % qtd;

                if ( a[j] != a[k] ) {
                	v[j] = a[k];
                        v[k] = a[j];
                        a[j] = v[j];
                        a[k] = v[k];

                } else {

	                j = rand() % qtd;
        	        k = rand() % qtd;

	                if ( a[j] != a[k] ) {
        	                v[j] = a[k];
                	        v[k] = a[j];
                        	a[j] = v[j];
	                        a[k] = v[k];
        	        }			
		}
	}

        if ( print == 's' ) {
                printf("v[%d] semi ordenado:\n", qtd);
                printArray(v,qtd);
        }

        return v;
}

int* vetorInversamenteOrdenado(int qtd, char print) {
	int i;
	int* v = (int*) malloc(qtd * sizeof(int));

	for ( i = qtd ; i > 0 ; i-- ) {
		v[qtd - i] = i - 1;	
	}

        if ( print == 's' ) {
                printf("v[%d] inversamente ordenado:\n", qtd);
                printArray(v,qtd);
        }

	return v;
}

