#include<stdio.h>
#include<stdlib.h>
#include"my_tree.h"

int main(void)
{
	FILE * fp;
	const char * file_path = "test.in";
	tree count_words;
	item new_item;

	new_item.count = 1;
	fp = fopen(file_path, "r");
	initialize_tree(&count_words);

	if (!fp)
	{
		fprintf(stderr, "Can't open file.");
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%s", new_item.word) == 1)
		add_item_to_tree(new_item, &count_words);

	fclose(fp);
	show_tree_items(count_words.root);
	clear_tree(count_words.root);

	return 0;
}