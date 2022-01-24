void bar();
void baz();
template<typename T>
T foo(const T &arg) {
    if(arg) bar();
    else baz();
    return arg;
}
int main()
{
    int a = 5;
    a = foo(a);
    double b = 0.5;
    b = foo(b);
    return 0;
}
