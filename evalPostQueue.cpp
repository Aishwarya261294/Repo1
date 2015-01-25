#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>

#define MAX 1000

using namespace std;

struct queue {
    char a[MAX];
    int frontt = -1;
    int rear = -1;
    };

struct queue s;

void push(char);
char pop();
char eval(char, int, int);

int main() {
    char c, z[MAX];
    int n, i, j;
    char op1, op2;

    i = 0;
    while ((c = getchar()) != '\n') {
        if (c != ' ')  z[i++] = c;
        }
    i--;
    while (i >= 0) {
        push(z[i--]);
        }

    n = strlen(s.a);

    while(s.frontt != s.rear) {
       c = pop();
            if (!isdigit(c) && isdigit(s.a[s.frontt]) &&  isdigit(s.a[s.frontt + 1])) {
                op1 = pop();
                op2 = pop();
                push(eval(c, op1 - '0', op2 - '0'));
                } else {
                    push(c);
                }
            }

        cout << pop();
        }
void push(char c) {
    if(s.rear == MAX - 1) {
        cout << "Overflow\n";
        return;
        }
    if (s.frontt == -1) s.frontt = 0;
    s.a[++s.rear] = c;
    }

char pop() {
    if(s.frontt == -1) {
        cout << "underflow\n";
        return NULL;
        }
    return s.a[s.frontt++];
    }

char eval(char c, int op1, int op2) {
    int n;
    switch(c) {
        case '+': n = op2 + op1;
            break;
        case '-': n = op2 - op1;
            break;
        case '*': n = op2 * op1;
            break;
        case '/': n = op2 / op1;
            break;
        case '^': n = pow(op2, op1);
            break;
            }
        return (char)(n + '0');
    }