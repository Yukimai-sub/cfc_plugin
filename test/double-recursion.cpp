int some_integer();
int other_integer(int);
int sion(int x);
int recur(int x)
{
    if(x == 0) return 0;
    int y = other_integer(x);
    if(x > 5) return recur(y);
    else return sion(y);
}
int sion(int x)
{
    if(x == 0) return 0;
    int y = other_integer(x);
    if(x < -5) return recur(y);
    else return sion(y);
}
int main()
{
    int t = some_integer();
    recur(t);
    return 0;
}
