/*
 * Conteudo: Arquivo de metodos para chamar Algoritmos de ordenacao
 * Autor: Esdras La-Roque
 * Data: 19/04/2015
 * Versão: 0.5
 */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <time.h>
#include "geradorvetor.h"
#include "algoritmos.h"
#define TRUE 's'
#define FALSE 'n'

/* Definindo funcao para mensagem de ajuda */
void ajuda(char *nome) {
    fprintf(stderr, "\
Use: %s <opcoes>\n\n\
[OPCOES]:\n\
	 -h, --help          		Mostra estas informacoes de ajuda.\n\
         -t, --tamanho=<tamanho_vetor>  Quantidade de elementos do vetor.\n\
         -a, --algoritmo=<ALGORITMO>	Algoritmo de ordenacao.[ insertion | quick | bucket ]\n\
         -e, --estado=<ESTADO> 		Defini estado do vetor gerado. [ ord | inv | sord | ale ]\n\
         -p, --imprimir	     		Imprimir vetor gerado.\n", nome);
    exit(-1) ;
}

enum e_ordenacao { ORD, INV, SORD, ALE };
enum e_algoritmo { INSERTION, QUICK, BUCKET };

struct listaOrdenacao {
	char *label;
	enum e_ordenacao id;
} itens_ordenacao[] = {
	{"ord", ORD},
	{"inv", INV},
	{"sord", SORD},
	{"ale", ALE}
};

struct listaAlgoritmo {
	char *label;
	enum e_algoritmo id;
} itens_algoritmo[] = {
	{"insertion", INSERTION},
	{"quick", QUICK},
	{"bucket", BUCKET}
};

struct timespec t_inicial={0,0}, t_final={0,0};

main (int argc, char **argv) {

	/* Inicializacao de variaveis */
	int i, opt, tam = NULL;
	char *alg = NULL, *status = NULL; 
	int flag_imprimir = 0;
	int *vetor = NULL;

	/* Parametrizando as opcoes passadas por argumento, baseado na biblioteca getopt.h (Padrao GNU/Linux) */
	const struct option opcoes[] = {
		{"help"		, no_argument		, 0		, 'h'},
		{"tamanho"	, required_argument	, 0		, 't'},
		{"algoritmo"	, required_argument	, 0		, 'a'},
		{"estado"	, required_argument	, 0		, 'e'},
		{"imprimir"	, no_argument		, &flag_imprimir, 1  },
		{0		, 0			, 0		, 0  }
	};

	/* Verificando a existencia da quantidade minima de parametros passados via cli */
	if ( argc < 7 )
		ajuda(argv[0]);

	/* Tratamento dos argumentos passados ao programa */
	while( (opt = getopt_long(argc, argv, "ht:a:e:p", opcoes, NULL)) > 0 ) {
        	switch ( opt ) {
			/* -h ou --help */
            		case 'h': ajuda(argv[0]);
                		break;
			/* -t ou --tamanho */
            		case 't': tam = atoi(optarg);
                		break;
			/* -a ou --algoritmo */
            		case 'a': alg = optarg;
                		break;
			/* -s ou --status */
			case 'e': status = optarg;
                		break;
			/* -p ou --imprimir */
            		case 'p': flag_imprimir = 1;
                		break ;
            		default: fprintf(stderr, "Opcao invalida ou faltando argumento: '%c'\n", optopt);
                		return -1;
	        }
    	}

	/* Verificando se o vetor contem o minimo de elementos para ordenar */
	if ( tam < 2 ) {
		printf("Erro: O tamanho do vetor não pode ser menor que 2.\n");
		return -1;
	}
	
	/* Criando vetor com tamanho e estado de ordenacao passados em parametro */
	if ( strcmp(status,  itens_ordenacao[0].label) == 0 ) {
       	        if ( flag_imprimir )
               	        vetor = vetorOrdenado(tam,TRUE);
                else 
       	                vetor = vetorOrdenado(tam,FALSE);
	} else if ( strcmp(status,  itens_ordenacao[1].label) == 0 ) {
       	        if ( flag_imprimir )
               	        vetor = vetorInversamenteOrdenado(tam,TRUE);
                else 
       	                vetor = vetorInversamenteOrdenado(tam,FALSE);
	} else if ( strcmp(status,  itens_ordenacao[2].label) == 0 ) {
       	        if ( flag_imprimir )
               	        vetor = vetorSemiOrdenado(tam,TRUE);
                else 
       	                vetor = vetorSemiOrdenado(tam,FALSE);
	} else if ( strcmp(status,  itens_ordenacao[3].label) == 0 ) {
       	        if ( flag_imprimir )
               	        vetor = vetorAleatorio(tam,TRUE);
                else 
       	                vetor = vetorAleatorio(tam,FALSE);
	} else {
		printf("Erro: Estado de ordenacao invalido. Utilize \"--help\" para ajuda.\n");
		return -1;
	}

	/* Executando ordenacao baseada no algoritmo escolhido e capturando o tempo de execucao */
	if ( strcmp(alg, itens_algoritmo[0].label) == 0 ) {
		clock_gettime(CLOCK_REALTIME, &t_inicial);
		insertion_sort(vetor, tam);
		clock_gettime(CLOCK_REALTIME, &t_final);
                if ( flag_imprimir ) {
			printf("\n");
                        printf("Insertion_sort( v[%d] )\n", tam);
                        printArray(vetor, tam);
			printf("\n");
                }
	} else if ( strcmp(alg,  itens_algoritmo[1].label) == 0 ) { 
		clock_gettime(CLOCK_MONOTONIC, &t_inicial);
		quick_sort(vetor, tam);
		clock_gettime(CLOCK_MONOTONIC, &t_final);
		if ( flag_imprimir ) {
			printf("\n");
			printf("Quick_sort( v[%d] )\n", tam);
			printArray(vetor, tam);
			printf("\n");
		}
	} else if ( strcmp(alg,  itens_algoritmo[2].label) == 0 ) {
		clock_gettime(CLOCK_REALTIME, &t_inicial);
                bucket_sort(vetor, tam);
		clock_gettime(CLOCK_REALTIME, &t_final);
                if ( flag_imprimir ) {
			printf("\n");
                        printf("Bucket_sort( v[%d] )\n", tam);
                        printArray(vetor, tam);
			printf("\n");
                }
	}  else {
		printf("Erro: Algoritmo nao suportado. Utilize \"--help\" para ajuda.\n");
		return -1;
	}

	/* Iniciando variaveis globais que foram definidas no objeto 'algoritmos.o' e imprimindo resultados */
	extern long long int mov ;
	extern long long int comp ;
	printf("Tempo de execucao (ns): %lu\n", t_final.tv_nsec - t_inicial.tv_nsec);
	printf("Movimentacoes: %lli\n", mov);
	printf("Comparacoes: %lli\n", comp);

	return 0;
}
