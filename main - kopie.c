//HW02 Patrik Tlach 24.10.2018
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
typedef int bool;
#define true 1
#define false 0

int csleol(bool*end)
{
	bool blank = true,state = true;
	char sgn = 1;
	int n = 0;
	while (1)
		
	{
		char c = getc(stdin);

		if (c == ' ')
			blank = true;
		else if (c == '\n')
		{
			*end = true;
			return n*sgn;
		}
		else {
			blank = false;
		}

		if (state == true)
		{
			if (blank == false)
				state = false;
		}
		if (state == false)
		{

			if (c == '-')
				sgn *= -1;
			else if (c == '+')
				sgn *= 1;
			else if (c >= '0' && c <= '9')
			{
				n *= 10;
				n += c - '0';
			}
			else
				return n*sgn;

			if (blank == true)
				return n*sgn;
		}
	}
}

int main(int argc, char *argv[])
{
	int cnt = 0;
	int a = 0, b = 0, kl = 0, za = 0, s = 0, p = 0, max = -10000, min = 10000;
	bool end = false;
	bool mimoInterval = false;
	bool firstNumber = true;
	while (cnt < 10000)
	{
		a = csleol(&end);
		if (a < -10000 || a > 10000)
		{
			mimoInterval = true;
			break;
		}
		else
		{
			if (firstNumber == true)
				firstNumber = false;
			else
				printf("%d, ", b);
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
		b = a;

		if (end)
		{
			break;
		}

	}
	if(!firstNumber)
	printf("%d\n", b);
	
	if (mimoInterval)
	{
		printf("Error: Vstup je mimo interval!\n");
		return 100;
	}	
	else
	{
		printf("Pocet cisel: %d\n", cnt);
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
	//system("PAUSE");
	return 0;
}
