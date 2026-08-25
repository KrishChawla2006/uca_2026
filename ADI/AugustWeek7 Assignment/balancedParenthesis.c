/*
Question:
Balanced Parenthesis
Check for balanced parentheses in an expression.
Given a string expression, write a program to examine whether the pairs of "{",}","(",")","[","]" are correct in expression in O(N) time.
Constraints 0 < Length(expression) <= 30

Input 1 [()]{}{()()}
Output 1 true

Input 2 [()
Output 2 false
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isBalanced(char expression[]) {

    char stack[30];
    int top = -1;
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else if (ch == ')') {

            if (top == -1 || stack[top] != '(')
              return false;

            top--;
        }
        else if (ch == '}') {

            if (top == -1 || stack[top] != '{')
              return false;

            top--;
        }
        else if (ch == ']') {

            if (top == -1 || stack[top] != '[')
              return false;

            top--;
        }
    }
    return top == -1;
}

int main() {

    char expression[31];
  
    printf("Enter expression: ");
    scanf("%30s", expression);

    if (isBalanced(expression))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
