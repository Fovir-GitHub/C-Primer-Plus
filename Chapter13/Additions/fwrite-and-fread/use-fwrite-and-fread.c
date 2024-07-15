// Display how to use fwrite() and fread() in c.

#include<stdio.h>
#include<stdlib.h>

#define SIZE 80

int main(void)
{
	FILE* out, * in;

	// Use fwrite().
	char* str = "This is a test.";
	double number = 0.123456;

	// Open output file.
	out = fopen("fwrite1.out", "w");
	// Use fwrite() to write data in binary form.
	fwrite(str, SIZE, 1, out);
	fclose(out);

	out = fopen("fwrite2.out", "w");
	fwrite(&number, sizeof(double), 1, out);
	fclose(out);

	// Use fread().
	char read_str[SIZE];
	double num;

	// Open file.
	in = fopen("./fwrite1.out", "r");
	// Read from file in binary form.
	fread(read_str, SIZE, 1, in);
	// Output
	puts(read_str);
	fclose(in);

	in = fopen("./fwrite2.out", "r");
	fread(&num, sizeof(double), 1, in);
	printf("%lf\n", num);
	fclose(in);

	return 0;
}