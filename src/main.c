/* main.c
 *
 * Copyright 2018 Karl Fleischmann
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#include "scanner/scanner.h"
#include "stb/stretchy_buffer.h"

#include <stdlib.h>
#include <stdio.h>

int
main (int argc, char **argv)
{
	if (argc > 1)
	{
		if (!(yyin = fopen(argv[1], "r")))
		{
			perror(argv[1]);
			return EXIT_FAILURE;
		}
	}

	int i, j;
	int length;
	int content_length;
	slide_t **presentation;
	content_t *content;

	initialize_presentation(&presentation);
	yylex(&presentation);

	printf("%s\n", "TODO: Start rendering.");

	length = sb_count(presentation);
	printf("Presentation is %d slides long.\n", length);

	for (i = 0; i < length; i++)
	{
		content = presentation[i]->content;
		content_length = sb_count(content);

		printf("Slide: %d (%d)\n$$$\n", i, content_length);

		for (j = 0; j < content_length; j++)
		{
			printf(
					"%4d | %d :: %s :: %s\n",
					j,
					content[j].line,
					resolve_content_type(content[j].type),
					content[j].value);
		}

		printf("%s\n", "$$$");
	}

	free_presentation(&presentation);

	return EXIT_SUCCESS;
}
