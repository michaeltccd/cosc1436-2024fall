## Primitives

```
number          ::= digit+
literal         ::= string_literal | char_literal | int_literal | float_literal | bool_literal
bool_literal    ::= true | false
char_literal    ::= '.'
int_literal     ::= [+ | -] number
float_literal   ::= int_literal . number
                  | int_literal (E | e) [+ | -] number
string_literal  ::= "..."
```

## Variables

```
variable-decl ::= T id [ = expr ] { , id [ = expr ] }* ;
```

## Expressions

```
expr ::= simple-expr
       | assign-expr
       | type-cast

simple-expr ::= arithmetic-expr
              | literal
              | sizeof ( expr )

arithmetic-expr ::= expr arithmetic-op expr
                  | unary-op expr
arithmetic-op ::= + | - | * | / | %
unary-op ::= + | -

assign-expr ::= expr = expr
combination-expr ::= expr arithmetic-op = expr

type-cast ::= static_cast<T>(expr)
            | (T)expr
```

## Statements

```
stmt ::= stmt-list ;

stmt-list ::= simple-stmt
            | block-stmt
block-stmt  ::= { stmt* }
simple-stmt ::= expr 
              | output-stmt
output-stmt ::= std::cout << output_expr { << output_expr }*
output-expr ::= expr | iomanip
iomanip     ::= setw(int) | left | right | fixed | setprecision(int) | setfill(char)
input-stmt  ::= std::cin >> expr { >> expr }*
              | std::getline(std::cin, expr)
```

## Math Functions

```
math-funcs ::= abs(expr) | ceil(expr) | floor(expr)   
             | pow(expr) | sqrt(expr)  
             | exp(expr) | log(expr)
             | round(expr) | trunc(expr)
```