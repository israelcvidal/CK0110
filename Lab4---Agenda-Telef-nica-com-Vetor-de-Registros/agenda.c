#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXREGISTROS 1000
#define MAXNOME 100
#define SIM 1
#define NAO 0

/*
	ATENÇÃO: ESTA SOLUÇÃO É A SOLUÇÃO DO STENIO, O QUE NÃO IMPLICA QUE A SUA SOLUÇÃO ESTEJA ERRADA, OU QUE A MINHA SEJA A MAIS CERTA.
	         HÁ DIVERSAS MANEIRAS DE ABORDAR UM MESMO PROBLEMA.
	
	ATENÇÃO[2]: ESTE PROGRAMA NÃO FAZ USO DE ALGORITMOS DE ORDENAÇÃO PARA MANTER A AGENDA ORDENADA, UMA VEZ QUE ISTO IMPLICARIA EM UMA MAIOR COMPLEXIDADE DO CÓDIGO, ALÉM DE ISSO NÃO TER SIDO PEDIDO (NÃO TAVA NO PDF :p ).
				PORÉM, ACREDITO QUE SEJA UM BOM EXERCÍCIO TENTAR COLOCAR AS COISAS EM ORDEM POR AQUI. ENTÃO, ESTÁ EM SUA RESPONSABILIDADE INCREMENTAR A AGENDA PARA MANTÊ-LA ORDENADA! (Há uma dica solta por ai...)
	
	ATENÇÃO[3]: O ESTILO DE CÓDIGO QUE ESTÁ NESTE PROGRAMA É O ESTILO DO STENIO, ONDE TEM UMA DAS PRINCIPAIS CARACTERÍSTICAS O NÃO USO DO 'ELSE', POIS ACHO QUE POLUI O CÓDIGO, USANDO-O APENAS EM SITUAÇÕES DE EXTREMA NECESSIDADE.
	
	Problema: A descrição do problema está no documento PDF dentro da mesma pasta em que este arquivo se encontra.

	Algumas explicações sobre alguns comandos usados neste programa: 
	- Acredito que há alguns comandos aqui que são novos pra vocês, darei uma rápida explicação do sentido e da nacessidade do uso dos mesmos neste programa.

	- strcmp:(str1, str2) A função strcmp (string comparator) nos retorna um valor inteiro:
				0 se as duas strings passadas como parâmetros são iguais
				< 0 Se o primeiro caractere de str1 tem um valor menor que o primeiro caractere de str2 (Veja a tabela ASCII)
				> 0 Se o primeiro caractere de str1 tem um valor maior que o primeiro caractere de str2.
	
	- __fpurge(): A explicação desta função é longa, por isso, peço que você pesquise sobre esta função e entenda como ela afeta a vida de programadores iniciantes em linguagem C, e o motivo pelo o qual muita gente ama ela.
					   Uma dica que posso dar sobre essa função é que existe uma opção alternativa, bastando dar um espaço na leitura de caracteres ou strings, como: scanf(" %s", ...) ou scanf(" %c", ...).
					   No Windows, esta função tem o nome de: fflush().

	- getchar(): Este comando 'congela' a tela até que o usuário tecle 'Enter'. Ele é feito para ler caracteres, logo, como toda tecla tem um caractere por trás, ao apertarmos enter, ele simplesmente 'descongela'.
			   O uso deste comando neste programa foi necessário, apesar de parecer que foi mera 'estética'. Certas vezes, o computador não dá uma pausa pra que o usuário visualize a tela, sendo assim, temos que fazer alguma coisa para que ele 'congele' pelo tempo que precisarmos.
		* TENTE VOCÊ MESMO! Comente a linha 367 e tente fazer uma busca na Agenda. 
	
	- strcpy(str_destino, str_origem): Copia o conteúdo de uma String para a outra. Aqui, para evitar problemas, o tamando da string de destino tem que ser maior ou igual ao tamanho da string de origem.

	- continue: Este comando é usado nas estruturas de repetição. Ao ser encontrado, o laço para sua execução e passa para a pŕoxima iteração, sem se importar o que tem abaixo do 'continue'.
*/


//Aqui, definimos nosso tipo AgendaTelefonica, onde temos uma série de atributos que um contato de uma Agenda telefônica real possui.*/
typedef struct AgendaTelefonica{
	char nome[MAXNOME];
	int DDD;
	int numeroTelefone;
	char tipo;
	int matricula;
	int disponivel; // Poderia ter usado o DDD ou alguma outra variável para sinalizar que a posição da agenda estava disponível, mas, por fins didáticos, preferi usar uma variável específica para isso.
}AgendaTelefonica;

// Esta função nos diz se a agenda está vazia. Ela será muito útil, já que utilizaremos ela várias vezes.
int verificaAgendaVazia(AgendaTelefonica agenda[]){
	int i;
	//Verificamos todas as posições da agenda...
	for(i = 0; i < MAXREGISTROS; i++){
		if(agenda[i].disponivel == NAO){ // Se acharmos alguma posição ocupada na Agenda, quer dizer que há algum contato cadastrado na agenda, logo, retornamos NAO, pois a agenda não está vazia.
			return NAO;
		}
	}
	return SIM; // Se passarmos por todas as posições da Agenda e não encontramos nem 1 posição vaga, isso quer dizer que não há contatos cadastrados na Agenda, logo, retornamos SIM, pois a agenda está vazia.
}

/*Aqui, sinalizamos que toda a agenda está vazia, colocando um 'SIM' na sua disponibilidade. 
  Este passo é importante, pois, diversas vezes, neste código, usaremos essa função. */
void inicializarAgenda(AgendaTelefonica agenda[]){
	int i;

	for(i = 0; i < MAXREGISTROS; i++){
		agenda[i].disponivel = SIM; // Colocamos todas as posições da agenda como disponível.
	}
}

/* Esta função nos retorna o primeiro índice disponível que ela encontrar. 
 A estratégia é percorrer todo o vetor de Agenda até encontrar uma posião vaga e, quando encontrarmos, retornamos o índice dessa posição.*/
int buscarVagasDisponiveis(AgendaTelefonica agenda[]){
	int i;

	for(i = 0; i < MAXREGISTROS; i++){
		if(agenda[i].disponivel == SIM){
			return i; // Ao encontramos uma posição vaga na agenda, retornamos o índice desta posição.
		}
	}
	return -1; // Se não encontrarmos nem 1 posição vaga, retornamos -1. O Motivo de não retornar 0 ou algum outro inteiro maior que 0 é que estes também podem ser posições do vetor (para números menores que 1000),
			  //  e, se o retornassemos, estaríamos retornado uma posição do vetor que, pelos testes feitos no laço acima, não está disponível.
}

// Esta função irá nos permitir fazer uma busca dentro do vetor da Agenda. Só precisaremos do nome buscado e da própria agenda.
int buscarContato(char nomeBuscado[], AgendaTelefonica agenda[]){
	int i;

	// Percorremos toda a agenda...
	for(i = 0; i < MAXREGISTROS; i++){
		if(strcmp(nomeBuscado, agenda[i].nome) == 0 && agenda[i].disponivel == NAO){ // Se encontrarmos um contato com o mesmo nome em uma posição que não esteja disponível (isto ficará mais claro quando você ver a função Apagar)...
    		return i; // Retornamos a posĩção deste contato na Agenda
    	}
	}
	return -1; // Caso contrário, retornamos -1, pelo mesmo motivo da função acima.
}

/*Esta é a função apagar, que usa uma estratégia bem simples: 
  Quando o usuário requisitar a exclusão de um contato da agenda, iremos buscar este contato na agenda e diremos que a posição que o mesmo está ocupado passará a não estar mais disponível.
  Assim, ela ficará livre para que possamos adicionar um novo contato por cima do contato que iremos 'excluir'.
  Tudo relacionado à exclusão do contato ocorrerá dentro da função 'apagarContato', deste o recebimento do nome contato até a 'exclusão' do mesmo.
   */
void apagarContato(AgendaTelefonica agenda[]){
	char nomeRemover[MAXNOME]; // Variável que guardará o nome do contato que queremos 'excluir'.
	int indiceContatoRemover; // Índice que o contato queremos apagar está na agenda

	system("clear");
	printf("---------------------------------REMOVER CONTATO---------------------------------\n");
	// Se a agenda estiver vazia, não há o que apagar. Logo, apenas damos um aviso e terminamos a função com um 'return'.
	if(verificaAgendaVazia(agenda) == SIM){
		printf("\nAgenda Vazia! [!]\n");
		getchar();
		return; // Apesar de nossa função ser do tipo 'void', ou seja, não retorna nada, podemos usar o comando 'return' apenas para parar o funcionamento da função, uma vez que
			    // dentro de uma função, quando o compilador encontra este comando, toda a função é encerrada, sem importar o que está depois do 'return', é como o 'break' dos laços de repetição.
	}
	// Se chegarmos aqui, é porque a nossa agenda não está vazia, caso contrário, teríamos entrado na condição acima, e a função teria sido encerrada.
	printf("\nDigite o nome do Contato que deseja remover: \n"); // Aqui, pedimos para que o usuário entre com o nome do usuário que ele deseja apagar
	scanf("%s", nomeRemover);
	__fpurge(stdin); // Darei uma explicação sobre o que é este comando no final desta função.
	
	// Aqui, fazemos uma busca dentro da agenda pelo contato com o nome que o usuário deseja excluir. Como a função de 'buscarContato' retorna um inteiro que corresponde ao índice que um dado contato ocupa dentro da agenda,
	// passamos este valor para a variável 'indiceContatoRemover', que agora pode possuir exatamente o índice que o contato que queremos excluir ocupa na agenda.
	indiceContatoRemover = buscarContato(nomeRemover, agenda);
	
	// A função 'buscarContato' também pode retornar uma resposta negativa à nossa busca, indicando que o contato que buscamos não existe na agenda. 
	// Sendo assim, o único teste que nós fazemos é se o valor retornado por 'buscarContato', que agora está em 'indiceContatoRemover', é positivo, pois se for, temos uma posição válida na agenda.
	if(indiceContatoRemover >= 0){
		printf("Contato removido com Sucesso!\n"); 
		agenda[indiceContatoRemover].disponivel = SIM; // Mudamos a disponibilidade da posição do contato que 'excluímos', que estava ocupada, para disponível.
		// Perceba que o índice da agenda que mudamos a disponibilidade é exatamente o índice retornado pela função 'buscarContato', que agora está em 'indiceContatoRemover'.
	}else{ // Caso contrário, ou seja, o valor retornado por 'buscarContato', que agora está em 'indiceContatoRemover', for negativo, isso quer dizer que o contato buscado não está na Agenda, ou seja, a busca retornou -1.
		printf("\nErro ao Remover Contato! [!]\n");
		printf("Motivo: O Contato '%s' nao esta Cadastrado na Agenda!\n", nomeRemover);
	}
	getchar(); 
}

// Esta função é responsável pela inserção de novos contatos na Agenda. Assim como na função 'apagarContato', recebemos a agenda como parâmetro e
// todo o procedimento de inserção ocorre dentro desta função.
void inserirNovoContato(AgendaTelefonica agenda[]){

	// Dados que todo contato da Agenda tem
	char nomeNovoContato[MAXNOME];
	int novoDDD;
	int novoNumero;
	char tipoNovoNumero;
	int novaMatricula;
	int indiceVaga;

	system("clear");
	printf("-----------------------INSERIR NOVO CONTATO-----------------------\n\n");
	// Aqui, buscamos uma vaga disponível na agennda por meio da função 'buscarVagasDisponiveis'.
	indiceVaga = buscarVagasDisponiveis(agenda); 
	// Se recebermos -1 como resultado, isto quer dizer que nossa agenda está cheia (dê uma olhada na função 'buscarVagasDisponiveis')
	if(indiceVaga == -1){
		printf("\nErro ao Adicionar contato! [!]\n");
		printf("Motivo: A Agenda esta Cheia!\n\n");
		// Nas linhas abaixo, damos ao usuário a chance de Inserir de inserir um novo contato na agenda.
		printf("\nDeseja excluir algum contato agora? [?]\n");
		printf("1 - Sim\n");
		printf("0 - Nao\n");
		scanf("%d", &indiceVaga); // Reeusamos a variável 'indiceVaga' para receber a resposta do usuário sobre excluir um contato da agenda.
		if(indiceVaga == 1){ // Se o usuário responder que sim, chamaos a função 'apagarContato', pra que o usuário possa excluir um contato e a agenda volte a ter espaço para novos contatos.
			apagarContato(agenda);
		}
		// Após a chamada, terminamos a função.
		return;	
	}

	// Se chegamos neste ponto, foi porque não entramos na condição acima, o que quer dizer que indiceVaga != -1, o que nos diz que ainda há vagas na agenda. 
	printf("Digite as infomacoes abaixo para cadastrar um novo Contato: \n");
	printf("Nome: \n");
	scanf("%s", nomeNovoContato);
    __fpurge(stdin);
    // Após lermos o nome do novo contato à ser inserido na agenda, fazemos uma rápida busca na agenda para nos certificarmos que não há outro contato com o mesmo nome. 
    // Perceba que já utilizamos a função 'buscarContato' em dois contextos diferentes, um para inserir e outro para excluir um contato. REUSE SEU CÓDIGO!
    if(buscarContato(nomeNovoContato, agenda) >= 0){ // Se 'buscarContato' retornar um número positivo, isso quer dizer que este contato já existe na Agenda, pois este valor retornado corresponde exatamente à posição do contato na agenda.
    	// Se o contato já existir na agenda...
    	printf("\nErro ao adicionar Contato! [!]\n");
    	printf("Motivo: O contato '%s' ja existe na Agenda!", nomeNovoContato);
		getchar();
    	return;
    }
    // Perceba que na condição acima não faço uso de variáveis auxiliares para receber o valor retornado pela função 'buscarContato', pois também podemos trabalhar diretamente com o valor retornado pela função.

    // Neste ponto, pela condição acima, temos a certeza que o valor retornado é negativo, sendo assim, não há nem 1 contato com o nome do novo contato que o usuário deseja cadastrar.
	// Recebemos os dados do novo contato
	printf("Matricula do novo contato: \n");
	scanf("%d", &novaMatricula);
	printf("DDD: \n");
	scanf("%d", &novoDDD);
	printf("Numero do Telefone: \n");
	scanf("%d", &novoNumero);
	__fpurge(stdin);
	printf("Tipo do numero do novo contato: \n");
	scanf("%c", &tipoNovoNumero);
	
	// Neste momento, passamos todas as informações do novo contato para a posição que encontramos na Agenda na linha 154
	// Perceba que a posição do vetor em que fazemos as alterações é exatamente na posição que nossa busca nos retornou.
	strcpy(agenda[indiceVaga].nome, nomeNovoContato);
	agenda[indiceVaga].numeroTelefone = novoNumero;
	agenda[indiceVaga].DDD = novoDDD;
	agenda[indiceVaga].tipo = tipoNovoNumero;
	agenda[indiceVaga].matricula = novaMatricula;
	agenda[indiceVaga].disponivel = 0; // Aqui, dizemos que a posição não está mais disponível.

	// Daqui em diante, mostramos as informações do novo contato para o usuário.
	printf("\nNovo contato cadastrado com sucesso!\n");
	printf("Dados do novo contato: \n");
	printf("\nNome: %s\n",  agenda[indiceVaga].nome);
	printf("Telefone: (%d) %d\n", agenda[indiceVaga].DDD, agenda[indiceVaga].numeroTelefone);
	printf("Tipo do Telefone: ");
	if(agenda[indiceVaga].tipo == 'c' || agenda[indiceVaga].tipo == 'C'){
		printf("Celular\n");
	}else{
		printf("Fixo\n");
	}
	__fpurge(stdin);
	getchar();		
}

// Esta função lista todos os usuários da Agenda.
void listarContatos(AgendaTelefonica agenda[]){
	int i;

	system("clear");
	printf("---------------------------------CONTATOS---------------------------------\n");
	// Antes de qualquer coisa, verificamos se a agenda está vazia.
	if(verificaAgendaVazia(agenda) == SIM){
		// Se estiver, perguntamos ao usuário se o mesmo deseja adicionar um novo Contato à agenda.
		printf("\nAgenda Vazia! [!]\n");
		printf("\nDeseja adicionar um novo contato agora? [?]\n");
		printf("1 - Sim\n");
		printf("0 - Nao\n");
		scanf("%d", &i);// Usamos a variável que iríamos usar no laço abaixo.
		if(i == 1){
			inserirNovoContato(agenda); // Se o mesmo responder sim, chamaos a função 'inserirNovoContato' para que um novo contato seja inserido na Agenda.
		}
		// Se for respondido que não, terminamos a função, já que, como entramos nesta condicional, a agenda está vazia.
		return;
	}
	// Caso contrário, percorremos toda a agenda.
	for(i = 0; i < MAXREGISTROS; i++){
		// Se a posição do vetor analizada não estiver disponível, quer dizer que há um contato lá, e então imprimimos as informações do contato que está ocupando a posição. 
		if(agenda[i].disponivel == NAO){
			printf("\nNome: %s\n",  agenda[i].nome);
			printf("Telefone: (%d) %d\n", agenda[i].DDD, agenda[i].numeroTelefone);
			printf("Tipo do Telefone: ");
			if(agenda[i].tipo == 'c' || agenda[i].tipo == 'C'){
				printf("Celular\n");
			}else{
				printf("Fixo\n");
			}
		}
	}
	getchar();
}
// Aqui fazemos a leitura dos dados diretamente do Arquivo.
void lerAgendaArquivo(AgendaTelefonica agenda[], FILE *arquivo){
	int i = 0;
	while(!feof(arquivo)){
		// Como as informações da agenda estão organizadas uma por linha, daremos um '\n' à cada leitura de dados.
		fscanf(arquivo, "%d\n%s\n%d\n%d\n%c\n", &agenda[i].matricula, agenda[i].nome, &agenda[i].DDD,
												&agenda[i].numeroTelefone, &agenda[i].tipo);		
		agenda[i].disponivel = 0; // E para cada posição da agenda lida, dizemos que ela está ocupada.
		i++;
	}
}

// Este é o menu básisco de operações da agenda.
void menu(){
	system("clear");
	printf("\n---------------------------------MENU---------------------------------\n");
	printf("\nDigite uma das opcoes abaixo para utilizar a Agenda: \n");
	printf("'B' ou 'b' - Buscar telefone pelo nome\n");
	printf("'I' ou 'i' - Inserir novo Registro\n");
	printf("'A' ou 'a' - Apagar Registro pelo nome\n");
	printf("'L' ou 'l' - Listar nomes na Agenda\n");
	printf("'S' ou 's' - Sair da Agenda\n");
}

int main(int argc, char const *argv[]){
	
	FILE *arquivo; // Ponteiro para o Arquivo que utilizaremos.
	AgendaTelefonica agenda[MAXREGISTROS]; // Vetor da Agenda
	char opcao; // Variável que guardará a escolha no menu pelo usuário
	
	inicializarAgenda(agenda); // Inicializamos toda a agenda, dizendo que todas as posições estão disponíveis.

	// Se tivermos dois argumentos, quer dizer que um arquivo foi passado na linha de comando, portanto, abrimos o arquivo para leitura e passamos os valores para o vetor da Agenda.
	if(argc == 2){
		arquivo = fopen(argv[1], "r");
		lerAgendaArquivo(agenda, arquivo);
	}

	opcao = 'a'; /*Como você já deve ter percebido, ao criar uma variável, ela recebe valores aleatórios na sua criação, o que deixa a chance de ela receber qualquer valor.
				Como 'opcao' é do tipo char, nada impede que, por algum acaso, ela seja criada com o caractere 's' ou 'S' dentro dela, o que faria com que nós não entrassemos no laço 'while' abaixo.
	 			EU acredito que é uma boa prática sempre inicializar as variáveis. ;)*/

	// Enquanto o usuário não quiser sair do programa...
	while(opcao != 's' && opcao != 'S'){
		
		menu(); // Chamamos o MENU
		scanf("%c", &opcao); // Lemos a opção do Usuário
		__fpurge(stdin);
		
		// E daqui em diante, apenas direcionamos o usuário para a opção que ele deseja realizar com base na sua opção.

		if(opcao == 'i' || opcao == 'I'){
			inserirNovoContato(agenda);
		}

		if(opcao == 'a' || opcao == 'A'){
			apagarContato(agenda);
		}

		if(opcao == 'l' || opcao == 'L'){
			listarContatos(agenda);
		}

		// O motivo do 'Buscar Contato' ter ficado na 'main', foi que, como eu faço o reuso da função de busca, não fica legal ficar pedindo informações quando na verdade o nosso objetivo é mais direto, apenas conseguir um índice.
		// Sendo assim, para não ter que criar uma nova função, deixei o buscar bem aqui.
		if(opcao == 'b' || opcao == 'B'){
			system("clear");
			printf("\n---------------------------------BUSCAR CONTATO---------------------------------\n");
			// Se a agenda estiver vazia....
			if(verificaAgendaVazia(agenda) == SIM){
				int opcao;
				printf("\nErro ao Buscar Contato! [!]\n");
				printf("Motivo: A agenda esta vazia!\n\n");
				printf("Deseja adicionar um novo contato a Agenda agora? [?]\n");
				printf("1 - Sim\n");
				printf("0 - Nao\n");
				scanf("%d", &opcao);
				if(opcao == SIM){ // Se o usuário quiser adicionar um novo contato...
					inserirNovoContato(agenda);
				}else{
					continue; // Se não, passamos para a próxima iteração do laço 'while'.
				}			
			}

			// Se a agenda não está vazia, isso quer dizer que há contatos na agenda.
			char nomeBuscado[MAXNOME]; // Variável que usaremos para ler o contato que queremos buscar.
			int indiceAuxiliar; // Variável que Armazenará o índice em que o contato está (ou a resposta de que ele não está na Agenda).
			// Lemos o nome do contato que o usuário deseja buscar na Agenda:
			printf("Digite o nome do Contato que deseja buscar: \n");
			scanf("%s", nomeBuscado);
			__fpurge();
			indiceAuxiliar = buscarContato(nomeBuscado, agenda); // Buscamos o contato na Agenda.
			
			// Se a resposta retornada por 'buscarContato' for válida (positiva), nós encontramos o contato que o usuário está procurando.
			if(indiceAuxiliar >= 0){	
				printf("\nContato Encontrado!\n");
				printf("%s - (%d) %d ", agenda[indiceAuxiliar].nome, agenda[indiceAuxiliar].DDD, agenda[indiceAuxiliar].numeroTelefone);
				if(agenda[indiceAuxiliar].tipo == 'c' || agenda[indiceAuxiliar].tipo == 'C'){
					printf("- Celular\n");
				}else{
					printf("- Fixo\n");
				}
			}else{
				// Caso contrário, dizemos que o contato não existe.
				printf("Erro! O Contato buscado nao existe! [!]\n");
			}		
			getchar();
		}
	}
	return EXIT_SUCCESS;
}

/* PEACE! */
