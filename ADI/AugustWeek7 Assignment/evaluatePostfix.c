/*
Question:
Evaluation of Postfix expressions
The Postfix notation is used to represent algebraic expressions. The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis are not required in postfix.

For example: 3 1 * + 9 - is a postfix expression where paranthesis are not required to change the order of evaluation of expressions. The order of evaluation for expressions with operator is governed by the position of the operator in the expression.

Here, the order of evaluation is: *, +, -

(3 * 1) + 2) - 9 is the equivalent infix expression and the value of the expression is: -4

Constraints: 0 < Length of expression < 50 Operands are numeric Operators are: "+" for addition, "-" for subtraction, "*" for multiplication, "/" for division and

Every token in the expression is separated by a space.

Sample Input 2 3 1 * + 9 -

Sample Output -4
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char expression[100];
    int stack[50];
    int top = -1;

    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    char *token = strtok(expression, " \n");

    while (token != NULL) {
      
        if (strlen(token) == 1 &&
            (token[0] == '+' ||
             token[0] == '-' ||
             token[0] == '*' ||
             token[0] == '/')) {

            int b = stack[top--];
            int a = stack[top--];

            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            stack[++top] = result;
        }
        else {
            stack[++top] = atoi(token);
        }

        token = strtok(NULL, " \n");
    }

    printf("Result = %d\n", stack[top]);

    return 0;
}
