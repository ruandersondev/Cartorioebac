#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocaçoes de texto por região
#include <string.h> //biblioteca que armazena as strings

int registrar() //Função responsável por cadastrar usuários no sistema
{
	//início da criação das variáveis strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis strings 
	printf("Digite o cpf a ser cadastrado: "); //coleta de informações do usuário
	scanf("%s", cpf); //refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //crio um novo arquivo na pasta 
	file = fopen(arquivo, "w"); // cria o arquivo e "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar dados "a" significa atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: " );
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" significa que o sistema está lendo o arquivo 
	
	if(file == NULL) //caso a busca seja nula ou inexistente 
	{
		printf("Não foi possível abrir o arquivo, arquivo não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso seja encontrado o conteudo ou outra coisa denominada 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}
int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //deleta a especificação denominada 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usuário não se encontra no sistema.\n");
		system("pause");
	}
	
	while(fgets(cpf, 40, file) != NULL)
	{
		printf("\nEsse cpf foi deletado com sucesso.\n");
		printf("%s", cpf);
		printf("\n\n");
	}
	
	system("pause");
	
}
int main()
{
	int opcao=0; //definindo variáveis1
	
	int x=1;
	
	for(x=1;x=1;)
	
	{
		system("cls");//responsável por limpar a tela após a busca ou confirmação
	
    	setlocale(LC_ALL, "Portuguese"); //linguagem 
	
	    printf("## Cartório da EBAC ##\n\n"); //início do menu
	    printf("Escolha a opção desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
     	printf("escolha a opção desejada:"); //fim do menu
	
	    scanf("%d", &opcao); //armazena nossa escolha
	
        system("cls"); //limpa a tela após uma tomada de decisão
        
        switch(opcao)
        {
        	case 1:
        	registrar(); //chamada de funções
	    	break; //fim da primeira ação switch
	    	
	    	case 2:
	    	consultar();
	    	break;
	    	
	    	case 3:
	    	deletar();
	        break;
	        
	        default: //opção não denominada no arquivo ou algo não feito no sistema
	        printf("essa opcao não está disponível no momento!\n");
		    system("pause");
		    break;
		}
	
	    }
    }


