#include <stdio.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct
{
  int top;
  char data[MAX];
} Stack;

Stack stack;
char infix[MAX], postfix[MAX];
int isEmpty()
{
  if (stack.top == -1)
  {
    return TRUE;
  }
  return FALSE;
}
int isFull()
{
  if (stack.top == (MAX - 1))
  {
    return TRUE;
  }
  return FALSE;
}
void init()
{
  stack.top = -1;
}
void push(char chr)
{
  if (isFull())
  {
    printf("Stack Overflow!\n");
  }
  else
  {
    stack.top += 1;
    stack.data[stack.top] = chr;
  }
}
void pop()
{
  if (isEmpty())
  {
    printf("Stack underflow!\n");
  }
  else
  {
    stack.top -= 1;
  }
}
int OpLevel(char op)
{
  if (op == '^')
  {
    return 3;
  }
  else if (op == '*' || op == '/')
  {
    return 2;
  }
  else if (op == '+' || op == '-')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void in_to_post(char infix[])
{
  int i = 0, j = 0;
  char temp;
  while (infix[i] != '\0')
  {
    char karakter = infix[i];
    if (karakter == '^' || karakter == '*' || karakter == '/' || karakter == '+' || karakter == '-')
    {
      while (!isEmpty() && (OpLevel(karakter) <= OpLevel(stack.data[stack.top])))
      {
        temp = stack.data[stack.top];
        postfix[j] = temp;
        j++;
        pop();
      }
      push(karakter);
    }
    else if (karakter == '(')
    {
      push(karakter);
    }
    else if (karakter == ')')
    {
      while (stack.data[stack.top] != '(')
      {
        temp = stack.data[stack.top];
        postfix[j] = temp;
        j++;
        pop();
      }
      pop();
    }
    else
    {
      postfix[j] = karakter;
      j++;
    }
    i++;
  }
  while (!isEmpty())
  {
    temp = stack.data[stack.top];
    postfix[j] = temp;
    j++;
    pop();
  }
  printf("%s", postfix);
}
int main()
{
  init();
  scanf("%s", infix);
  in_to_post(infix);
  return 0;
}