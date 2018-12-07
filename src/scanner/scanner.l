/* scanner/scanner.l
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
%option nodefault
%option noyywrap
%option yylineno
%option never-interactive

%x SLIDE
%x COMMENT

%{
#include "scanner/scanner.h"
%}

%%

"/*"                   { BEGIN COMMENT; }

^#\t                   { current_type = CONTENT_HEADING; BEGIN SLIDE; }
^<\t                   { current_type = CONTENT_ALIGN_LEFT; BEGIN SLIDE; }
^>\t                   { current_type = CONTENT_ALIGN_RIGHT; BEGIN SLIDE; }
^@\t                   { current_type = CONTENT_IMAGE; BEGIN SLIDE; }
^-\t                   { current_type = CONTENT_ITEM; BEGIN SLIDE; }
^`\t                   { current_type = CONTENT_VERBOSE; BEGIN SLIDE; }
^=\t |
^\t                    { current_type = CONTENT_ALIGN_CENTER; BEGIN SLIDE; }

<COMMENT>"*/"          { BEGIN INITIAL; }
<COMMENT>([^*]|\en)+|. /* ignore everything in a comment */

<SLIDE>.+              { append_to_slide(current_type, yytext); }
<SLIDE>\n              { current_type = CONTENT_SPACER; BEGIN INITIAL; }

^;.+\n                 /* comment */
^\.\n                  { current_type = CONTENT_SPACER;
                         append_to_slide(current_type, ""); }
\n                     { add_slide(presentation, current_type, yylineno); }
.                      { handle_unknown_char_error(yylineno, yytext); }

<<EOF>>                { cleanup(); return 0; }

%%
