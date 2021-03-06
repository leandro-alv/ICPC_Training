#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bin
{
	int bB;
	int gB;
	int cB;
};

int compare (const void * a, const void * b);

int moveEnch(struct bin bin1, struct bin bin2, struct bin bin3, char * move);

int main()
{
	struct bin bin1, bin2, bin3;
	int B=0, G=0, C=0, i=1, movesQtt=0;
	char c, bestMove[4];
	while(c != EOF)
	{
		fscanf(stdin, "%d", &B);
		fscanf(stdin, "%d", &G);
		fscanf(stdin, "%d", &C);
		c = fgetc(stdin);
		if(i%3 == 1)
		{
			bin1.bB = B;
			bin1.gB = G;
			bin1.cB = C;
		}
		else if(i%3 == 2)
		{
			bin2.bB = B;
			bin2.gB = G;
			bin2.cB = C;
		}
		else
		{
			bin3.bB = B;
			bin3.gB = G;
			bin3.cB = C;
		}
		if(i%3 == 0)
		{
			movesQtt = moveEnch(bin1, bin2, bin3, bestMove);
			printf("%s %d\n", bestMove, movesQtt);
		}
		i++;
	}
	return(0);
}

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b);
}

int moveEnch(struct bin bin1, struct bin bin2, struct bin bin3, char * move)
{
	int op1, op2, op3, op4, op5, op6, i;

	op1 = (bin2.bB + bin3.bB) + (bin1.gB + bin3.gB) + (bin1.cB + bin2.cB);

	op2 = (bin2.bB + bin3.bB) + (bin1.cB + bin3.cB) + (bin1.gB + bin2.gB);

	op3 = (bin2.gB + bin3.gB) + (bin1.cB + bin3.cB) + (bin1.bB + bin2.bB);

	op4 = (bin2.gB + bin3.gB) + (bin1.bB + bin3.bB) + (bin1.cB + bin2.cB);

	op5 = (bin2.cB + bin3.cB) + (bin1.gB + bin3.gB) + (bin1.bB + bin2.bB);

	op6 = (bin2.cB + bin3.cB) + (bin1.bB + bin3.bB) + (bin1.gB + bin2.gB);
	int vector[] = {op1, op2, op3, op4, op5, op6};
	qsort(vector, 6, sizeof(int), compare);
	
	if(vector[0] == op2) strcpy(move, "BCG");
	else if(vector[0] == op1) strcpy(move, "BGC");
	else if(vector[0] == op6) strcpy(move, "CBG");
	else if(vector[0] == op5) strcpy(move, "CGB");
	else if(vector[0] == op4) strcpy(move, "GBC");
	else strcpy(move, "GCB");
	return vector[0];
}
