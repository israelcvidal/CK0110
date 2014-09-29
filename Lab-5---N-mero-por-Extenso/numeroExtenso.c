#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	ATENÇÃO: ESTA SOLUÇÃO É A SOLUÇÃO DO STENIO, O QUE NÃO IMPLICA QUE A SUA SOLUÇÃO ESTEJA ERRADA, OU QUE A MINHA SEJA A MAIS CERTA.
	         HÁ DIVERSAS MANEIRAS DE ABORDAR UM MESMO PROBLEMA.
	
	OBS: Esta solução não usou o vetor buffer que foi dado como dica de uso na descrição do problema.
	
	ESTRATÉGIA USADA: Separar cada parte do número de entrada em sua Centena, Dezena e Unidade, depois disso, encontrar o extenso de acada uma delas
						por meio das funções implementadas no Código e, posteriormente, concatenar todas estas Strings em uma só.
*/

//Descobrindo o Valor da Centena
int centena(int n){
	return n / 100;
}

//Descobrindo o Valor da Dezena
int dezena(int n){ 
	return (((n - centena(n) * 100) - n % 10))/10;
}

//Descobrindo o Valor da Unidade
int unidade(int n){
	return n % 10;
}
//Esta função calcula o tamanho de uma string passada como parâmetro.
//O parâmetro recebido é um ponteiro de char, o que o torna uma String.
int tamanhoString(char *string){
	int contador = 0; //Contador de caracteres na String
	//Enquanto não encontrar o fim da String...
	while(string[contador] != '\0'){
		contador++; //++ no contador
	}
	return contador; // retorna o contador
}

//Todas as funções abaixo retornam um ponteiro para caractere, ou seja, Strings.

//Verificamos o valor da Unidade do número de entrada e retornamos o seu valor por extenso
char * unidadePorExtenso(int unid){
	if(unid == 1){
		return "Um";
	}
	if(unid == 2){
		return "Dois";
	}
	if(unid == 3){
		return "Tres";
	}
	if(unid == 4){
		return "Quatro";
	}
	if(unid == 5){
		return "Cinco";
	}
	if(unid == 6){
		return "Seis";
	}
	if(unid == 7){
		return "Sete";
	}
	if(unid == 8){
		return "Oito";
	}
	if(unid == 9){
		return "Nove";
	}
}

char * dezenasPorExtenso(int dez, int unid){
	if(dez == 1){ // números entre 10 e 19 (inclusive) ocorrem quando a dezena é 1
		if(unid == 0){
			return "Dez";
		}
		if(unid == 1){
			return "Onze";
		}
		if(unid == 2){
			return "Doze";
		}
		if(unid == 3){
			return "Treze";
		}
		if(unid == 4){
			return "Quatorze";
		}
		if(unid == 5){
			return "Quinze";
		}
		if(unid == 6){
			return "Dezesseis";
		}
		if(unid == 7){
			return "Dezesete";
		}
		if(unid == 8){
			return "Dezoito";
		}
		if(unid == 9){
			return "Dezenove";
		}
	}
	//Daqui em diante, verificamos se a unidade do número é 0, se for, estaremos nas "dezenas fechadas" (10, 20, 30...) (salvo engano tem um nome pra esses números)
	//Se este não for o caso, ainda haverá algo a mais a se falar do número, por isso, retornamos "Número e ".
	if(dez == 2){
		if(unid == 0){
			return "Vinte";
		}
		return "Vinte e ";
	}
	if(dez == 3){
		if(unid == 0){
			return "Trinta";
		}
		return "Trinta e ";
	}
	if(dez == 4){
		if(unid == 0){
			return "Quarenta";
		}
		return "Quarenta e ";
	}
	if(dez == 5){
		if(unid == 0){
			return "Cinquenta";
		}
		return "Cinquenta e ";
	}
	if(dez == 6){
		if(unid == 0){
			return "Sessenta";
		}
		return "Sessenta e ";
	}
	if(dez == 7){
		if(unid == 0){
			return "Setenta";
		}
		return "Setenta e ";
	}
	if(dez == 8){
		if(unid == 0){
			return "Oitenta";
		}
		return "Oitenta e ";
	}
	if(dez == 9){
		if(unid == 0){
			return "Noventa";
		}
		return "Noventa e ";
	}
}

//Como anteriormente, verificaremos primeiro se o número é uma "centena fechada" (100, 200, 300...) verificando se sua dezena e unidades são 0.
//Se este não for o caso, temos que analizar a dezena e unidade do número, retornando "Centena e " e deixando que as funções de dezena e unidade cuidem do resto.
char * centenaPorExtenso(int cent, int dez, int unid){
	if(cent == 1){		
		if(dez == 0 && unid == 0){
			return "Cem";
		}
		return "Cento e ";
	}
	if(cent == 2){		
		if(dez == 0 && unid == 0){
			return "Duzentos";
		}
		return "Duzentos e ";
	}
	if(cent == 3){		
		if(dez == 0 && unid == 0){
			return "Trezentos";
		}
		return "Trezentos e ";
	}
	if(cent == 4){		
		if(dez == 0 && unid == 0){
			return "Quatrocentos";
		}
		return "Quatrocentos e ";
	}
	if(cent == 5){		
		if(dez == 0 && unid == 0){
			return "Quinhetos";
		}
		return "Quinhetos e ";
	}
	if(cent == 6){		
		if(dez == 0 && unid == 0){
			return "Seiscentos";
		}
		return "Seiscentos e ";
	}
	if(cent == 7){		
		if(dez == 0 && unid == 0){
			return "Setecentos";
		}
		return "Setecentos e ";
	}
	if(cent == 8){		
		if(dez == 0 && unid == 0){
			return "Oitocentos";
		}
		return "Oitocentos e";
	}
	if(cent == 9){		
		if(dez == 0 && unid == 0){
			return "Novecentos";
		}
		return "Novecentos e ";
	}
}

//E é aqui que as coisas serão controladas e verificadas. 
//Esta função tem como objetivo calcular o nome por extenso do número, tendo como retorno um ponteiro para char, que será o nome do número por extenso..
//OBS: Não é necessário usar todas as variáveis usadas abaixo, porém, para fins didáticos para um melhor entendimento, resolvi fazer dessa forma.
char * numeroPorExtenso(int numero){
	//Se o número for 0, 00 ou 000:	
	if(numero == 0){
		return "Zero";
	}

	//Variávels que armazenarão a centena, dezena e unidade do número de entrada
	int cent;
	int dez;
	int unid;
	//Variáveis que nos dirão o tamanho exato para alocação de uma determinada String, sem desperdicio de espaço.
	int tamanhoStringCentena;
	int tamanhoStringDezena;
	int tamanhoStringUnidade;

	//Ponteiros que guardarão o nome de cada pedaço (centena, dezena e unidade) do número.
	char *centenasExtenso;
	char *dezenasExtenso;
	char *unidadesExtenso;
	char *numeroExtenso; //Ao fim de tudo, concatenaremos todas as Strings nesta outra e retornaremos a mesma.

	//Cálculo das partes do número (dezena, centena e unidade)
	cent = centena(numero);
	dez = dezena(numero);
	unid = unidade(numero);
	//Os blocos condicionais sinalizam os casos em que precisamos de uma atenção a mais.
	//Iremos analizar este caso se o nosso número estiver entre 10 e 19
	if(cent == 0 & dez == 1){
		tamanhoStringDezena = tamanhoString(dezenasPorExtenso(dez, unid)); // Calcula o tamanho da String
		dezenasExtenso = (char*)malloc(tamanhoStringDezena*sizeof(char)); // Aloca exatamente o que é necessário para armazenar o número por extenso
		dezenasExtenso = dezenasPorExtenso(dez, unid); //Atribuímos o extenso da Dezena na variável 'dezenasExtenso' e a retornamos.

		return dezenasExtenso;
	}
	//Neste caso, temos que analizar apenas a unidade, uma vez que a dezena e centena serão 0.
	if(dez == 0 && cent == 0){
		tamanhoStringUnidade = tamanhoString(unidadePorExtenso(unid)); // Calcula o tamanho da String
		unidadesExtenso = (char*)malloc(tamanhoStringUnidade*sizeof(char)); // Aloca apenas o que precisa com base na linha acima
		unidadesExtenso = unidadePorExtenso(unid); // Atribui o nome da unidade na variável 'unidadesExtenso' e a retorna.

		return unidadesExtenso;		
	}
	//Aqui, temos um número entre 0 e 99
	if(cent == 0){
		/*Assim como antes,
		1 - Calculamos o tamanho da Palavra
		2 - Alocamos exatamente este espaço
		3 - Atribuímos esta String à uma variável*/
		//Neste caso, como a centena é 0, só precisamos nos preocuar com a dezena e com a unidade.
		tamanhoStringDezena = tamanhoString(dezenasPorExtenso(dez, unid));
		dezenasExtenso = (char*)malloc(tamanhoStringDezena*sizeof(char));
		dezenasExtenso = dezenasPorExtenso(dez, unid);

		tamanhoStringUnidade = tamanhoString(unidadePorExtenso(unid));
		unidadesExtenso = (char*)malloc(tamanhoStringUnidade*sizeof(char));
		unidadesExtenso = unidadePorExtenso(unid);
		//Alocamos exatamente o que iremos precisar somando os tamanhos dos espaços que já armazenamos antes.
		numeroExtenso = (char*)malloc((tamanhoStringDezena + tamanhoStringUnidade)*sizeof(char));
		strcat(numeroExtenso, dezenasExtenso); //Seguindo a ordem Centena, Dezena e Unidade, concatenamos primeiro a dezena ao 'numeroExtenso'
		strcat(numeroExtenso, unidadesExtenso); // e só depois a UNidade.
		
		return numeroExtenso; //Retornamos o número que foi criado a partir da concatenação da Dezena com a Unidade.
	}

	//Como em nemhum dos casos acima foi necessário o uso da Centena, só agora começamos a manipulá-la.
	tamanhoStringCentena = tamanhoString(centenaPorExtenso(cent, dez, unid));
	centenasExtenso = (char*)malloc(tamanhoStringCentena*sizeof(char));
	centenasExtenso = centenaPorExtenso(cent, dez, unid);
	//Como chegamos aqui, isso quer dizer que a centena não é 0, caso contrário, teríamos ficado em alguma das condições acima portanto, estamos entre 100 e 999.
	if(dez == 1){
		//Se a dezena for 1, é por que estamos em alguma centena somado a alguma dezezna entre 10 e 19
		tamanhoStringDezena = tamanhoString(dezenasPorExtenso(dez, unid));
		dezenasExtenso = (char*)malloc(tamanhoStringDezena*sizeof(char));
		dezenasExtenso = dezenasPorExtenso(dez, unid);
		//Somamos o que já foi alocado e calculado para a centena ao que foi alocado e calculado para a dezena e alocamos 'numeroExtenso' de acordo com estes valores
		numeroExtenso = (char*)malloc((tamanhoStringDezena + tamanhoStringCentena)*sizeof(char));
		strcat(numeroExtenso, centenasExtenso); //Concatena a centena ao 'numeroExtenso', que inicialmente não contém nada
		strcat(numeroExtenso, dezenasExtenso); //Concatena a dezena ao que foi concatenado à String acima

		return numeroExtenso; //retorna o resultado das concatenações
	}

	//Se a dezena e a Unidade são 0, só temos a centena.
	if(dez == 0 && unid == 0){
		return centenasExtenso; 
	}
	//Se a unidade for 0, só temos que verificar a centena e a Unidade
	if(unid == 0){
		tamanhoStringDezena = tamanhoString(dezenasPorExtenso(dez, unid));
		dezenasExtenso = (char*)malloc(tamanhoStringDezena*sizeof(char));
		dezenasExtenso = dezenasPorExtenso(dez, unid);

		numeroExtenso = (char*)malloc((tamanhoStringDezena + tamanhoStringCentena)*sizeof(char));
		strcat(numeroExtenso, centenasExtenso);
		strcat(numeroExtenso, dezenasExtenso);

		return numeroExtenso;
	}

	//Se a dezena for 0, só nos preocupamos coma a centena e a unidade
	if(dez == 0){
		tamanhoStringUnidade = tamanhoString(unidadePorExtenso(unid));
		unidadesExtenso = (char*)malloc(tamanhoStringUnidade*sizeof(char));
		unidadesExtenso = unidadePorExtenso(unid);

		numeroExtenso = (char*)malloc((tamanhoStringUnidade + tamanhoStringCentena)*sizeof(char));
		strcat(numeroExtenso, centenasExtenso);
		strcat(numeroExtenso, unidadesExtenso);

		return numeroExtenso;
	}

	//A partir daqui, todas as linhas até o fim desta função não possuem restrição, por tanto, podemos calcular a centena e a unidade à vontade, assim como colocar tudo isso para o 'numeroExtenso'.
	tamanhoStringDezena = tamanhoString(dezenasPorExtenso(dez, unid));	
	dezenasExtenso = (char*)malloc(tamanhoStringDezena*sizeof(char));
	dezenasExtenso = dezenasPorExtenso(dez, unid);

	tamanhoStringUnidade = tamanhoString(unidadePorExtenso(unid));
	unidadesExtenso = (char*)malloc(tamanhoStringUnidade*sizeof(char));
	unidadesExtenso = unidadePorExtenso(unid);
	//Alocamos o valor das 3 Strings usadas
	numeroExtenso = (char*)malloc((tamanhoStringUnidade + tamanhoStringCentena + tamanhoStringDezena)*sizeof(char));
	//Concatenamos uma-a-uma a variável 'numeroExtenso', seguindo a ordem: Centena, Dezena e Unidade.
	strcat(numeroExtenso, centenasExtenso);
	strcat(numeroExtenso, dezenasExtenso);
	strcat(numeroExtenso, unidadesExtenso);
	
	return numeroExtenso; //Retornamos a String que contém o extenso dó número de entrada
}

int main(int argc, char const *argv[]){

	FILE *arquivo; //Ponteiro de Arquivo
	int numero; //Variável que guardará o valor do número que queremos saber seu valor por extenso
	//Execução com Arquivo
	if(argc == 2){
		char *numExtenso[1000]; //Vetor de ponteiros de caracteres que guardarão os extensos de até 1000 números
		int i = 0; //Contador auxiliar

		arquivo = fopen(argv[1], "r");
		if(arquivo == NULL){
			printf("ERRO! O Arquivo nao pode ser aberto!\n");
			return EXIT_FAILURE;
		}
		system("clear");
		printf("\n\t[NUMEROS DO ARQUIVO POR EXTENSO]\n");
		while(!feof(arquivo)){
			fscanf(arquivo, "%d\n", &numero);	//Lemos o número do Arquivo
			numExtenso[i] = numeroPorExtenso(numero); //Calculamos e armazenamos o extenso do i-ésimo número no nosso vetor de ponteiros
			i++; //Atualizamos o contador para uma posição à frente.
		}
		fclose(arquivo);
		//Percorremos todo o vetor de ponteiros e imprimimos todos os extensos nas posições
		//Fazemos isso enquanto não encontrarmos o fim do vetor de Strings (ponteiro para char) 'numExtenso'
		for(i = 0; numExtenso[i] != '\0'; i++){
			printf("%s\n", numExtenso[i]); //Usamos %s para imprimir as Strings
		}
		return EXIT_SUCCESS; //Sucesso :)
	}
	
	//Caso o programa não seja chamado com Argumento...
	system("clear");
	printf("\n\t[ENTRADA DE NUMEROS PELA LINHA DE COMANDO]\n\n");
	printf("Informe o numero a ser mostrado por Extenso: ");	
	scanf("%d", &numero); //Lemos um número do usuário
	printf("%s\n", numeroPorExtenso(numero)); //E imprimimos o mesmo por extenso.

	return EXIT_SUCCESS;
}

/*PEACE!*/
