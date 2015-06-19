Desenvolvido no Debian. Rodado via linha de comando com GCC e GDB 

_________________________________________________________________________

1) Estrutura de dados: Pilha
* Fonte: minhapilha.c
  * Inserção
  * Pesquisa por valor
  * Exclusão
  * Retorna tamanho da lista.
  * Usa malloc e ponteiro 

  * para compilar:
    * gcc -g minhapilha.c -o pilha

  * para rodar:
    * se quiser usar gdb -> (sudo apt-get install gdb)
    * gdb ./pilha  ou somente ./pilha 

_________________________________________________________________________

2) Fork efetuado dia 16/06/2015
* Projeto importado do meu github para projeto no Eclipse CDT

_________________________________________________________________________

3) dia 17/06/2015 - Encontrado e corrigido 11 warnings

* Inicialização de variáveis char com valor zero
* Especificador de formato %u das funções do printf modificados para %p
* Variável 'command' não utilizada - linha comentada
* Variável rs_scn criada para recepção dos retornos das funções: system e scanf
  * Impressão do resultado desta variável ao final da execução do programa por mera conveniência afim de evitar warning

_________________________________________________________________________

4) dia 18/06/2015
* Formatação de código
  * Seguindo orientações do link: http://www.gnu.org/prep/standards/standards.html#Formatting
  * TODO
  	* incluir no momento da re-criação do menu a função 'system' chamando o comando 'clear' para limpar a telar
  	* Mensagens informativas das opções escolhidas serem repassadas por parâmetro para serem impressas pela função criarMenu 
