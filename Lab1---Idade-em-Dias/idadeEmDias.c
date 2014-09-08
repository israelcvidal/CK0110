#include <stdio.h>
#include <stdlib.h>
#define IMPAR 0 // 'IMPAR' e 'PAR' não são variáveis com valores 0 e 1 respectivamente, elas são constantes com valores 0 e 1, respectivamente. 
#define PAR 1 

/*  - Constantes são o oposto de variáveis, apesar de trabalharem da mesma forma. 
	- As variáveis tem esse nome exatamente porque podemos mudar seu valor durante a execução do programa. Já as constantes são dados gravados em memória que de forma alguma podemos alterar seu valor.
	- Ao encontrar o nome IMPAR ou PAR no código, o compilador rapidamente substituirá o valor IMPAR por 0 ou PAR por 1.
	- Para criarmos uma constante, usamos o pré-processador #define. 
	- #define é um pré-processador porque todas as constantes devem ser definidas antes do inicio do programa. 
	- Outro fato importante é que, por padrão, sempre definimos nomes de constantes com letras maiúsculas.

	Problema: Dada uma data de nascimento e a data do dia atual, calcule a idade em dias do usuário, atentando-se para anos bissextos.

	ATENÇÃO: ESTA SOLUÇÃO É A SOLUÇÃO DO STENIO, O QUE NÃO IMPLICA QUE A SUA SOLUÇÃO ESTEJA ERRADA, OU QUE A MINHA SEJA A MAIS CERTA.
	         HÁ DIVERSAS MANEIRAS DE ABORDAR UM MESMO PROBLEMA.

	Estratégia usada: Contaremos a quantidade de dias que restam do ano, após a data de nascimento, assim como a quantidade de dias que já se passaram
						no ano até a data atual. Após isso, contaremos a quantidade de anos bissextos e contaremos quantos anos se passaram desde o ano de nascimento até o ano atual,
						multiplicamos este número por 365 (os anos que a subtração irá resultar já são completos) e subtrairemos por 1

	Algoritmo:
		  
		   qtd_anosBissextos <- Cálculo da Quantida de Anos Bissextos
		   qtd_diasRestam <- Quantidade de dias que restam para acabar o ano à partir da data de Nascimento
		   qtd_diasPassados <- Quantidade de dias que se passaram desde o início do ano até a data de nascimento

		   se dia_nascimento = dia_atual e mes_nascimento = mes_atual então
		       retorne (ano_atual - ano_nascimento) * 365 + qtd_anosBissextos
		   fim_se
			
		   retorne (((anoAtual - anoNascimento) - 1) * 365) + qtd_diasPassados + qtd_diasRestam + qtd_anosBissextos;

	Site que faz o mesmo Cálculo deste programa, caso queira conferir seus testes: http://www.calculador.com.br/calculo/diferenca-entre-datas
	Tabela com todos os anos Bissextos de 1004 até 2020: http://www.ponteiro.com.br/bisse.php

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	* LÓGICA PARA OS LAÇOS DAS FUNÇÕES 'int calculaQuantidadeDiasRestantes(int dia, int mes)' e 'int calculaQuantidadeDiasPassados(int dia, int mes)':
	
	- Existe uma lógica por trás dos números de 1 à 12, no contexto dos meses:

		Janeiro[1] Fevereiro[2] Março[3] Abril[4] Maio[5] Junho[6] Julho[7] Agosto[8] Setembro[9] Outubro[10] Novembro[11] Dezembro[12]
Dias       31          28/29       31		30		31		30		 31		   31		  30		  31		  30		   31 
 		
 		- É fácil notar que: De Janeiro[1] à Julho[7], apenas os meses ímpares possuem 31 dias, e os pares possuem 30, com exceção de Fevereiro, que pode ter 28 ou 29 dias.
		- De Agosto[8] em diante, esta lógica se inverte, fazendo com que os meses pares tenham 31 dias e os ímpares tenham 30 dias.
		- Assim, para contar dias, basta saber qual mês está sendo analizado e em que intervalo ele está (1 à 7 - ímpares com 31 dias e pares com 30 dias ou 8 à 12 - pares com 31 dias e ímpares com 30 dias)
*/

//Esta é a nossa função principal, onde chamamos todas as funções responsáveis por fazerem contagens, tal como anos bissextos.
//Nesta função, receberemos os dados da data de nascimento e data atual do usuário.
int idadeEmDias(int diaNascimento, int mesNascimento, int anoNascimento, int diaAtual, int mesAtual, int anoAtual){

	int qtdBissextos; // Variável que irá guardar a quantidade de anos bissextos no intervalo de anoNascimento e anoAtual.
	int diasPassadosAnoAtual; // Variável que irá guardar a quantidade de dias que já se passaram desde o começo do ano até a data atual.
	int diasRestantesAnoNascimento;	// Variável que irá guardar a quantidade de dias que ainda restam desde o dia/mes de nascimento até o fim do ano.
	
	// Calculamos quantos anos bissextos há entre o ano de nascimento e o ano atual e passamos este valor para 'qtdBissextos'
	qtdBissextos = calculaQuantidadeAnosBissextos(anoNascimento, anoAtual); 
	
	// Se o dia/mes de nascimento forem iguais ao dia/mes atual, basta fazer a diferença entre o ano atual e o ano de nascimento e multiplicar por 365 e somar com a quantidade de anos bissextos no intervalo.
	if(diaNascimento == diaAtual && mesNascimento == mesAtual){
		printf("\nFeliz Aniversario!\n");
		return (anoAtual - anoNascimento) * 365 + qtdBissextos; // Subtraímos os anos e multiplicamos por 365 e depois somamos o resultado à qtd. de anos bissexto encontrados no intervalo de ano nasc. até ano atual.
	}

	// Aqui, fazemos o cálculo de quantos dias já se passaram desde o começo do ano até a data de atual, assim como calculamos quantos dias ainda restam até o fim do ano desde a data de nascimento,
	// e passamos estes valores-resultados para suas respectivas variáveis.
	diasPassadosAnoAtual = calculaQuantidadeDiasPassados(diaAtual, mesAtual);
	diasRestantesAnoNascimento = calculaQuantidadeDiasRestantes(diaNascimento, mesNascimento);

	// Após feitos os cálculos, seguimos a seguinte equação:
	return (((anoAtual - anoNascimento) - 1) * 365) + diasPassadosAnoAtual + diasRestantesAnoNascimento + qtdBissextos;
   /*(anoAtual - anoNascimento): Nos dirá a idade 'bruta' do usuário.
	 ((anoAtual - anoNascimento) - 1): Ao subtrairmos o trecho acima por 1, iremos obter a quantidade exata de anos que o usuário viveu, bastando subtrair por 1, visto que este ano (ou quase) será reposto nos cálculos de quantidade de dias passados e restantes.
	 (((anoAtual - anoNascimento) - 1) * 365): Nos dirá quantos dias se passaram
	 diasPassadosAnoAtual + diasRestantesAnoNascimento + qtdBissextos: Nos dirá: A quantidade de dias que se passaram desde o início do ano até o dia/mês da data atual + a quantidade de dias que ainda restam desde a data de nascimento até o fim do ano + a quantidade de anos bissextos encontrados no intervalo de 'anoNascimento' e 'anoAtual'.
	*/
}

int calculaQuantidadeAnosBissextos(int anoNascimento, int anoAtual){
	int i; // Contador que vai iterar entre os anos no intervalo do ano de nascimento até o ano atual
	int quantidadeAnosBissextos = 0; // Variável que guardará a quantidade de anos bissextos no intervalo do Ano de nascimento e o Ano atual
	// IMPORTANTE: Variáveis que serão usadas como contadores devem ser inicializadas com ZERO (no geral).
	for(i = anoNascimento; i <= anoAtual; i++){
		if((i % 4 == 0 && i % 100 != 0 ) || i % 400 == 0){ // Condição para um ano ser Bissexto
			quantidadeAnosBissextos++; // Se o ano analizado for bissexto, adicionamos a variável 'quantidadeAnosBissextos' em 1.
		}
	}

	return quantidadeAnosBissextos; // Retornamos a quantidade de anos bissextos que existem no intervalo do ano de nascimeneto até o ano atual.
}

// Algoritmo simples para testar se um dado número é par ou ímpar
int parOuImpar(int numero){
	if(numero % 2 == 0){ // Se o número for divisível por 2 (se número / 2 -> resto = zero):
		return PAR; // Retornamos PAR (1)
	} // Se não for divisível por 2...
	return IMPAR; // Retornamos ÍMPAR (0)
}

// Esta função calcula a quantidade de dias que restam desde o dia/mês de nascimento até o fim do ano
int calculaQuantidadeDiasRestantes(int dia, int mes){
	int i; // Variável que vai interar no laço que iremos usar.
	int qtdDias = 0; // Variável que vai contar a quantidade de dias que restam para o fim do ano desde a data de nascimento.

	// A explicação da lógica deste laço está no início do Código
	for(i = mes + 1; i <= 12; i++){	
		if(i <= 7){ // Se o mês analizado está entre 1 <= mês <= 7:
			if(parOuImpar(i) == IMPAR){
				qtdDias += 31; // No intervalo de 1 à 7, para meses ÍMPARES, somamos 31 dias.
			}else{
				if(i == 2){
					qtdDias += 28; // Para fevereiro, somamos 28. Não precisamos nos preocupar com a possibilidade de 29 dias em Fevereiro, já que esta dúvida é resolvida com a função int calculaQuantidadeAnosBissextos(int anoNascimento, int anoAtual)
				}else{
					qtdDias += 30; // No intervalo de 1 à 7, para meses PARES, somamos 31 dias.
				}
			}
		}else{ // Entraremos neste bloco se já não estivermos mais no intervalo de 1 à 7, o que implica que que estamos no intervalo [8, 12]
			if(parOuImpar(i) == PAR){ // Como já foi dito na lógico no início do código, no mês de agosto em diante, os meses pares passam a ter 31 dias e os ímpares 30.
				qtdDias += 31; // Somamos 31 dias se o mês analizado for PAR.
			}else{
				qtdDias += 30; // Somamos 30 dias se o mês analizado for PAR.
			}
		}
	}

	/* 	- Os seguintes blocos condicionais expressam a quantidade de dias que ainda restam para terminar o ano, partindo da data de nascimento.
		- Temos que nos atentar à também contar os dias do mês de nascimento, por isso, cada 'if' é específico para uma classe de meses.
	    - Para descobrimos a quantidade de dias que se passaram desde o dia do nascimento até o fim do mês dentro do mês de nascimento, 
		- basta subtraírmos a quantidade total de dias do mês analizado pelo dia de nascimento.
	
		LEMBRE-SE: Meses pares de 1 à 7 tem 30 dias e meses ímpares tem 31 dias.
				   Meses pares de 8 à 12 tem 31 dais e meses ímpares tem 30 dias.
				   No nosso caso, Fevereiro sempre tem 28 dias.
	*/
	
	// Fevereiro
	if(mes == 2){
		return qtdDias + (28 - dia);	
	}

	// Mês entre 1 e 7 ÍMPAR
	if(mes <= 7 && parOuImpar(mes) == IMPAR){
		return qtdDias + (31 - dia);
	}

	// Mês entre 8 e 12 ÍMPAR
	if(mes > 7 && parOuImpar(mes) == IMPAR){
		return qtdDias + (30 - dia);
	}

	// Mês entre 1 e 7 PAR
	if(mes <= 7 && parOuImpar(mes) == PAR){
		return qtdDias + (31 - dia);
	}
	
	// Mês entre 8 e 12 ÍMPAR
	if(mes > 7 && parOuImpar(mes) == PAR){
		return qtdDias + (30 - dia);
	}
	
}

// Esta função calcula a quantidade de dias que já se passaram desde o começo do ano até a data atual.
int calculaQuantidadeDiasPassados(int dia, int mes){
	int i;
	int qtdDias = 0;

	// Se o mês atual for Janeiro, retornamos o dia atual, já que foram os únicos que se passaram até o momento.
	if(mes == 1){
		return dia;
	}

	// A explicação da lógica deste laço está no início do Código
	for(i = 1; i <= 12; i++){	
		if(i == mes){ // Só iremos analiar os meses de Janeiro até o mês da data Atual.
			break;
		}
		// O funcionamento do laço abaixo é o mesmo do laço da função 'int calculaQuantidadeDiasRestantes(int dia, int mes)', e sua explicação está no inínio do Código (linha 30).
		if(i <= 7){
			if(parOuImpar(i) == IMPAR){
				qtdDias += 31;
			}else{
				if(i == 2){
					qtdDias += 28;
				}else{
					qtdDias += 30;
				}
			}
		}else{
			if(parOuImpar(i) == PAR){
				qtdDias += 31; 
			}else{
				qtdDias += 30;
			}
		}
	}

	return qtdDias + dia; // Não há restrĩções na quantidade de dias retornados, já que só queremos saber quantos dias se passaram, 
						 //	 basta somar os dias passados dos meses anteriores com os dias que se passaram no mês atual(diaAtual).
}

int main(int argc, char const *argv[]){
	
	// Variáveis correspondentes à data de Nascimento
	int diaNascimento; 
	int mesNascimento;
	int anoNascimento;

	// Variáveis correspondentes à data Atual
	int diaAtual;
	int mesAtual;
	int anoAtual;

	// Entrada dos dados da data de nascimento
	printf("Digite a data de nascimento (separada por espaco): \n");
	scanf("%d %d %d", &diaNascimento, &mesNascimento, &anoNascimento);
	
	// Entrada dos dados da data atua
	printf("Digite a data atual (separada por espaco): \n");
	scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);
	// Mostrando o resultado final: 
	printf("Voce tem %d dia(s) de vida!\n", idadeEmDias(diaNascimento, mesNascimento, anoNascimento, diaAtual, mesAtual, anoAtual));

	return EXIT_SUCCESS;
}

/* PEACE! */
