#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca�oes de texto por regi�o
#include <string.h> //biblioteca que armazena as strings

int registrar() //Fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio da cria��o das vari�veis strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis strings 
	printf("Digite o cpf a ser cadastrado: "); //coleta de informa��es do usu�rio
	scanf("%s", cpf); //refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //crio um novo arquivo na pasta 
	file = fopen(arquivo, "w"); // cria o arquivo e "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
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
	file = fopen(cpf,"r"); //"r" significa que o sistema est� lendo o arquivo 
	
	if(file == NULL) //caso a busca seja nula ou inexistente 
	{
		printf("N�o foi poss�vel abrir o arquivo, arquivo n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso seja encontrado o conteudo ou outra coisa denominada 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}
int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //deleta a especifica��o denominada 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usu�rio n�o se encontra no sistema.\n");
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
	int opcao=0; //definindo vari�veis1
	
	int x=1;
	
	for(x=1;x=1;)
	
	{
		system("cls");//respons�vel por limpar a tela ap�s a busca ou confirma��o
	
    	setlocale(LC_ALL, "Portuguese"); //linguagem 
	
	    printf("## Cart�rio da EBAC ##\n\n"); //in�cio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
     	printf("escolha a op��o desejada:"); //fim do menu
	
	    scanf("%d", &opcao); //armazena nossa escolha
	
        system("cls"); //limpa a tela ap�s uma tomada de decis�o
        
        switch(opcao)
        {
        	case 1:
        	registrar(); //chamada de fun��es
	    	break; //fim da primeira a��o switch
	    	
	    	case 2:
	    	consultar();
	    	break;
	    	
	    	case 3:
	    	deletar();
	        break;
	        
	        default: //op��o n�o denominada no arquivo ou algo n�o feito no sistema
	        printf("essa opcao n�o est� dispon�vel no momento!\n");
		    system("pause");
		    break;
		}
	
	    }
    }


