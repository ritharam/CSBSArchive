#ifndef _yy_defines_h_
#define _yy_defines_h_

#define IDENTIFIER 257
#define NUMBER 258
#define ADD_OP 259
#define MUL_OP 260
#define ASSIGN 261
#define IF 262
#define GOTO 263
#define LT 264
#define GT 265
#define EQ 266
#define NEQ 267
#define COLON 268
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
