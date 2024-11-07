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

type-decl ::= struct-decl
            | enum-decl
            | array-decl
            | pointer-decl

struct-decl         ::= struct id { struct-member-list } ;
struct-member-list  ::= struct-member*
struct-member       ::= field-decl
field-decl          ::= T id [ = expr ] ;

enum-decl   ::= enum id { enum-member } ;
enum-member ::= id [ = expr ] ;
```

## Functions

```
function-defn ::= function-decl function-body
function-decl ::= function-return-type id ( [ parameter-list ] )
function-body ::= { stmt* } [ ; ]
function-return-type ::= T | void | T[]

parameter-list ::= parameter { , parameter }*
                  | void
parameter ::= parameter-type [ id [ = expr ] ]
parameter-type ::= T | T& T[] 
```

## Expressions

```
expr ::= simple-expr
       | assign-expr
       | type-cast
       | prepostfix-expr
       | function-call
       | array-element
       | pointer-expr

simple-expr ::= arithmetic-expr
              | literal
              | sizeof ( expr )
              | relational-expr
              | logical-expr
              | conditional-expr

arithmetic-expr ::= expr arithmetic-op expr
                  | unary-op expr
arithmetic-op ::= + | - | * | / | %
unary-op ::= + | -

prepostfix-expr ::= V++
                  | ++V
                  | V--
                  | --V

assign-expr ::= expr = expr
combination-expr ::= expr arithmetic-op = expr

relational-expr ::= expr relational-op expr
relational-op ::= < | <= | > | >= | == | !=

logical-expr ::= expr && expr
               | expr || expr
               | !expr

type-cast ::= static_cast<T>(expr)
            | (T)expr

conditional-expr ::= Eb ? E : E

function-call ::= id ( [ argument-list ] )
argument-list ::= argument { , argument }*
argument ::= expr
```

## Statements

```
stmt ::= stmt-list ;
stmt-list ::= simple-stmt
            | block-stmt
            | decision-stmt
            | loop-stmt
            | break-stmt
            | continue-stmt
            | function-call
            | return-stmt
            
decision-stmt ::= if-stmt
                | switch-stmt

loop-stmt ::= while-stmt
            | for-stmt
            | do-stmt
            | for-range-stmt

block-stmt  ::= { stmt* }
simple-stmt ::= expr 
              | output-stmt
output-stmt ::= std::cout << output_expr { << output_expr }*
output-expr ::= expr | iomanip
iomanip     ::= setw(int) | left | right | fixed | setprecision(int) | setfill(char)
input-stmt  ::= std::cin >> expr { >> expr }*
              | std::getline(std::cin, expr)

if-stmt ::= if (expr) S [else-stmt];       
else-stmt ::= else S

switch-stmt ::= switch (expr) { case-statement-list } ;
case-statement-list ::= case-statement* [ default-statement ]
case-statement ::= case expr : S ;
default-statement ::= default : S ;

break-statement ::= break
continue-statement ::= continue;

while-stmt ::= while (expr) S ;
do-stmt    ::= do S while (expr) ;

for-stmt        ::= for ( [for-init-expr-list] ; [for-test-expr-list] ; [for-update-expr-list] ) S;
for-init-expr-list ::= for-init-expr { , for-init-expr }*
for-init-expr   ::= expr | T id = expr
for-test-expr-list ::= for-test-expr { , for-test-expr }*
for-test-expr   ::= expr
for-update-expr-list ::= for-update-expr { , for-update-expr }*
for-update-expr ::= expr

return-stmt ::= return [ expr ] ;
```

## Arrays

```
array-decl ::= T id [ array-size ]
array-size ::= expr

array-element ::= id [ array-index ]
array-index ::= expr

for-range-stmt ::= for ( T id : arr ) S;
```

## Pointers

```
pointer-decl ::= T* id
pointer-expr ::= address-expr 
               | dereference-expr
               | null-expr
               | new-expr
               | delete-expr
address-expr ::= & variable
               | & array-element
               | & function-id               
dereference-expr ::= * expr
null-expr    ::= NULL | nullptr
new-expr     ::= new T | new T[]
delete-expr  ::= delete expr | delete[] expr
```

## Math Functions

```
math-funcs ::= abs(expr) | ceil(expr) | floor(expr)   
             | pow(expr) | sqrt(expr)  
             | exp(expr) | log(expr)
             | round(expr) | trunc(expr)
```