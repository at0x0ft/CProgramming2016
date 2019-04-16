#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double factorial(int n)	// �K����v�Z����֐�
{
	double ans = 1.0;
	if(n < 0)
	{
		printf("Can't calcurate n!\n");
		exit(1);
	}
	else if(n == 0 || n == 1)
	{
		return ans;
	}
	else
	{
		return(n * factorial(n - 1));
	}
}

int main(void)
{
	int n, i, k;
	double e = 0.0;

	/* �����扽�ʂ܂ŕ\�����邩����͂��� (������1�ʂ��珬����15�ʂ܂�). */
	printf("Show the result by the ** decimal place.\nPut ** in the integer which is bigger than 0 and smaller than 16:** = ");
	scanf("%d", &k);
	if(!(k >= 1 && k <= 15))
	{
		printf("Error:Please put the integer which is bigger than 0 and smaller than 16.\n");
		exit(1);
	}

	// ������k�ʂ܂ł�\������K�v������̂ŁA������(k+1)�ʂ܂ł̐��m�Ȏ��R�ΐ��̒l�����߂�K�v������.
	// �����ŁAe�ɑ���1/(n!)��10��-(k+1)������������Ȃ�n���ȉ��Ō��肵�Ă���.

	n = 0;
	while(!(factorial(n) > pow(10, k + 1)))	// pow(10, -16) > 1 / n! �܂� n! > pow(10, 16)���I�������Ƃ��Ă���.
	{
		n++;
	}

	for(i = 0; i <= n + 10; i++)
	{
		e += 1.0 / factorial(i);
	}

	/* �\�����鏬���̈ʂ�ϐ��Ŏw�肵�Ă��邽�߁Ak�̒l�𕶎���Ƃ��ďo�͂��A������̘A�����g����formatstr�Ɋi�[���A���߂�formatstr��printf���g���ĕ\������. */
	char formatstr[1024];
	sprintf(formatstr,"e = %%.%df\n", k);
	printf(formatstr, e);

	return 0;
}
