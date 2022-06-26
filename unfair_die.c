#include <stdio.h>
#include "stdlib.h"
#include <time.h>

float PMF[6];
float CDF[6];

void imp_PMF(){
    printf("\n welcome ");
	printf("\n Please enter 6 PMF values ..! ");

	for(int i=0;i<6;i++){
		printf("\n Please enter PMF of number %d : ",i+1);
		scanf("%f",&PMF[i]);
	}

}

void CDF_Calc(){

	CDF[0] = PMF[0];

	for (int i=1;i<6;i++)
	{
		CDF[i]=CDF[i-1]+PMF[i];
	}

}

int prob_Calc()
{

	int temp = rand() % 101;

	if      (temp >= CDF[4]*100)
		return 6;

	else if (temp >= CDF[3]*100)
		return 5;

	else if (temp >= CDF[2]*100)
		return 4;

	else if (temp >= CDF[1]*100)
		return 3;

	else if (temp >= CDF[0]*100)
		return 2;

	else
		return 1;

}


int main()
{
    srand(time(0));

    int tri;

	imp_PMF();
	CDF_Calc();

	printf("\n\n Please enter num of tries : ");
	scanf("%d",&tri);

	for (int i=0;i<tri;i++)
	{
		printf("\n Throw %d : %d",i+1,prob_Calc());
	}


}
