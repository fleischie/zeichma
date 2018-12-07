/**
 * \file         scanner.h
 * \brief        Header file containing the scanning/parsing functionality
 *
 * Zeichma is a presentation software.
 */

/* scanner/scanner.h
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

#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>

/* ========================================================================= */
/* Definitions                                                               */
/* ========================================================================= */

/* allow parameters to be passed into the scanning call */
#define YY_DECL int yylex(slide_t ***presentation)

/* ========================================================================= */
/* Externally defined properties                                             */
/* ========================================================================= */
extern FILE *yyin;

/* ========================================================================= */
/* Data types                                                                */
/* ========================================================================= */
/**
 * \typedef      content_type_t
 * \brief        Enumeration of states for content of a slide
 */
typedef enum {
	CONTENT_HEADING = 1,
	CONTENT_ALIGN_LEFT,
	CONTENT_ALIGN_CENTER,
	CONTENT_ALIGN_RIGHT,
	CONTENT_IMAGE,
	CONTENT_ITEM,
	CONTENT_VERBOSE,
	CONTENT_SPACER,
} content_type_t;

/**
 * \typedef      content_t
 * \brief        Individual, marked up items on a slide
 */
typedef struct {
	int line;
	content_type_t type;
	char *value;
} content_t;

/**
 * \typedef      slide_t
 * \brief        Container for several content items
 */
typedef struct {
	content_t *content;
} slide_t;


/* ========================================================================= */
/* Forward function declarations                                             */
/* ========================================================================= */
/**
 * \fn           handle_unknown_char_error
 * \brief        Handle case of unknown encountered character
 */
void handle_unknown_char_error (int, char *);

/**
 * \fn           resolve_content_type
 * \brief        Return human readable representation of content type
 */
char *resolve_content_type (content_type_t);

/**
 * \fn           initialize_presentation
 * \brief        Prepare the presentation array to be usable
 */
void initialize_presentation (slide_t ***);

/**
 * \fn           free_presentation
 * \brief        De-allocate the presentation space
 */
void free_presentation (slide_t ***);

/**
 * \fn           append_to_slide
 * \brief        Append content item to current slide
 */
void append_to_slide (slide_t ***, content_type_t, char *, int);

/**
 * \fn           add_slide
 * \brief        Append current slide to presentation container
 */
void add_slide (slide_t ***, content_type_t);

/**
 * \fn           cleanup
 * \brief        Callback to handle end of scanning/parsing
 */
void cleanup (void);

/* ========================================================================= */
/* Global variables                                                          */
/* ========================================================================= */
/**
 * \var
 * \brief
 */
content_type_t current_type;

#endif // SCANNER_H_
