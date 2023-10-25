#include <stdio.h>
#include "student.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	struct student rec;
	FILE *fp;

	if (argc != 2) {
		fprintf(stderr, "How to use: %s FileName\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "wb");
	printf("%-15s %-13s %-11s %-9s %-7s %-5s\n", "id", "bookname", "author","year", "numofboorow","borrow");
	while (scanf("%d %s %s %hd %d %s", &rec.id, rec.bookname, rec.author, &rec.year, &rec.numofboorow, rec.borrow) == 6)
		fwrite(&rec, sizeof(rec), 1, fp);

	fclose(fp);
	exit(0);
}
