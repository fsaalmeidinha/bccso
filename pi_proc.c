#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int arg,char** args)
{
	int t0 = 1;
	int t1 = 1;
	int t2 = 1;
	int t3 = 1;
	
	t0 = fork();
	if(t0 > 0)
		t1 = fork();
	if(t0 > 0 && t1 > 0)
		t2 = fork();
	if(t0 > 0 && t1 > 0 && t2 > 0)
		t3 = fork();
	
	if(t0 == 0 || t1 ==0 || t2 == 0 || t3 == 0)
	{
		FILE* file;
		if(t0 == 0)
		file = fopen("file0.txt","w");
		
		if(t1 == 0)
		file = fopen("file1.txt","w");
		
		if(t2 == 0)
		file = fopen("file2.txt","w");
		
		if(t3 == 0)
		file = fopen("file3.txt","w");
		
		int dentro = 0;
		int n = 0;
		
		
		if(t0 == 0)
			srandom(time(NULL)*10);
		
		if(t1 == 0)
			srandom(time(NULL)*101);
		
		if(t2 == 0)
			srandom(time(NULL)*202);
		
		if(t1 == 0)
			srandom(time(NULL)*303);
		
		while(n <= 10000000)
		{
			float rand0 = random()/(float)RAND_MAX;
			float rand1 = random()/(float)RAND_MAX;
			
			if(((rand0*rand0) + (rand1 * rand1)) <= 1)
				dentro++;
			n++;
		}
		fprintf(file,"%f",((float)dentro/(float)n));
		fclose(file);
	}
	
	if(t0 > 1 && t1 > 1 && t2 > 1 && t3 > 1)
	{
		wait();
		wait();
		wait();
		wait();
		FILE* fileToRead0 = fopen("file0.txt","r");
		FILE* fileToRead1 = fopen("file1.txt","r");
		FILE* fileToRead2 = fopen("file2.txt","r");
		FILE* fileToRead3 = fopen("file3.txt","r");

		float pi0;
		fscanf(fileToRead0,"%f",&pi0);
		float pi1;
		fscanf(fileToRead1,"%f",&pi1);
		float pi2;
		fscanf(fileToRead2,"%f",&pi2);
		float pi3;
		fscanf(fileToRead3,"%f",&pi3);

		printf("\n%f\n",pi0 + pi1 + pi2 + pi3);
		fclose(fileToRead0);
		fclose(fileToRead1);
		fclose(fileToRead2);
		fclose(fileToRead3);
	}
	
	return 0;
} 
