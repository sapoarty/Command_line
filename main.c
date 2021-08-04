#include <stdio.h>

int is_alph_symb(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}
void CommandLine(char * str) {
  int var_len;
  int value_len;
  int next_var_len;
  char *temp_str;

  while (1)
  {
    // looking for '=' sym
    while (*str != '=')
    {
        if (*str == '\0') break;
        str++;
    }
    if (*str == '\0') break;

    // go to symbol before '='
    str--;

    //checking variable len
    temp_str = str;
    var_len = 0;
    value_len = 0;
    while (is_alph_symb(*temp_str))
    {
      var_len++;
      temp_str--;
    }

    // skip '='
    str += 2;
    if (*str == '\0') break;

    // looking for the next '=' and count value len
    while (*str != '=')
    {
        value_len++;
        str++;
        if (*str == '\0') break;
    }
    if (*str == '\0') break;

    // skip '='
    str--;

    //checking next variable len
    next_var_len = 0;
    while (is_alph_symb(*str))
    {
      next_var_len++;
      str--;
    }

    //decrese value len by next variable len and space
    value_len -= next_var_len + 1;

    printf("%d=%d ", var_len, value_len);
  }
  printf("%d=%d\n", var_len, value_len);
}

int main(void) {

  // keep this function call here
  CommandLine("letters=A B Z T numbers=1 2 26 20 combine=true");
    printf("%s", "letters=A B Z T numbers=1 2 26 20 combine=true");
    return 0;

}