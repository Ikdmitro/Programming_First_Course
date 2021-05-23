typedef struct
{
    double* A;
    int l;
    int top;
} StackA;

int Push(StackA* s, double v);
double Pop(StackA* s);
double Peek(StackA const* s);
int IsEmptyStack(StackA const* s);
void Clear(StackA* s);
void InitStack(StackA* s, int l);
void PrintStack(StackA const* s);
void Destruct(StackA* s);
void InitStack(StackA* s, int l) // инициализация стека из lэлементов
{
    if (s->A = (double*)malloc(sizeof(double) * l))
    {
        s->l = l;
    }
    else s->l = -1;
    s->top = -1;
}
void PrintStack(StackA const* s) // выводэлементовстека

{
    int i;
    for (i = 0; i <= s->top; i++)
        printf("%-7.3lf ", (s->A)[i]);
}
void Destruct(StackA* s) // уничтожениестека

{
    if (s->A) free(s->A);
    s->l = -1;
    s->top = -1;
}
int Push(StackA* s, double v) // добавлениеэлементавстек

{
    if (s->top >= s->l - 1) return 0;
    s->top++;
    s->A[s->top] = v;
    return 1;
}

double Pop(StackA* s)// достатьэлемент
{
    if (s->top >= 0)
        return s->A[s->top--];
    else return 1e300;
}

double Peek(StackA const* s)// просмотретьверхнийэлементбезудаления
{
    if (s->top >= 0)
        return s->A[s->top];
    else return 1e300;
}
void Clear(StackA* s) //очисткастека
{
    s->top = -1;
}

int IsEmptyStack(StackA const* s)// проверкастекананаличиеэлементов
{
    if (s->top < 0) return 1;
    else return 0;
}

