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
        if (i >= j) {
	    comp++;
            break;
	}
        t = a[i];
        a[i] = a[j];
        a[j] = t;
	mov++;
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
        for(; count[i] > 0; (count[i])--) {
            array[j++] = i;
	    mov++;
	}
}   
/* Fim: Bucket_sort */

/* Inicio Bubble_sort */
void bubble_sort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)  {
           comp++;
           if (arr[j] > arr[j+1]) {
               swap(&arr[j], &arr[j+1]);
           }
       }
} 
/* Fim: Bubble_sort */

/* Inicio Selection_sort */
void selection_sort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) {
            comp++;
            if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        }
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
/* Fim: Selection_sort */

void swap (int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp;
    mov++;
} 