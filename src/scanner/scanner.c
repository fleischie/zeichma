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

void
handle_unknown_char_error (int lineno, char *text)
{
	fprintf(
		stderr,
		"Encountered unknown character (%d): %s\n",
		lineno,
		text);
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
initialize_presentation (slide_t ***presentation)
{
	slide_t *slide;

	*presentation = NULL;

	slide = malloc(sizeof(slide_t *));
	slide->content = NULL;

	sb_push(*presentation, slide);
}

void
free_presentation (slide_t ***presentation)
{
	int i, length;
	slide_t *slide;

	length = sb_count(*presentation);
	for (i = length - 1; i >= 0; i--)
	{
		slide = (*presentation)[i];

		sb_free(slide->content);
		slide->content = NULL;

		free(slide);
		slide = NULL;
	}

	sb_free(*presentation);
}

void
add_slide (slide_t ***presentation, content_type_t t)
{
	if (t != CONTENT_SPACER)
	{
		return;
	}

	slide_t *new_slide;
	new_slide = malloc(sizeof(slide_t));
	new_slide->content = NULL;

	sb_push(*presentation, new_slide);
}

void
append_to_slide (
		slide_t ***presentation,
		content_type_t t,
		char *s,
		int lineno)
{
	slide_t *slide;
	content_t current_item;

	current_item.type = t;
	current_item.value = strdup(s);
	current_item.line = lineno;

	slide = sb_last(*presentation);

	sb_push(slide->content, current_item);
}

void
cleanup (void)
{
	printf("%s\n", "TODO: Finalize slidedeck.");
}
