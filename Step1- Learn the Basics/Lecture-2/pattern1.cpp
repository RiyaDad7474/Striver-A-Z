#include <iostream>
using namespace std;
void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // for (int j = n; j >=i; j--)    This is Riya's approach
        // {
        //     cout <<"* ";
        // }
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print8(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 1; j <= 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print11(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}
void print12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // space
        for (int j = i; j <= space; j++)
        {
            cout << " ";
        }

        // numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space = space - 2;
    }
}
void print13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }
}
void print14(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (char value = 'A'; value <= 'A' + i; value++)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}
void print15(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (char value = 'A'; value <= 'A' + (n - i - 1); value++)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}
void print16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char value = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}
void print17(int n)
{
    for (int i = 0; i < n; i++)
    { // Loop from 0 to n-1
        // Print leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // Char
        char value = 'A';
        int breakpoint = (2 * i + 1) / 2;

        // Print characters
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << value << " ";

            // Increment until the breakpoint, then decrement
            if (j < breakpoint)
            {
                value++;
            }
            else
            {
                value--;
            }
        }

        cout << endl; // Move to the next line after each row
    }
}
void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + (n - 1);
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
}
void print19(int n)
{
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < S; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        S = S + 2;
        cout << endl;
    }
    S = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < S; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        S = S - 2;
        cout << endl;
    }
}
void print20(int n)
{
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout<<endl;
        if(i<n)
        spaces = spaces - 2;
        else
        spaces = spaces + 2;
    }
}
void print21(int n){
    for(int i=0;i<n;i++){
        for(int j= 0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1 ){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}
void print22(int n){
    for(int i = 0;i<2*n-1;i++){
        for(int j = 0;j<2*n-1;j++){
            int top = i;
            int left = j;
            int right = (2*n - 2) - j;
            int down = (2*n - 2) - i;
            cout<<(n - min(min(top,down),min(left,right)));

        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        // print2(n);
        print22(n);
    }
    // return 0;
}