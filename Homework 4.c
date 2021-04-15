#include <stdio.h>
#include <stdlib.h> 

#define OpMax 100 
#define Numero '0' 

int getop(char []);
void push(double);
double pop(void);

main()
{
    printf("Introduca su operacion\nNumero (Espacio) Numero (Espacio) Signo\nEjemplo:35 87 *\n");
	
	int type;
    double op2;
    char s[OpMax];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case Numero:
            push(atof(s));
            break;
            case '+':
            push(pop() + pop());
            break;
            case '*':
            push(pop() * pop());
            break;
            case '-':
            op2 = pop();
            push(pop() - op2);
            break; 
            case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: cero divisor\n");
            break;
            case '\n':
            printf("\t%.8g\n", pop());
            break;
            default:
            printf("error: comando desconocido %s\n", s);
            break;
        }
    }
}

#define ValMax 100

int d = 0;
double valor[ValMax];

void push(double f)
{
    if(d < ValMax)
        valor[d++]=f;
    else
        printf("error: pila llena %g\n",f);
}

double pop(void)
{
    if(d>0)
        return valor[--d];
    else
    {
        printf("error: pila vacia \n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;
    
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return Numero;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: demaciados caracteres\n");
    else
    
        buf[bufp++] = c;
}
