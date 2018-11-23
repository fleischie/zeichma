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

	yylex();

	printf("%s\n", "TODO: Start rendering.");

	return EXIT_SUCCESS;
}
