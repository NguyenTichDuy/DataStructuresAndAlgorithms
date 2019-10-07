#include<stdio.h>

FILE *f, *f1;

int n, t, p, count = 0;
int a[100], b[100], c[100], d[100];

void Input()
{
	f = fopen("SvoiIn.txt", "r");
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &t);
	fscanf(f, "%d", &p);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &a[i]);
		fscanf(f, "%d", &b[i]);
		fscanf(f, "%d", &c[i]);
		fscanf(f, "%d", &d[i]);
	}
	fclose(f);
}

void Output()
{
	f1 = fopen("SvoiOut.txt", "w+");
	fprintf(f1, "%d", count);
	fclose(f1);
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		printf("\n%d %d %d %d", a[i], b[i], c[i], d[i]);
	}
}
void Svoi()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j] <= t && b[j] <= p && a[j] >= 0 && b[j] >= 0)
			{
				t += c[j];
				p += d[j];
				a[j] = -1;
				b[j] = -1;
				count++;
			}
		}
	}
}
int main()
{
	Input();
	print();
	Svoi();
	
	Output();
}
