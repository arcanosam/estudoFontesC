#include <stdio.h>
#include <stdlib.h>

#include "stack/stack.h"

void makeMenu(){
	printf ("\t 0 - Exit \n");
	printf ("\t 1 - Push Item \n");
	printf ("\t 2 - Search an Item \n");
	printf ("\t 3 - List itens from stack \n");
	printf ("\t 4 - Stack size \n");
	printf ("\t 5 - Delete an Item \n");
	printf ("\n\nChoice one of the options above =  ");

}

int main (void)
{
	char ch=0;
	char option_typed=0;
	int item_typed, founded, res_scan;
	struct stack *num_stack;


	res_scan = system ("clear");

	makeMenu();

	option_typed = getchar ();

	num_stack = NULL;

	while(ch !=  '0')
	  {
		switch (option_typed)
		  {
			case '0':
				exit(EXIT_SUCCESS);

			case '1':
				printf("\nType a number:  ");
				res_scan = scanf("%d", &item_typed);

				num_stack = push (num_stack, item_typed);
				break;

			case '2':
				printf ("Type a number to be searched:  ");
				res_scan = scanf ("%d", &item_typed);

				founded = search_by_item (num_stack, item_typed);

				if (founded > 0)
				  {
					printf ("\nThe item was found in this position: %d . \n\n", founded);
				  }
				else
				  {
					printf ("\nItem not found.\n\n");
				  }
				break;

			case '3':
				list_stack (num_stack);
				break;

			case '4':
				stack_size (num_stack);
				break;

			case '5':
				printf ("\nType a number:  ");
				res_scan = scanf ("%d", &item_typed);

				num_stack = remove_by_value (num_stack, item_typed);

				printf ("Stack updated.\n");
				list_stack (num_stack);
				stack_size (num_stack);
				break;
		  }


		if (option_typed !='\n')
		  {
			/*
			 * res_scan = system ("clear");
			 * TODO
			 * passar mensagem referente a opção como parametro
			 * da funcao makeMenu afim de nao perde-la apos a limpeza de tela
			 */
			makeMenu ();
		  }

		option_typed = getchar ();

	  }

	printf ("\n %d", res_scan);
	free (num_stack);

	return 0;
}
