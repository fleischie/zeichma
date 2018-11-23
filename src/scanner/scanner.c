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

#include "scanner.h"

#include <stdlib.h>
#include <stdio.h>

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
add_slide (content_type_t t, int lineno)
{
	if (t != CONTENT_SPACER)
	{
		return;
	}

	printf("TODO: Flush content to slide and append (%d)\n", lineno);
}

void
append_to_slide (content_type_t t, char *s)
{
	printf(
		"TODO: Append content to current slide (%s) :: %s\n",
		resolve_content_type(t),
		s);
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
