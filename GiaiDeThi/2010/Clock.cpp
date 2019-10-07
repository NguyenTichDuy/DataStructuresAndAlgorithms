#include<stdio.h>

FILE *f, *f1;
int h,p,s;
int h1,p1,s1;

void Clock()
{
	if (s >= 0 && s < 59)
	{
		s1 = s + 1;
		h1 = h;
		p1 = p;
	}
	else if (s == 59)
	{
		s1 = 0;
		p1 = p+ 1;
		if (p >= 0 && p < 59)
		{
			h1 = h + 1;
		}
		else
		{
			p1 = 0;
			h1 = h + 1;
			if (h1 == 24)
			{
				h1 = 0;
				s1 = 1;
				p1 = 0;
			}
		}
	}
	
	
}
void Input()
{
	f = fopen("ClockIn.txt", "r");
	fscanf(f, "%d", &h);
	fscanf(f, "%d", &p);
	fscanf(f, "%d", &s);
	fclose(f);
}
void Output()
{
	f1 = fopen("ClockOut.txt", "w");
	fprintf(f1, "%d %d %d", h1, p1, s1);
	fclose(f1);
}
int main()
{
	Input();
	Clock();
	Output();
}
