int some_integer();
int other_integer(int);
int recursion(int x)
{
    if(x == 0) return some_integer();
    else return recursion(other_integer(x));
}
int main()
{
    int t = some_integer();
    recursion(t);
    return 0;
}
