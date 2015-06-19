#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

struct no
{
	int valor;
	struct no *proximo;
};


struct no *
adicionarNovoNo (struct no *node, int valor)
{

	struct no *ptr;

	if (node == NULL)
	  {
		printf ("if\n");
		node = malloc (sizeof (struct no));
		node->valor = valor;
		node->proximo = NULL;
	  }
	else
	  {
		printf ("else\n");
		ptr = malloc (sizeof (struct no));
		ptr->valor = valor;
		ptr->proximo = node;
		node = ptr;
	  }

	printf (" valor %d - endereco %p \n",node->valor, node->proximo);
	return node;
}


void
imprimir (struct no *node)
{
	struct no *ptr;

	if (node != NULL)
	  {
		ptr = node;
		printf (" valor: %d - meu ender: %p - prox: %p \n", ptr->valor, ptr, ptr->proximo);

		while (ptr->proximo)
		  {
			ptr = ptr->proximo;
			printf (" valor: %d - meu ender: %p - prox: %p \n", ptr->valor, ptr, ptr->proximo);
		  }
	  }
} 


int
pesquisarPorPosicao (struct no *node, int pesquisa)
{
	struct no *ptr, *proximo;
	int posicao = -1;
	int contador = 0;

	if (node)
	  {
		ptr = node;
		proximo = ptr;

		while (proximo)
		  {

			 if (ptr->valor != pesquisa)
			   {
				ptr = ptr->proximo;
				proximo = ptr;
				contador++;
			   }
			 else
			   {
				 posicao = (contador +1);
				 proximo = NULL;//para sair do loop
			   }
		  }
	  }

	return posicao;
} 

int
contaLista(struct no *node)
{
	int ret = 0;
	struct no *ptr;

	ptr = node;

	while (ptr != NULL)
	  {
		ret++;
		ptr = ptr->proximo;
		//printf(" linha: %d  \n", ret);
	  }

	printf (" total de linhas na lista : %d  \n", ret);

	return ret;
}

struct no *
deletarNoPorValor(struct no *node, int pesquisa)
{
	int posicao = -1;
	int contador = 0;
	int totalLista;
	struct no *ptr = node;


	posicao = pesquisarPorPosicao (node, pesquisa);

	totalLista = contaLista (node);

	/* diminuir 1 pq comeca contar de zero */
	posicao--;

	/*
	 * fazer o loop de acordo com a posicao, começando do valor zero.
	 * qdo encontrar tem que ligar o valor anterior ao posterior
	 */
	if (posicao >= 0)
	  {
		/*
		 * a solução para o primeiro elemento da lista
		 */
		if (posicao == 0)
		  {
			/*
			 * aponta o node para a posicao seguinte,
			 * pq o primeiro elemento é o a ser deletado
			 */
			node = ptr->proximo;
		  }
		else if ((posicao+1) == totalLista)
		  {
			/*
			 * a solução para excluir o ultimo elemento da lista
			 * vai ate a posicao anterior à encontrada(q neste caso eh a penultima)
			 * -2 pq comecei a contar do zero
			 */
			while (contador < (totalLista -2))
			  {
				node = node->proximo;
				printf (" valor: %d - meu ender: %p \n", node->valor,  node);
				contador++;

			  }

			/*
			 * no final do loop chegara ao penultimo
			 */

			/*
			 * para excluir o ultimo
			 */
			node->proximo = NULL;

			/*
			 * atualiza o ponteiro para o inicio da pilha
			 */
			node = ptr;
		  }
		else
		  {
			/*
			 * a solução para o elemento no meio da lista -
			 * para encontrar o elemento anterior ao ser deletado
			 */
			ptr = node;

			while (ptr)
			  {
				if (contador == posicao-1)
				  {
					/*
					 * aponta para o proximo do elemento encontrado
					 */
					ptr->proximo = ptr->proximo->proximo; /* pega o posterior depois do excluido */
					break;
				  }

				contador++;
				ptr = ptr->proximo;
			  }
		  }
	  }
	else
	  {
		printf (" valor nao cadastrado na pilha. \n");
	  }

	return node;
}

void criarMenu(){
	printf ("\t 0 - Sair \n");
	printf ("\t 1 - Adicionar Elemento \n");
	printf ("\t 2 - Pesquisar por Elemento \n");
	printf ("\t 3 - Imprimir \n");
	printf ("\t 4 - Conta Lista \n");
	printf ("\t 5 - Deletar por Elemento \n");
	printf ("\n\n Escolha uma das opcoes acima =  ");

}

int main (void)
{
	// char command;
	char ch=0;
	char rank_ch=0;
	int num, encontrado, rs_scn;
	struct no *node;


	rs_scn = system ("clear");

	criarMenu();

	rank_ch = getchar ();

	node = NULL;

	while(ch !=  '0')
	  {
		switch (rank_ch)
		  {
			case '0':
				exit(EXIT_SUCCESS);
			case '1':
				printf("\n Entre com o valor :  ");
				rs_scn = scanf("%d", &num);

				node = adicionarNovoNo (node, num);
				break;
			case '2':
				printf ("Entre com o valor para pesquisa:  ");
				rs_scn = scanf ("%d", &num);

				encontrado = pesquisarPorPosicao (node, num);

				if (encontrado > 0)
				  {
					printf (" valor encontrado na posicao: %d . \n",encontrado);
				  }
				else
				  {
					printf ("Valor nao cadastrado.\n");
				  }
				break;
			case '3':
				imprimir (node);
				break;
			case '4':
				contaLista (node);
				break;
			case '5':
				printf ("\n Entre com o valor :  ");
				rs_scn = scanf ("%d", &num);

				node = deletarNoPorValor (node, num);
				/*
				 * deletarPorValor (node, num);
				 */

				printf ("\n  ");
				printf ("\n  Lista Atualizada.\n");
				imprimir (node);
				break;
		  }


		if (rank_ch !='\n')
		  {
			/*
			 * rs_scn = system ("clear");
			 * TODO
			 * passar mensagem referente a opção como parametro
			 * da funcao criarMenu afim de nao perde-la apos a limpeza de tela
			 */
			criarMenu ();
		  }

		rank_ch = getchar ();

	  }

	printf ("\n %d", rs_scn);
	free (node);

	return 0;
}

