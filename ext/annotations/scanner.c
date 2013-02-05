/* Generated by re2c 0.13.5 on Fri Jan 18 16:53:32 2013 */
// 1 "scanner.re"

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"

#include "scanner.h"

#define JJCTYPE unsigned char
#define JJCURSOR (s->start)
#define JJLIMIT (s->end)
#define JJMARKER q

int phannot_get_token(phannot_scanner_state *s, phannot_scanner_token *token) {

	char next, *q = JJCURSOR, *start = JJCURSOR;
	int status = PHANNOT_SCANNER_RETCODE_IMPOSSIBLE;

	while (PHANNOT_SCANNER_RETCODE_IMPOSSIBLE == status) {

		if (s->mode == PHANNOT_MODE_RAW) {

			if (*JJCURSOR == '\n') {
				s->active_line++;
			}

			next = *(JJCURSOR+1);

			if (*JJCURSOR == '\0' || *JJCURSOR == '@') {
				if ((next >= 'A' && next <= 'Z') || (next >= 'a' && next <= 'z')) {
					s->mode = PHANNOT_MODE_ANNOTATION;
					continue;
				}
			}

			++JJCURSOR;
			token->opcode = PHANNOT_T_IGNORE;
			return 0;

		} else {

		
// 66 "scanner.c"
		{
			JJCTYPE jjch;
			unsigned int jjaccept = 0;

			jjch = *JJCURSOR;
			switch (jjch) {
			case 0x00:	goto jj38;
			case '\t':
			case '\r':
			case ' ':	goto jj34;
			case '\n':	goto jj36;
			case '"':	goto jj10;
			case '\'':	goto jj11;
			case '(':	goto jj14;
			case ')':	goto jj16;
			case ',':	goto jj32;
			case '-':	goto jj2;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto jj4;
			case ':':	goto jj30;
			case '=':	goto jj28;
			case '@':	goto jj26;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto jj13;
			case 'F':
			case 'f':	goto jj8;
			case 'N':
			case 'n':	goto jj6;
			case 'T':
			case 't':	goto jj9;
			case '[':	goto jj22;
			case '\\':	goto jj12;
			case ']':	goto jj24;
			case '{':	goto jj18;
			case '}':	goto jj20;
			default:	goto jj40;
			}
jj2:
			++JJCURSOR;
			switch ((jjch = *JJCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto jj68;
			default:	goto jj3;
			}
jj3:
// 183 "scanner.re"
			{
			status = PHANNOT_SCANNER_RETCODE_ERR;
			break;
		}
// 177 "scanner.c"
jj4:
			jjaccept = 0;
			jjch = *(JJMARKER = ++JJCURSOR);
			goto jj69;
jj5:
// 67 "scanner.re"
			{
			token->opcode = PHANNOT_T_INTEGER;
			token->value = estrndup(start, JJCURSOR - start);
			token->len = JJCURSOR - start;
			q = JJCURSOR;
			return 0;
		}
// 191 "scanner.c"
jj6:
			++JJCURSOR;
			switch ((jjch = *JJCURSOR)) {
			case 'U':
			case 'u':	goto jj63;
			default:	goto jj44;
			}
jj7:
// 109 "scanner.re"
			{
			token->opcode = PHANNOT_T_IDENTIFIER;
			token->value = estrndup(start, JJCURSOR - start);
			token->len = JJCURSOR - start;
			q = JJCURSOR;
			return 0;
		}
// 208 "scanner.c"
jj8:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'A':
			case 'a':	goto jj58;
			default:	goto jj44;
			}
jj9:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'R':
			case 'r':	goto jj54;
			default:	goto jj44;
			}
jj10:
			jjaccept = 1;
			jjch = *(JJMARKER = ++JJCURSOR);
			if (jjch <= 0x00) goto jj3;
			goto jj52;
jj11:
			jjaccept = 1;
			jjch = *(JJMARKER = ++JJCURSOR);
			if (jjch <= 0x00) goto jj3;
			goto jj46;
jj12:
			jjch = *++JJCURSOR;
			goto jj44;
jj13:
			jjch = *++JJCURSOR;
			goto jj44;
jj14:
			++JJCURSOR;
// 117 "scanner.re"
			{
			token->opcode = PHANNOT_T_PARENTHESES_OPEN;
			return 0;
		}
// 246 "scanner.c"
jj16:
			++JJCURSOR;
// 122 "scanner.re"
			{
			token->opcode = PHANNOT_T_PARENTHESES_CLOSE;
			return 0;
		}
// 254 "scanner.c"
jj18:
			++JJCURSOR;
// 127 "scanner.re"
			{
			token->opcode = PHANNOT_T_BRACKET_OPEN;
			return 0;
		}
// 262 "scanner.c"
jj20:
			++JJCURSOR;
// 132 "scanner.re"
			{
			token->opcode = PHANNOT_T_BRACKET_CLOSE;
			return 0;
		}
// 270 "scanner.c"
jj22:
			++JJCURSOR;
// 137 "scanner.re"
			{
			token->opcode = PHANNOT_T_SBRACKET_OPEN;
			return 0;
		}
// 278 "scanner.c"
jj24:
			++JJCURSOR;
// 142 "scanner.re"
			{
			token->opcode = PHANNOT_T_SBRACKET_CLOSE;
			return 0;
		}
// 286 "scanner.c"
jj26:
			++JJCURSOR;
// 147 "scanner.re"
			{
			token->opcode = PHANNOT_T_AT;
			return 0;
		}
// 294 "scanner.c"
jj28:
			++JJCURSOR;
// 152 "scanner.re"
			{
			token->opcode = PHANNOT_T_EQUALS;
			return 0;
		}
// 302 "scanner.c"
jj30:
			++JJCURSOR;
// 157 "scanner.re"
			{
			token->opcode = PHANNOT_T_COLON;
			return 0;
		}
// 310 "scanner.c"
jj32:
			++JJCURSOR;
// 162 "scanner.re"
			{
			token->opcode = PHANNOT_T_COMMA;
			return 0;
		}
// 318 "scanner.c"
jj34:
			++JJCURSOR;
			jjch = *JJCURSOR;
			goto jj42;
jj35:
// 167 "scanner.re"
			{
			token->opcode = PHANNOT_T_IGNORE;
			return 0;
		}
// 329 "scanner.c"
jj36:
			++JJCURSOR;
// 172 "scanner.re"
			{
			s->active_line++;
			token->opcode = PHANNOT_T_IGNORE;
			return 0;
		}
// 338 "scanner.c"
jj38:
			++JJCURSOR;
// 178 "scanner.re"
			{
			status = PHANNOT_SCANNER_RETCODE_EOF;
			break;
		}
// 346 "scanner.c"
jj40:
			jjch = *++JJCURSOR;
			goto jj3;
jj41:
			++JJCURSOR;
			jjch = *JJCURSOR;
jj42:
			switch (jjch) {
			case '\t':
			case '\r':
			case ' ':	goto jj41;
			default:	goto jj35;
			}
jj43:
			++JJCURSOR;
			jjch = *JJCURSOR;
jj44:
			switch (jjch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto jj43;
			default:	goto jj7;
			}
jj45:
			++JJCURSOR;
			jjch = *JJCURSOR;
jj46:
			switch (jjch) {
			case 0x00:	goto jj47;
			case '\'':	goto jj49;
			case '\\':	goto jj48;
			default:	goto jj45;
			}
jj47:
			JJCURSOR = JJMARKER;
			switch (jjaccept) {
			case 0: 	goto jj5;
			case 1: 	goto jj3;
			}
jj48:
			++JJCURSOR;
			jjch = *JJCURSOR;
			switch (jjch) {
			case '\n':	goto jj47;
			default:	goto jj45;
			}
jj49:
			++JJCURSOR;
// 100 "scanner.re"
			{
			token->opcode = PHANNOT_T_STRING;
			token->value = estrndup(q, JJCURSOR - q - 1);
			token->len = JJCURSOR - q - 1;
			q = JJCURSOR;
			return 0;
		}
// 464 "scanner.c"
jj51:
			++JJCURSOR;
			jjch = *JJCURSOR;
jj52:
			switch (jjch) {
			case 0x00:	goto jj47;
			case '"':	goto jj49;
			case '\\':	goto jj53;
			default:	goto jj51;
			}
jj53:
			++JJCURSOR;
			jjch = *JJCURSOR;
			switch (jjch) {
			case '\n':	goto jj47;
			default:	goto jj51;
			}
jj54:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'U':
			case 'u':	goto jj55;
			default:	goto jj44;
			}
jj55:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'E':
			case 'e':	goto jj56;
			default:	goto jj44;
			}
jj56:
			++JJCURSOR;
			switch ((jjch = *JJCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto jj43;
			default:	goto jj57;
			}
jj57:
// 94 "scanner.re"
			{
			token->opcode = PHANNOT_T_TRUE;
			return 0;
		}
// 571 "scanner.c"
jj58:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'L':
			case 'l':	goto jj59;
			default:	goto jj44;
			}
jj59:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'S':
			case 's':	goto jj60;
			default:	goto jj44;
			}
jj60:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'E':
			case 'e':	goto jj61;
			default:	goto jj44;
			}
jj61:
			++JJCURSOR;
			switch ((jjch = *JJCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto jj43;
			default:	goto jj62;
			}
jj62:
// 89 "scanner.re"
			{
			token->opcode = PHANNOT_T_FALSE;
			return 0;
		}
// 668 "scanner.c"
jj63:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'L':
			case 'l':	goto jj64;
			default:	goto jj44;
			}
jj64:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case 'L':
			case 'l':	goto jj65;
			default:	goto jj44;
			}
jj65:
			++JJCURSOR;
			switch ((jjch = *JJCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto jj43;
			default:	goto jj66;
			}
jj66:
// 84 "scanner.re"
			{
			token->opcode = PHANNOT_T_NULL;
			return 0;
		}
// 758 "scanner.c"
jj67:
			jjch = *++JJCURSOR;
			switch (jjch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto jj70;
			default:	goto jj47;
			}
jj68:
			jjaccept = 0;
			JJMARKER = ++JJCURSOR;
			jjch = *JJCURSOR;
jj69:
			switch (jjch) {
			case '.':	goto jj67;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto jj68;
			default:	goto jj5;
			}
jj70:
			++JJCURSOR;
			jjch = *JJCURSOR;
			switch (jjch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto jj70;
			default:	goto jj72;
			}
jj72:
// 76 "scanner.re"
			{
			token->opcode = PHANNOT_T_DOUBLE;
			token->value = estrndup(start, JJCURSOR - start);
			token->len = JJCURSOR - start;
			q = JJCURSOR;
			return 0;
		}
// 818 "scanner.c"
		}
// 188 "scanner.re"


		}
	}

	return status;
}
