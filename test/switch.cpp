void foo();
void bar();
void baz();
int main()
{
    int a;
    switch(a)
    {
        case 0:
        foo();
        break;
        case 1:
        bar();
        break;
        default:
        baz();
    }
    return 0;
}
