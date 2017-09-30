#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* O Programa retornou os resultados esperados, mostrando na tela o PID (Process Identification) ou (identificador de processos) */

int main(void)
{
    int i;
    pid_t pid;

	/* este � o primeito teste para verificar se o fork foi bem sucedido */
   
   if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
	
	/* Em seguida fazemos se pid == 0, sendo o resultado positivo somente no processo filho
	sendo assim o processo pai nao entra nessa condi��o, apenas o processo filho, 
	E caso esse teste condicional seja falso, � porque o processo em vigor � o pai.*/
	
    if (pid == 0)
    {
        //O c�digo aqui dentro ser� executado no processo filho
        printf("pid do Filho: %d\n", getpid());
    }
    else
    {
        //O c�digo neste trecho ser� executado no processo pai
        printf("pid do Pai: %d\n", getpid());
    }

	/*� importante colocar algum comando que impe�a que nosso programa abra, execute e rapidamente feche, n�o sendo poss�vel ver os prints. 
	Assim, caso n�o esteja usando o Code::Blocks, 
	coloque um scanf() no final do programa, para voc� ver o resultado na tela */
    printf("Esta regiao sera executada por ambos processos\n\n");
    scanf("%d", &i);
    exit(0);
}
