/*  
Dado la siguiente función:
void strcat (char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0') {
    i++;
    }
    while ((s[i++] = t[j++]) != '\0') { }
    }
Reescríbala usando apuntadores. ¿Qué ventajas se tienen?

Implemente, usando Lenguaje C, las siguientes funciones:
-Que retorne verdadero (1) si el string s1 está en el string s2, y falso
(0) si no lo está
int my_nsubstr(const char *s1, const char *s2)
-Invertir un string, por ejemplo, convierte a “abc” en “cba”,
trabaja sobre el mismo espacio apuntado por s.
void my_strrev(char *s)
*/

#include <stdio.h>
#include <string.h>

int my_nsubstr(const char *s1, const char *s2)
{
    int i, j;
    for(i = 0; s2[i] != '\0'; i++)
    {
        for(j = 0; s1[j] != '\0'; j++)
        {
            if(s2[i] == s1[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

void my_strrev(char *s)
{
    int i, j;
    char aux;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}

int main()
{
    void cadap (char *s, char *t);
    char s[100], t[100];
    printf("Ingrese frase 1: ");
    fgets(s, 100, stdin);
    printf("Ingrese frase 2: ");
    fgets(t, 100, stdin);
    strcat(s, t);
    printf("%s", s);
    printf(my_nsubstr(s, t) ? "Verdadero(1)" : "Falso(0)");
    printf("\n");
    printf ("Frase invertida: ");
    my_strrev(s);
    printf("%s", s);

    return 0;
    /*
    La ventaja de usar apuntadores es que se ahorra memoria, 
    ya que no se crean variables innecesarias, 
    además de que se ahorra tiempo de ejecución.
    */
}