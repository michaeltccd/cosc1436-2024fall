## Symbols

ASTERISK    ::= '*'
BACKWARD_SLASH  ::= '/'
COMMA       ::= ','
DOT         ::= '.'
DOUBLE_QUOTE::= '"'
EQUAL       ::= '='
EXP         ::= 'E'
FALSE       ::= 'false'
LBRACE      ::= '{'
LPAREN      ::= '('
MINUS       ::= '-'
PERCENT     ::= '%'
PLUS        ::= '+'
RBRACE      ::= '}'
RPAREN      ::= ')'
SEMICOLON   ::= ';'
SINGLE_QUOTE::= '''
STREAM_OP   ::= '<<'
TRUE        ::= 'true'

## Primitives

```
number          ::= digit+
literal         ::= string_literal | char_literal | int_literal | float_literal | bool_literal
bool_literal    ::= TRUE | FALSE
char_literal    ::= SINGLE_QUOTE char SINGLE_QUOTE
int_literal     ::= [ PLUS | MINUS ] number
float_literal   ::= int_literal DOT number
                  | int_literal EXP [ PLUS | MINUS ] number
string_literal  ::= DOUBLE_QUOTE * DOUBLE_QUOTE
```

## Variables

```
variable-decl ::= T id [ EQUAL expr ] { COMMA id [ EQUAL expr ] }* SEMICOLON
```

## Expressions

```
expr ::= simple-expr
       | assign-expr

simple-expr ::= arithmetic-expr
              | literal
              | sizeof LPAREN expr RPAREN

arithmetic-expr ::= expr arithmetic-op expr
                  | unary-op expr
arithmetic-op ::= PLUS | MINUS | ASTERISK | BACKWARD_SLASH | PERCENT
unary-op ::= PLUS | MINUS

assign-expr ::= expr EQUAL expr
combination-expr ::= expr arithmetic-op EQUAL expr
```

## Statements

```
stmt ::= stmt-list SEMICOLON

stmt-list ::= simple-stmt
            | block-stmt
block-stmt  ::= LBRACE stmt* RBRACE
simple-stmt ::= expr 
              | output-stmt
output-stmt ::= std::cout STREAM_OP expr { STREAM_OP expr }*
```