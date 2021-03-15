/* Arquivo de definicoes pontuais */
typedef struct opcoesOrdenacao {
	char *label;
//	enum e_ordenacao id;
} Ordenacao;


struct listaOrdenacao {
        char *label;
        enum e_ordenacao id;
} itens_ordenacao[] = {
        {"ord", ORD},
        {"inv", INV},
        {"sord", SORD},
        {"ale", ALE}
};

