#include <stdio.h>
#include <stdlib.h>

/*
	ATENÇÃO: ESTA SOLUÇÃO É A SOLUÇÃO DO STENIO, O QUE NÃO IMPLICA QUE A SUA SOLUÇÃO ESTEJA ERRADA, OU QUE A MINHA SEJA A MAIS CERTA.
	         HÁ DIVERSAS MANEIRAS DE ABORDAR UM MESMO PROBLEMA.

	Problema: Faça um programa em linguagem C que receba um valor inteiro positivo N e mostre
			  todos os números da sequência Fibonacci que sejam menores do que N.

	Estratégia usada: 
	
	OBS: PARA UMA MELHOR COMPREENSÃO DO ALGORITMO USADO, INDICO QUE FAÇA CASOS DE TESTES EM UM PAPEL, ONDE É 
	     MAIS FÁCIL VISUALIZAR O QUE ACONTECE NO DECORRER DA EXECUÇÃO DO CÓDIGO
*/

void fibbonacci(int numeroEntrada){
	int x, y, fib;
	int i;

	x = 0; // A inicialização da variável 'x' e 'y' ficará mais óbvia mais abaixo
	y = 1;
	i = 0; // Variável que nos ajudará a imprimir os 2 primeiros elementos da Sequencia
	
  /*Como ESTA resolução do problema não depende do número de iterações do laço abaixo,
	 podemos fazê-lo como um laço infinito, onde não precisamos declarar variáveis de controle
 	 do laço, nem inicializações ou incrementos desta variável.
 	Aqui, nossa condição de parada será quando a variável 'fib' for maior ou igual ao número que entramos,
	 fazendo com que os números que sejam imprimidos sejam apenas aqueles que são menores que o número de Entrada.*/
	for(;;){ //laço for sem declarações

		// Se i for 0 ou 1, imprimimos 0 e depois 1, que são os primeiros da Sequência
		if(i <= 1){ 
			fib = i; // Fazemos isso passando o valor de i (que será 0 ou 1) e passamos para 'fib'
			i++; // Quando imprimimos o 0 e o 1 da sequencia, não precisaremos mais da variável 'i', fazemos ela parar de ser incrementada quando ela for 2
		}else{ // Senão...
			fib = x + y; // A variável auxiliar 'fib' vai receber a soma de x + y
			x = y; // Fazemos x receber o valor do y
			y = fib; // E y passa a ter o valor de fib
		}
		// Se o fib já for maior ou igual (caso em que o número de entrada está na sequencia), paramos o laço
		// OBS: O motivo de esse if estar aqui e não lá em cima, é que a verificação tem que ser feita
		// após as operações com o 'fib'.
		if(fib >= numeroEntrada){
			break;
		}
		// Imprimimos o valor de 'fib'
		printf("%d ", fib);
	}
}

int main(int argc, char const *argv[]){

	int numeroEntrada;
	
	printf("Digite um Numero inteiro: \n");
	scanf("%d", &numeroEntrada);
	printf("Elementos da serie de Fibbonacci menores que %d: ", numeroEntrada);
	fibbonacci(numeroEntrada);
	printf("\n");

	return EXIT_SUCCESS;
}

/* PEACE! */
