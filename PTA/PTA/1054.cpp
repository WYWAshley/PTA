#include<iostream>
using namespace std;
int image[603][803];
int color[17000000] = {0};
int Q1054()
{
	int row, column, maxcolor = 16999999, max = 0;
	scanf("%d %d", &column, &row);
	int half = row * column / 2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			int c;
			scanf("%d", &c);
			color[c]++;
			if (color[c] > half){
				printf("%d", c);
				system("pause");
				return 0;
			}
			if (color[c] > max) {
				max = color[c];
				maxcolor = c;
			}
		}
	}
	printf("%d", maxcolor);
	system("pause");
	return 0;
}