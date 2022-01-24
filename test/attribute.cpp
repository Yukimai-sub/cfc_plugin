void foobar();
void barbaz();
int some_integer();
void __attribute__((cfcheck(false))) foo(int t) {
    if(t == 5)
        foobar();
    else barbaz();
}

void bar(int t)
{
    if(t == 1)
        foobar();
    else barbaz();
}

void __attribute__((cfcheck(true))) baz(int t)
{
    if(t == 2)
        foobar();
    else barbaz();
}

void __attribute__((cfcheck)) foobarbaz(int t)
{
    if(t == 3)
        foobar();
    else barbaz();
}

int main()
{
    int t = some_integer();
    foo(t);
    bar(t);
    baz(t);
    foobarbaz(t);
    return 0;
}
