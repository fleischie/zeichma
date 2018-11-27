/* scanner/scanner.c
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
#include <string.h>

static char *current_slide = NULL;

void
handle_unknown_char_error (int lineno, char *text)
{
	fprintf(
		stderr,
		"Encountered unknown character (%d): %s\n",
		lineno,
		text);
}

void
add_slide (slide_t ***presentation, content_type_t t, int lineno)
{
	if (t != CONTENT_SPACER)
	{
		return;
	}

	int size;
	char *tmp;
	slide_t *new_slide;

	size = strlen(current_slide) + 1;
	new_slide = malloc(sizeof(slide_t));
	tmp = malloc(size);

	snprintf(tmp, size, "%s", current_slide);

	new_slide->type = t;
	new_slide->content = tmp;

	sb_push(*presentation, new_slide);

	// free slide from current content
	current_slide = NULL;
	free(current_slide);
}

void
append_to_slide (content_type_t t, char *s)
{
	int size;
	char *tmp;
	char *separator;

	if (current_slide == NULL)
	{
		size = strlen(s) + 2;
		current_slide = malloc(size);
		separator = "";
	}
	else
	{
		size = strlen(current_slide) + strlen(s) + 2;
		current_slide = realloc(current_slide, size);
		separator = "\n";
	}

	tmp = strdup(current_slide);
	snprintf(current_slide, size, "%s%s%s", tmp, separator, s);

	free(tmp);
}

char *
resolve_content_type (content_type_t t)
{
	switch (t) {
		case CONTENT_HEADING:
			return "Heading";
		case CONTENT_ALIGN_LEFT:
			return "Align left";
		case CONTENT_ALIGN_CENTER:
			return "Align center";
		case CONTENT_ALIGN_RIGHT:
			return "Align right";
		case CONTENT_IMAGE:
			return "Image";
		case CONTENT_ITEM:
			return "Item";
		case CONTENT_VERBOSE:
			return "Verbose";
		case CONTENT_SPACER:
			return "Space";
	}

	return "";
}

void
cleanup (void)
{
	printf("%s\n", "TODO: Finalize slidedeck.");
}
