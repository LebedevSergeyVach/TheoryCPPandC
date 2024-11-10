#include "postfix.h"

void infix_to_postfix(char *infix, char *postfix) {
    Stack s;
    s.top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ') continue;

        if (is_operator(infix[i])) {
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(infix[i])) {
                postfix[k++] = (char)pop(&s);
            }
            push(&s, infix[i]);
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (s.top != -1 && s.items[s.top] != '(') {
                postfix[k++] = (char)pop(&s);
            }
            pop(&s);
        } else if (strncmp(&infix[i], "sin", 3) == 0) {
            i += 2;
            push(&s, 's');
        } else if (strncmp(&infix[i], "cos", 3) == 0) {
            i += 2;
            push(&s, 'c');
        } else if (strncmp(&infix[i], "tan", 3) == 0) {
            i += 2;
            push(&s, 't');
        } else if (strncmp(&infix[i], "ctg", 3) == 0) {
            i += 2;
            push(&s, 'g');
        } else if (strncmp(&infix[i], "sqrt", 4) == 0) {
            i += 3;
            push(&s, 'k');
        } else if (strncmp(&infix[i], "ln", 2) == 0) {
            i += 1;
            push(&s, 'l');
        } else {
            postfix[k++] = infix[i];
        }
    }
    while (s.top != -1) {
        postfix[k++] = (char)pop(&s);
    }
    postfix[k] = '\0';
}

double evaluate_postfix(char *postfix, double x) {
    Stack s;
    s.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] == ' ') continue;

        if (is_operator(postfix[i])) {
            double val1 = pop(&s);
            double val2 = pop(&s);
            switch (postfix[i]) {
                case '+':
                    push(&s, val2 + val1);
                    break;
                case '-':
                    push(&s, val2 - val1);
                    break;
                case '*':
                    push(&s, val2 * val1);
                    break;
                case '/':
                    push(&s, val2 / val1);
                    break;
            }
        } else if (postfix[i] == 'x') {
            push(&s, x);
        } else if (postfix[i] == 's') {
            double val = pop(&s);
            push(&s, sin(val));
        } else if (postfix[i] == 'c') {
            double val = pop(&s);
            push(&s, cos(val));
        } else if (postfix[i] == 't') {
            double val = pop(&s);
            push(&s, tan(val));
        } else if (postfix[i] == 'g') {
            double val = pop(&s);
            push(&s, 1 / tan(val));
        } else if (postfix[i] == 'k') {
            double val = pop(&s);
            push(&s, sqrt(val));
        } else if (postfix[i] == 'l') {
            double val = pop(&s);
            push(&s, log(val));
        } else {
            char num_str[MAX_SIZE];
            int j = 0;
            while ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.') {
                num_str[j++] = postfix[i++];
            }
            num_str[j] = '\0';
            push(&s, atof(num_str));
            i--;
        }
    }

    return pop(&s);
}
