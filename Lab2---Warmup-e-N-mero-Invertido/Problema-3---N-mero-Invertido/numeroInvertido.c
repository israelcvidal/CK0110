#include <stdio.h>
#include <stdlib.h>

/* 
	ATENÇÃO: ESTA SOLUÇÃO É A SOLUÇÃO DO STENIO, O QUE NÃO IMPLICA QUE A SUA SOLUÇÃO ESTEJA ERRADA, OU QUE A MINHA SEJA A MAIS CERTA.
	         HÁ DIVERSAS MANEIRAS DE ABORDAR UM MESMO PROBLEMA.

	Problema: Faça um programa em linguagem C que receba um valor inteiro de até 10 dígitos e
			  mostre o número inteiro invertido. Caso o programa seja chamado na linha de comando
			  sem nenhum argumento, o programa deve solicitar uma entrada de dados para o
			  usuário, através do teclado. Caso o programa seja chamado com parâmetro, o programa
			  deve ler o arquivo cujo nome foi passado no parâmetro, ler o número que está na
			  primeira linha do arquivo e mostrar seu número invertido.

	Estratégia usada: Por meio de operações matemáticas, iremos fazer operações sucessivas no número de entrada, de forma que iremos estar, de fato
					  colocando os números de maior ordem no local dos números de menor ordem. 
					  Ex: 4321 - 1234
					  	  Milhar vira Unidade, Unidade vira Milhar
					  	  Centena vira Dezena, Dezena vira Centena

	Algoritmo usado:
					aux <- 0 
					enquanto(numero != 0) faça
						aux <- aux * 10
						aux <- aux + (número mod 10)
						número <- número / 10
					fim_enquanto
					retorne aux
	*/

int inverterNumero(int numero){
	
	int aux = 0;
	// Enquanto nossa variável de entrada for diferente de 0, ou seja, se ainda conseguimos fazer operações como o mod e divisão com este número...
	while(numero != 0){
		aux *= 10; // Fazemos com que o número obtido na linha de baixo vire unidade, dezena, centena (dependendo da iteração atual) e etc... Esta linha só fará efeito à partir da segunda interação, já que, na primeira, ela será 0, pois aux = 0.
		aux += (numero % 10); // Aqui, pegamos o número da menor ordem do número de entrada e somamos ao que já tinhamos na variável 'aux'
		numero /= 10; /* Passamos para a próxima ordem do número de entrada dividindo o mesmo por 10, o que nos dá a possibilidade de
					  	 eliminar o elemento da maior ordem, passando para a segunda de maior ordem.
					  	 Ex: 123 / 10 = 12 (Divisão inteira) (Saímos de uma centena para uma dezena)*/
	}

	return aux; // Retornamos a variável auxiliar, que conterá o número invertido.
}

int main(int argc, char const *argv[]){
	
	FILE *arquivo; // Ponteiro para o Arquivo de Entrada
	int numero; // Variável que Armazenará o(s) número(s) contido(s) no Arquivo ou
				// o valor de entrada pela linha de comando

	if(argc == 2){ // Se tiver 2 Argumentos na linha de Comando... (./executavel + nomeArquivo)
		arquivo = fopen(argv[1], "r"); // Fazemos nosso Ponteiro de Arquivos apontar para o Arquivo passado como Parâmetro
		if(arquivo == NULL){ // Se o Arquivo não existir ou ocorrer algum erro ao Abrir o Arquivo...
			printf("Nao consegui abrir o arquivo, =(\n"); // =/
			return EXIT_FAILURE;
		}else{ // Se não...
			while(!feof(arquivo)){ // Enquanto houver algo para ler no Arquivo...
				fscanf(arquivo, "%d\n", &numero); 
				/* Aqui, é importante perceber que lemos uma linha inteira de uma vez,
				 sendo que nessa linha pode haver tipos de dados diferentes.
				A regra geral do uso do fscanf é: 
					fscanf(ponteiroDoArquivo, "tipoDoDado", &variavel_Que_Se_Quer_Armazenar_o_Dado_Lido_Do_Arquivo);
				Uma coisa interessante é que podemos ler diversos valores de uma vez só, em uma
				única linha do Arquivo, por exemplo:
					fscanf(meuArquivo, "%f, %d, %c\n", &meuFloat, &meuInteiro, &meuChar);
				O código acima lê uma linha inteira de um Arquivo. Vale lembrar que:
					- A ordem dos tipos de dados que aparecem no Arquivo tem que ser a mesma no fscanf;
					- Você pode definir um separador para organizar os valores dentro do Arquivo e fazer o fscanf
						obedecer esse separador, no caso, usei a vírgula (,) para separar os valores dentro do Arquivo;
					* Se o seu separador estiver explicitado diferente no fscanf, você será contemplado com um Erro!
						Portanto, mantenha a integridade do Arquivo e do fscanf.			
					- Como queremos, geralmente, ler mais de uma linha de um Arquivo, é importante passarmos para a próxima linha, não é? :)
						Para isso, dê sempre um '\n' no seu último argumento do fscanf para que esteja explicitado que ao acabar a linaha tual
							você deseja passar para a próxima linha.*/	
				printf("\nNumero de Entrada: %d\n", numero); // Imprimimos o número(s) lido(s) do Arquivo
				printf("Numero '%d' Invertido: %d\n", numero, inverterNumero(numero)); // Imprimindo o Número lido de forma inversa
			}
			fclose(arquivo); // FECHE O ARQUIVO! OCASIONALMENTE, COISAS OBSCURAS OCORREM DENTRO DO SISTEMA OPERACIONAL QUE PODEM CORROMPER O SEU
							// ARQUIVO! NÃO QUEREMOS ISSO, NÃO É? ENTÃO FECHA O ARQUIVO CABEÇÃO(ONA)! <3
		}
	}else{ // Se o usuário não quiser abrir um Arquivo...
		printf("Digite o Numero que quer Inverter: \n"); 
		scanf("%d", &numero); // Lemos um número inteiro direto da linha de comando
		printf("\nNumero de Entrada: %d\n", numero);
		printf("Numero '%d' Invertido: %d\n\n", numero, inverterNumero(numero)); // Imprimindo o Número lido de forma inversa
	}
	
	return EXIT_SUCCESS; // SUCESSO, NÃO É?! d:-P
}

/* PEACE! */
