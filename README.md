  Desenvolvido no Debian. Rodado via linha de comando com GCC e GDB 

1) Pilha
  minhapilha.c
  Insere, pesquisa por valor, exclui, conta o tamanho da lista.
  Usa malloc e ponteiro 

  ==> para compilar:
    gcc -g minhapilha.c -o pilha

  ==> para rodar:
   se quiser usar gdb -> (sudo apt-get install gdb)
    gdb ./pilha 
  ou somente
    ./pilha 
_________________________________________________________________________

2) Fork efetuado dia 16/06/2015
Projeto importado do meu github para projeto no Eclipse CDT

_________________________________________________________________________

3) dia 17/06/2015 - Encontrado e corrigido 11 warnings
==> Inicializado as variaveis char com valor zero
==> Modificado nas funções do printf o especificador de formato de %u para %p
==> comentado a linha que declara a variavel command (pois nao é usada)
==> criado variavel para receber os retornos das funções system e scanf e ao
fim imprimi-la no final apenas para evitar o warning de variavel não usada

 

     
