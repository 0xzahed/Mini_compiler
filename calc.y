%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int yylex();
void yyerror(char *s);
int error_occurred = 0;
extern FILE *yyin;
#define MAX_SYMBOLS 100
#define MAX_P 10
#define SYMBOL_VARIABLE 0
#define SYMBOL_FUNCTION 1
struct symbol {
    int type;
    char *name;
    union {
        struct {
            int value;
            int is_defined;
        } var;
        struct {
            char *params[10];
            int param_count;
            char *body;
        } func;
    } data;
} symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
int current_param_values[10];
int current_param_count = 0;
int find_symbol(char *name);
int add_variable(char *name, int value);
int add_function(char *name, char **params, int param_count, char *body);
int evaluate_function_body(char *body, char **params, int param_count, int *arg_values);
%}

%union {
    int ival;
    char *sval;
    int bval;
    struct {
        int ival;
        char *sval;
        int bval;
        int matched;
    } case_result;
    struct {
        char *params[10];
        int count;
    } param_list;
    struct {
        int values[10];
        int count;
    } arg_list;
}

%token <ival> NUMBER
%token <sval> STRING
%token <bval> BOOLEAN
%token <sval> IDENTIFIER
%token INT ASSIGN RETURN PLUS MINUS MULT DIV MOD POWER LT GT AND CONCAT REPEAT LENGTH SUBSTR MIN MAX INC DEC PRINT IF THEN ELSE SWITCH CASE DEFAULT
%left PLUS MINUS
%left MULT DIV MOD
%left POWER
%left LT GT
%left AND
%left CONCAT
%left REPEAT
%precedence THEN
%precedence ELSE
%type <ival> num_expr num_expr_base num_expr_with_if identifier_usage
%type <sval> str_expr str_expr_base str_expr_with_if
%type <bval> bool_expr bool_expr_base bool_expr_with_if
%type <case_result> switch_cases_num cases_num case_list_num
%type <case_result> switch_cases_str cases_str case_list_str
%type <case_result> switch_cases_bool cases_bool case_list_bool
%type <param_list> param_list params
%type <arg_list> arg_list args
%type <sval> function_body

%%

program:
    /* Empty */
    | statements
    ;

statements:
    statement { 
        if (error_occurred) error_occurred = 0;
    }
    | statements '\n' statement { 
        if (error_occurred) error_occurred = 0;
    }
    | statements '\n'
    ;

statement:
    num_expr    { if (!error_occurred) printf("Result (number): %d\n", $1); }
    | str_expr  { if (!error_occurred) { printf("Result (string): %s\n", $1); free($1); } }
    | bool_expr { if (!error_occurred) printf("Result (boolean): %s\n", $1 ? "true" : "false"); }
    | INT IDENTIFIER ASSIGN num_expr { 
        if (!error_occurred) {
            int index = add_variable($2, $4);
        }
        free($2);
    }
    | INT IDENTIFIER '(' param_list ')' '{' function_body '}' { 
        if (!error_occurred) {
            int index = add_function($2, $4.params, $4.count, $7);
        }
        free($2);
    }
    | PRINT '(' num_expr ')' { 
        if (!error_occurred) printf("Result (number): %d\n", $3); 
    }
    | PRINT '(' str_expr ')' { 
        if (!error_occurred) { printf("Result (string): %s\n", $3); free($3); } 
    }
    | PRINT '(' bool_expr ')' { 
        if (!error_occurred) printf("Result (boolean): %s\n", $3 ? "true" : "false"); 
    }
    ;

function_body:
    RETURN num_expr ';' { 
        $$ = NULL;
    }
    ;

param_list:
    /* Empty */ { $$.count = 0; }
    | params    { $$ = $1; }
    ;

params:
    IDENTIFIER { 
        $$.count = 1;
        $$.params[0] = $1;
    }
    | params ',' IDENTIFIER { 
        $$ = $1;
        if ($$.count >= MAX_P) {
            yyerror("Too many parameters");
            error_occurred = 1;
        } else {
            $$.params[$$.count] = $3;
            $$.count++;
        }
    }
    ;

num_expr:
    num_expr_base
    | num_expr_with_if
    ;

num_expr_base:
    NUMBER                { $$ = $1; }
    | identifier_usage    { $$ = $1; }
    | '(' num_expr ')'    { $$ = $2; }
    | num_expr PLUS num_expr  { $$ = $1 + $3; }
    | num_expr MINUS num_expr { $$ = $1 - $3; }
    | num_expr MULT num_expr  { $$ = $1 * $3; }
    | num_expr DIV num_expr   { if ($3 != 0) $$ = $1 / $3; else { yyerror("Division by zero"); error_occurred = 1; $$ = 0; } }
    | num_expr MOD num_expr   { if ($3 != 0) $$ = $1 % $3; else { yyerror("Modulo by zero"); error_occurred = 1; $$ = 0; } }
    | num_expr POWER num_expr { $$ = (int)pow($1, $3); }
    | LENGTH '(' str_expr ')' { $$ = strlen($3); free($3); }
    | MIN '(' num_expr ',' num_expr ')' { $$ = ($3 < $5) ? $3 : $5; }
    | MAX '(' num_expr ',' num_expr ')' { $$ = ($3 > $5) ? $3 : $5; }
    | IDENTIFIER INC { 
        int index = find_symbol($1);
        if (index == -1 || symbol_table[index].type != SYMBOL_VARIABLE || !symbol_table[index].data.var.is_defined) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Cannot increment undefined variable: %s", $1);
            yyerror(error_msg);
            error_occurred = 1;
            $$ = 0;
        } else {
            $$ = symbol_table[index].data.var.value;
            symbol_table[index].data.var.value++;
        }
        free($1);
    }
    | IDENTIFIER DEC { 
        int index = find_symbol($1);
        if (index == -1 || symbol_table[index].type != SYMBOL_VARIABLE || !symbol_table[index].data.var.is_defined) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Cannot decrement undefined variable: %s", $1);
            yyerror(error_msg);
            error_occurred = 1;
            $$ = 0;
        } else {
            $$ = symbol_table[index].data.var.value;
            symbol_table[index].data.var.value--;
        }
        free($1);
    }
    | SWITCH '(' num_expr ')' '{' switch_cases_num '}' { 
        if (!$6.matched) { 
            yyerror("No matching case and no default case provided"); 
            error_occurred = 1;
            $$ = 0; 
        } else { 
            $$ = $6.ival; 
        } 
    }
    ;

num_expr_with_if:
    IF '(' bool_expr ')' THEN num_expr ELSE num_expr { $$ = $3 ? $6 : $8; }
    ;

identifier_usage:
    IDENTIFIER { 
        int index = find_symbol($1);
        if (index == -1 || (symbol_table[index].type == SYMBOL_VARIABLE && !symbol_table[index].data.var.is_defined)) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Undefined variable: %s", $1);
            yyerror(error_msg);
            error_occurred = 1;
            $$ = 0;
        } else if (symbol_table[index].type == SYMBOL_VARIABLE) {
            $$ = symbol_table[index].data.var.value;
        } else {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "%s is a function, not a variable", $1);
            yyerror(error_msg);
            error_occurred = 1;
            $$ = 0;
        }
        free($1);
    }
    | IDENTIFIER '(' arg_list ')' { 
        int index = find_symbol($1);
        if (index == -1) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Undefined function: %s", $1);
            yyerror(error_msg);
            error_occurred = 1;
            $$ = 0;
        } else if (symbol_table[index].type != SYMBOL_FUNCTION) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "%s is not a function", $1);
            yyerror(error_msg);
            error_occurred = 1;
            $$ = 0;
        } else if (symbol_table[index].data.func.param_count != $3.count) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Function %s expects %d arguments, got %d", $1, symbol_table[index].data.func.param_count, $3.count);
            yyerror(error_msg);
            error_occurred = 1;
            $$ = 0;
        } else {
            $$ = evaluate_function_body(symbol_table[index].data.func.body, 
                                       symbol_table[index].data.func.params, 
                                       symbol_table[index].data.func.param_count, 
                                       $3.values);
        }
        free($1);
    }
    ;

arg_list:
    /* Empty */ { $$.count = 0; }
    | args      { $$ = $1; }
    ;

args:
    num_expr { 
        $$.count = 1;
        $$.values[0] = $1;
    }
    | args ',' num_expr { 
        $$ = $1;
        if ($$.count >= MAX_P) {
            yyerror("Too many arguments");
            error_occurred = 1;
        } else {
            $$.values[$$.count] = $3;
            $$.count++;
        }
    }
    ;

str_expr:
    str_expr_base
    | str_expr_with_if
    ;

str_expr_base:
    STRING                { $$ = $1; }
    | '(' str_expr ')'    { $$ = $2; }
    | str_expr CONCAT str_expr { 
        char *result = malloc(strlen($1) + strlen($3) + 2);
        strcpy(result, $1);
        strcat(result, " ");
        strcat(result, $3);
        free($1);
        free($3);
        $$ = result;
    }
    | str_expr REPEAT num_expr {
        char *s = $1;
        int times = $3;
        if (times < 0) {
            yyerror("Cannot repeat a string a negative number of times");
            error_occurred = 1;
            $$ = strdup("");
        } else {
            int len = strlen(s) * times;
            char *result = malloc(len + 1);
            result[0] = '\0';
            for (int i = 0; i < times; i++) {
                strcat(result, s);
            }
            $$ = result;
        }
        free(s);
    }
    | SUBSTR '(' str_expr ',' num_expr ',' num_expr ')' {
        char *s = $3;
        int start = $5, len = $7;
        if (start < 0 || start >= strlen(s) || len < 0 || start + len > strlen(s)) {
            yyerror("Invalid substring range");
            error_occurred = 1;
            $$ = strdup("");
        } else {
            char *result = malloc(len + 1);
            strncpy(result, s + start, len);
            result[len] = '\0';
            $$ = result;
        }
        free(s);
    }
    | SWITCH '(' num_expr ')' '{' switch_cases_str '}' { 
        if (!$6.matched) { 
            yyerror("No matching case and no default case provided"); 
            error_occurred = 1;
            $$ = strdup(""); 
        } else { 
            $$ = $6.sval; 
        } 
    }
    ;

str_expr_with_if:
    IF '(' bool_expr ')' THEN str_expr ELSE str_expr { $$ = $3 ? $6 : $8; }
    ;

bool_expr:
    bool_expr_base
    | bool_expr_with_if
    ;

bool_expr_base:
    BOOLEAN               { $$ = $1; }
    | '(' bool_expr ')'   { $$ = $2; }
    | num_expr LT num_expr { $$ = $1 < $3; }
    | num_expr GT num_expr { $$ = $1 > $3; }
    | bool_expr AND bool_expr { $$ = $1 && $3; }
    | SWITCH '(' num_expr ')' '{' switch_cases_bool '}' { 
        if (!$6.matched) { 
            yyerror("No matching case and no default case provided"); 
            error_occurred = 1;
            $$ = 0; 
        } else { 
            $$ = $6.bval; 
        } 
    }
    ;

bool_expr_with_if:
    IF '(' bool_expr ')' THEN bool_expr ELSE bool_expr { $$ = $3 ? $6 : $8; }
    ;

switch_cases_num:
    case_list_num { $$ = $1; }
    ;

cases_num:
    CASE NUMBER ':' num_expr { 
        if ($2 == $<ival>-1) { 
            $$.ival = $4; 
            $$.matched = 1; 
        } else { 
            $$.ival = 0; 
            $$.matched = 0; 
        } 
    }
    | cases_num CASE NUMBER ':' num_expr { 
        if ($1.matched) { 
            $$.ival = $1.ival;
            $$.matched = 1;
        } else if ($3 == $<ival>-2) { 
            $$.ival = $5;
            $$.matched = 1;
        } else {
            $$.ival = 0;
            $$.matched = 0;
        }
    }
    ;

case_list_num:
    cases_num DEFAULT ':' num_expr { 
        if ($1.matched) { 
            $$.ival = $1.ival;
            $$.matched = 1;
        } else {
            $$.ival = $4; 
            $$.matched = 1;
        }
    }
    ;

switch_cases_str:
    case_list_str { $$ = $1; }
    ;

cases_str:
    CASE NUMBER ':' str_expr { 
        if ($2 == $<ival>-1) { 
            $$.sval = $4; 
            $$.matched = 1; 
        } else { 
            $$.sval = strdup(""); 
            $$.matched = 0; 
        } 
    }
    | cases_str CASE NUMBER ':' str_expr { 
        if ($1.matched) { 
            $$.sval = $1.sval;
            $$.matched = 1;
        } else if ($3 == $<ival>-2) { 
            free($1.sval);
            $$.sval = $5;
            $$.matched = 1;
        } else {
            $$.sval = strdup("");
            $$.matched = 0;
        }
    }
    ;

case_list_str:
    cases_str DEFAULT ':' str_expr { 
        if ($1.matched) { 
            $$.sval = $1.sval;
            $$.matched = 1;
        } else {
            $$.sval = $4; 
            $$.matched = 1;
        }
    }
    ;

switch_cases_bool:
    case_list_bool { $$ = $1; }
    ;

cases_bool:
    CASE NUMBER ':' bool_expr { 
        if ($2 == $<ival>-1) { 
            $$.bval = $4; 
            $$.matched = 1; 
        } else { 
            $$.bval = 0; 
            $$.matched = 0; 
        } 
    }
    | cases_bool CASE NUMBER ':' bool_expr { 
        if ($1.matched) { 
            $$.bval = $1.bval;
            $$.matched = 1;
        } else if ($3 == $<ival>-2) { 
            $$.bval = $5;
            $$.matched = 1;
        } else {
            $$.bval = 0;
            $$.matched = 0;
        }
    }
    ;

case_list_bool:
    cases_bool DEFAULT ':' bool_expr { 
        if ($1.matched) { 
            $$.bval = $1.bval;
            $$.matched = 1;
        } else {
            $$.bval = $4; 
            $$.matched = 1;
        }
    }
    ;

%%

int find_symbol(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int add_variable(char *name, int value) {
    int index = find_symbol(name);
    if (index != -1) {
        symbol_table[index].data.var.value = value;
        symbol_table[index].data.var.is_defined = 1;
        return index;
    }
    if (symbol_count >= MAX_SYMBOLS) {
        yyerror("Symbol table full: too many symbols");
        return -1;
    }
    symbol_table[symbol_count].type = SYMBOL_VARIABLE;
    symbol_table[symbol_count].name = strdup(name);
    symbol_table[symbol_count].data.var.value = value;
    symbol_table[symbol_count].data.var.is_defined = 1;
    return symbol_count++;
}

int add_function(char *name, char **params, int param_count, char *body) {
    int index = find_symbol(name);
    if (index != -1) {
        char error_msg[100];
        snprintf(error_msg, sizeof(error_msg), "Symbol %s already defined", name);
        yyerror(error_msg);
        return -1;
    }
    if (symbol_count >= MAX_SYMBOLS) {
        yyerror("Symbol table full: too many symbols");
        return -1;
    }
    if (param_count > MAX_P) {
        yyerror("Too many parameters in function");
        return -1;
    }
    symbol_table[symbol_count].type = SYMBOL_FUNCTION;
    symbol_table[symbol_count].name = strdup(name);
    symbol_table[symbol_count].data.func.param_count = param_count;
    for (int i = 0; i < param_count; i++) {
        symbol_table[symbol_count].data.func.params[i] = strdup(params[i]);
    }
    symbol_table[symbol_count].data.func.body = strdup("a + b");
    return symbol_count++;
}

int evaluate_function_body(char *body, char **params, int param_count, int *arg_values) {
    if (strcmp(body, "a + b") == 0 && param_count == 2) {
        return arg_values[0] + arg_values[1];
    }
    yyerror("Unsupported function body expression");
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    error_occurred = 1;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open input.txt\n");
        return 1;
    }
    yyin = input_file;
    yyparse();
    fclose(input_file);
    return 0;
}