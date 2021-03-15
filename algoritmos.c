/*
 * Conteudo: Arquivo de metodos para chamar Algoritmos de ordenacao
 * Autor: Esdras La-Roque
 * Data: 14/04/2015
 * Versão: 0.1
 */
#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

long long int mov, comp;

/* Inicio: Insertion_sort */
void insertion_sort (int *a, int n) {
    int i, j, t;
    for (i = 1; i < n; i++) {
        t = a[i];
        for (j = i; j > 0 && t < a[j - 1]; j--) {
            a[j] = a[j - 1];
	    mov++;
	    comp++;
        }
        a[j] = t;
	comp++;
    }
}
/* Fim: Insertion_sort */

/* Inicio: Quick_sort */
void quick_sort (int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}
/* Fim: Quick_sort */

/* Inicio Bucket_sort */
void bucket_sort(int array[], int n) {  
    int i, j;  
    int count[n]; 
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    for (i = 0; i < n; i++)
        (count[array[i]])++;
 
    for (i = 0, j = 0; i < n; i++)  
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;
}   

