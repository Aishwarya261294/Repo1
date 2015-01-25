double eval(char expr[])
{
    int i;
    int c;
    double op1;
    double op2;
    double value;

    for(i = 0; (c = expr[i]) != '\n'; i++) {
            if(isdigit(c)) {
                    push((double)(c - '0'));
            } else {
                op1 = pop();
                op2 = pop();
                value = oper(c, op1, op2);
                push(value);
            }
    }
    return pop();
}

double eval(char expr[])
{
    int i;
    int c;
    int len;
    double op1;
    double op2;
    double value;

    len = strlen(expr);

    for(i = len - 1; i < 0; i--) {
            c = expr[i];
            if(isdigit(c)) {
                push((double)(c - '0'));
            } else {
                op1 = pop();
                op2 = pop();
                value = oper(c, op2, op1);
                push(value);
            }
    }
    return pop();
}

int main()
{
    int i = 0;
    char expr[];

    while ((expr[i++] = getchar()) != '\n');
    expr[i--] = '\0';

    cout << expr;
    eval(expr);
    cout << expr;
    return 0;
}

struct queue {
    int front;
    int
