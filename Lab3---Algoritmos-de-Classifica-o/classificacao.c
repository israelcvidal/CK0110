#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 5000

/*
	ATENÇÃO: ESTA SOLUÇÃO É A SOLUÇÃO DO STENIO, O QUE NÃO IMPLICA QUE A SUA SOLUÇÃO ESTEJA ERRADA, OU QUE A MINHA SEJA A MAIS CERTA.
	         HÁ DIVERSAS MANEIRAS DE ABORDAR UM MESMO PROBLEMA.

	Problema: 

	Estratégia usada: Para cada algoritmo analizado, iremos calcular o seu tempo de início e tempo de fim.
					  Após saber o tempo de início e o tempo de fim do algoritmo, faremos a subtração dos mesmos (fim - início, respectivamente)
					  e dividiremos por CLOCKS_PER_SEC para sabermos o tempo gasto pela CPU para executar o Algoritmo.

	Algoritmo usado: Entrada: Um vetor e o seu tamanho
					 Saída: Um número que indicará o tempo que a CPU demorou pra realizar o Algoritmo em milissegundos

					 tempoInicioAlgoritmo <- clock() //"Conta no relógio a hora em que o algoritmo começou a funcionar"
					 preencherVetor
					 ordene_com_algoritmo_analizado
					 tempoFimAlgoritmo <- clock() //"Conta no relógio a hora em que o algoritmo acabou"

					 retorne (fim_Algoritmo - inicio_Algoritmo) / CLOCKS_PER_SEC

	* IMPORTANTE: Perceba que, após a realização de cada função de classificação o vetor é povoado novamente com números aleatórios,
				  isso porque na classificação anterior (com exceção do primeiro), o vetor já foi ordenado, então, se não o embaralhassemos novamente,
				  os valores que lá estariam já estariam ordenados.

	* Análise dos Algoritmos: O Algoritmo Bolha é o melhor quando temos poucos elementos. Quanto mais elementos, pior ele fica.
							  Quanto mais números, melhor é o funcionamento do insertionSort e do SelectionSort. Porém, o SelectionSort sempre possui um melhor desemepenho.
							  O motivo disso deverá ser estudado na cadeira de Estruturas de Dados, com o professor Vitor Campos.
						
*/

// Esta função nos permite preencher um vetor inteiro com valores aleatórios
void povoarVetor(int vetor[], int tamanho){
	int i;
	/* UM POUCO SOBRE srand(time(NULL)): 
		- A função rand() gera uma sequência de valores que se repete igual a si própria sempre que o programa é executado.
		- Isto, porque, a semente da sequência é sempre a mesma (1)!
		- Para que produza-se uma sequência diferente, é necessário mudar a semente usando a função srand(), cujo argumento inteiro (sem sinal) é a nova semente e que não retorna nenhum valor.
		- Se se pretender uma sequência diferente sempre que o programa é executado e o utilizador não seja obrigado a introduzir a semente, podemos usar uma função que retorna o valor do relógio do computador em segundos, no caso, time(NULL).
	*/
	srand(time(NULL)); // Gerando semente aleatória
	for(i = 0; i < tamanho; i++){
		vetor[i] = rand() % 50000001; // Cada posição do vetor receberá o mod de um número aleatório (rand()) com o número 50000001.
	}
}

// Execução do Algoritmo Insertion_Sort, passando nosso vetor e o tamanho do mesmo como parâmetro.
void insertionSort(int vetor[], int tamanho){
	int i;
	int aux;

	for(i = 1; i < tamanho; i++){
		while((i != 0) && (vetor[i] < vetor[i - 1])){
			aux = vetor[i];
			vetor[i] = vetor[i - 1];
			vetor[i - 1] = aux;
			i--;
		}
	}
}

// Execução do Algoritmo Selection_Sort, passando nosso vetor e o tamanho do mesmo como parâmetro.
void selectionSort(int vetor[], int tamanho){
	int i, j;
	int min, swap;

	for(i = 0; i < (tamanho - 1); i++){
		min = i;
		for(j = (i + 1); j < tamanho; j++){
			if(vetor[j] < vetor[min]){
				min = j;
			}
		}
		if(i != min){
			swap = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = swap;
		}
	}
}

// Execução do Algoritmo Bubble_Sort, passando nosso vetor e o tamanho do mesmo como parâmetro.
void bubbleSort(int vetor[], int tamanho){
	int i;
	int j;
	int aux;

	for(i = 0; i < tamanho; i++){
		for(j = i + 1; j < tamanho; j++){
			if(vetor[i] > vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

double classificacaoBolha(int vetor[], int tamanho){

	clock_t inicioBolha, fimBolha; // Variáveis do tipo clock_t, que guadarão o tempo de início e o tempo de fim do Algoritmo

	inicioBolha = clock(); // Marca o tempo de início do Algoritmo
	povoarVetor(vetor, tamanho); // Preenche o vetor com números aleatórios
	bubbleSort(vetor, tamanho); // Ordena o Vetor
	fimBolha = clock(); // Marca o tempo de fim de execução do Algoritmo

	return (double)(fimBolha - inicioBolha)/CLOCKS_PER_SEC; // Subtrai o tempo de fim pelo tempo de início e divide pelo tempo de Clocks por segundo da CPU
}

/*AS 2 PRÓXIMAS FUNÇÕES FUNCIONAM EXATAMENTO COMO A FUNÇÃO ACIMA*/

double classificacaoInsertionSort(int vetor[], int tamanho){

	clock_t inicioInsertion, fimInsertion;

	inicioInsertion = clock();
	povoarVetor(vetor, tamanho);
	insertionSort(vetor, tamanho);
	fimInsertion = clock();

	return (double)(fimInsertion - inicioInsertion)/CLOCKS_PER_SEC;
}

double classificacaoSelectionSort(int vetor[], int tamanho){

	clock_t inicioSelectionSort, fimSelectionSort;

	inicioSelectionSort = clock();
	povoarVetor(vetor, tamanho);
	selectionSort(vetor, tamanho);
	fimSelectionSort = clock();

	return (double)(fimSelectionSort - inicioSelectionSort)/CLOCKS_PER_SEC;
}

int main(int argc, char const *argv[]){

	int vetor[TAMANHO];

	// Chamadas das funções de classificação de cada Algoritmo
	printf("Classificacao Bolha: %f\n", classificacaoBolha(vetor, TAMANHO));
	printf("Classificacao Insertion Sort: %f\n", classificacaoInsertionSort(vetor, TAMANHO));
	printf("Classificaco Selection Sort: %f\n", classificacaoSelectionSort(vetor, TAMANHO));

	return EXIT_SUCCESS;
}

/* PEACE! */
