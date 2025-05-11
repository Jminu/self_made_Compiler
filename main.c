#include <stdio.h>
#include <string.h>

enum state { p, q, r };

int cur_state = p;
int table[3][2] = {{q, p}, {r, p}, {r, r}};

int get_input_symbol(char ch)
{
    if (ch == '0')
        return 0;
    if (ch == '1')
        return 1;

    return -1; //input error
}

void table_driven(char* input_str)
{
    int str_len = strlen(input_str);
    int input_symbol;

    for (int i = 0; i < str_len; i++)
    {
        input_symbol = get_input_symbol(input_str[i]);

        if (input_symbol == -1)
        {
            printf("input error!\n");
            return;
        }

        cur_state = table[cur_state][input_symbol];
    }

    if (cur_state == r)
        printf("yes!\n");
    else
        printf("no!\n");
}

int main()
{
    char str[100];
    scanf("%s", str);

    table_driven(str);

    return 0;
}
