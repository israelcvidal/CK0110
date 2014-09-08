#include <stdio.h>
#include <stdlib.h>
/*
	ATENÇÃO: ESTA SOLUÇÃO É A SOLUÇÃO DO STENIO, O QUE NÃO IMPLICA QUE A SUA SOLUÇÃO ESTEJA ERRADA, OU QUE A MINHA SEJA A MAIS CERTA.
	         HÁ DIVERSAS MANEIRAS DE ABORDAR UM MESMO PROBLEMA.

	Problema: Faça um programa em linguagem C que receba um valor inteiro positivo N e mostre os
			  N primeiros números primos, considerando o primeiro número primo como sendo 2.

	Estratégia usada: Testaremos todos os números no intervalo de 1 até N - 1, já que queremos apenas valores menores que N.
					  Enquanto não imprimirmos um número N de números primos, continuamos a execução do programa. 

	Algoritmo usado: 
					primo <- 2
					enquanto contador != numero faça
						se primo for primo então
							escreva(primo)
							contador <- contador + 1
						fim_se
						primo <- primo + 1
					fim_enquanto

*/

int verificaPrimo(int numero){
	
	int i;	// índice do laço for
	int qtdDivisores = 0; // variável que vai contar quantos divisores diferentes o número tem

	// aqui, começamos o laço com i = 1 e terminamos quando i <= numero, já que um número é primo se ele for divisível
	// apenas por 1 e por ele mesmo, sendo assim, começamos o laço indo do 1, até o próprimo número (i <= numero)
	for(i = 1; i <= numero; i++){
		// testamos se o número que passamos para função é divisível pelo índice atual, se for, o mod entre esses dois resultará em 0
		// ai, adicionamos um na quantidade de divisores do número analizado.
		if(numero % i == 0){
			qtdDivisores++; // => qtdDivisores = qtdDivisores + 1;
		}
	}
	// se o número analizado tiver apenas 2 divisores, então, retornamos 1, entenda esse 1 como um 'sim, o número é primo'.
	if(qtdDivisores == 2){
		return 1;
	}
	// caso contrário, retornamos 0, que é equivalente à dizer: 'não, este número não é primo'.
	
	/*	Há maneiras mais fáceis de encontrar números primos e que exigem menos processamento, 
		tal como analizar apenas os números de 1 até a raíz do número analizado, o que é facilmente provado matematicamente,
		porém, por fins didáticos, esta solução me parece suficiente. :p
	*/
	return 0;
}

int main(int argc, char const *argv[]){

	int numero; // variável que vai guardar nosso número de entrada
	int primos = 2; // variável que vai percorrer os valores de 1 até o número, nos possibilitando analizar todos os números inteiros no intervalo de 1 até o número de entrada.
	int i = 0; // variável que usaremos para controle do laço

	printf("Digite a quantidade de numeros primos que quer mostrar: \n");
	scanf("%d", &numero);
 	
 	printf("%d primeiros numeros primos: \n", numero);

 	// Enquanto não imprimirmos N números primos...
 	while(i != numero){ 
 		if(verificaPrimo(primos) == 1){ // chamamos a função que verifica se um número é primo, se a resposta retorn
			printf("%d ", primos); // imprimimos o número analizado, que, pelo retorno da função, é um primo.
			i++;
		}
		primos++; // incrementamos a variável primos, para analizar o próximo inteiro.
 	}
	
	printf("\n");

	return EXIT_SUCCESS;
}

/* PEACE! */
