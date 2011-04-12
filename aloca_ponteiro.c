#include <stdio.h>
#include <stdlib.h>

void* aloca(int size);
void desaloca(unsigned char *ponteiro);

unsigned char memoria[10000];

int main(int arg,char* args[])
{
	int i;
	for(i = 0 ; i < 10000 ; i+=4 )
	{
		memoria[i] = 0;
	}

	int* x = aloca(sizeof(int));
	*x = 128732;
	printf("%d\n",*x);

	char *y = aloca(2*sizeof(char));
	y = "ab";
	printf("%s\n",y);

	free(x);

	return(0);
}

void* aloca(int size)
{
	int i = (int)memoria[0];
	int posicao = 4;

	if(i == 0)
	{
		*memoria = (int)1;
		memoria[4] = size;
		posicao += size;
	}
	else
	{
		posicao += (int)memoria[posicao + 1];
		while(1)
		{
			if(i != 0)
			{
				break;
			}
			posicao += memoria[posicao+1] + 1;
			i = memoria[posicao];
		}
		memoria[posicao] = 1;
		memoria[posicao+1] = size;
	}

	return(&memoria[posicao]);
}

void desaloca(unsigned char *ponteiro)
{
	unsigned char* aux = (ponteiro - 8);
	*aux = 0;
	printf("%d\n",*aux);
}
