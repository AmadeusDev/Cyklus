//HW02 Patrik Tlach 24.10.2018
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

int main(int argc, char *argv[])
{
	int cnt = 0;
	int a = 0, kl = 0, za = 0, s = 0, p = 0, max = -10000, min = 10000;
	bool end = false;
	bool mimoInterval = false;
	bool firstNumber = true;
	while (1)
	{
		int ret_val=scanf("%d", &a);
		if (ret_val<0) break;
		if (a < -10000 || a > 10000)
		{
			mimoInterval = true;
			break;
		}
		else
		{
			if (firstNumber == true)
			{
				printf("%d", a);
				firstNumber = false;
			}
			else
				printf(", %d", a);
		}
		cnt++;
		if (a > 0)
			kl++;
		if (a < 0)
			za++;
		if (a % 2 == 0)
			s++;
		p += a;
		if (a > max)
			max = a;
		if (a < min)
			min = a;

		if (end)
		{
			break;
		}
		if (feof(stdin)) break;
	}
	
	if (mimoInterval)
	{
		printf("\nError: Vstup je mimo interval!\n");
		return 100;
	}	
	else
	{
		printf("\nPocet cisel: %d\n", cnt);
		printf("Pocet kladnych: %d\n", kl);
		printf("Pocet zapornych: %d\n", za);
		printf("Procento kladnych: %.2f\n", (float)((float)kl / cnt) * 100);
		printf("Procento zapornych: %.2f\n", (float)((float)za / cnt) * 100);
		printf("Pocet sudych: %d\n", s);
		printf("Pocet lichych: %d\n", cnt - s);
		printf("Procento sudych: %.2f\n", (float)((float)s / cnt) * 100);
		printf("Procento lichych: %.2f\n", (float)((float)(cnt - s) / cnt) * 100);
		printf("Prumer: %.2f\n", (float)p / cnt);
		printf("Maximum: %d\n", max);
		printf("Minimum: %d\n", min);
	}
	return 0;
}
