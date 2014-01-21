#include <stdio.h>
#include <stdlib.h>

void pt_BR_hello();
void en_hello();
void es_hello();

enum languages {pt_BR = 0, en = 1, es = 2};   
typedef enum languages Lang;
typedef void (*HELLO)();

HELLO selector(Lang opt);

int main ()
{
    Lang n = 0;
    void (*hello)();

    do
    {
        printf ("Escolha a sua língua:\n");
        printf ("[0] Português;\n"); 
        printf ("[1] Inglês;\n");  
        printf ("[2] Espanhol.\n");
            scanf ("%d", &n);
        if (n < 0 || n > 2)
            fprintf (stderr, "Opção inválida.\n");
        else
            break; 
    
    } while (1);

    hello = selector(n);
    hello();
    
    return 0;
}


HELLO selector(Lang opt)
{
    void (*hello)();
    switch(opt){
        case pt_BR: 
            hello = &pt_BR_hello;
            break;
        case en: 
            hello = &en_hello; 
            break;
        case es: 
            hello = &es_hello;
            break;    
    } 
    return hello;   
}

void pt_BR_hello ()
{ 
    printf ("Olá mundo!\n"); 
}

void en_hello ()
{
    printf ("Hello world!\n"); 
}

void es_hello ()
{
    printf ("¡Hola mundo!\n"); 
}
