#include <iostream>
using namespace std;

bool Guess(int num);
int main()
{
    int num = rand() % 100 + 1;
    cout << "Guess a number between 1 and 100" << endl;
    while (!Guess(num))
        ;
    return 0;
}

bool Guess(int num)
{
    int guess;
    cin >> guess;
    if (guess == num)
    {
        cout << "You are right!" << endl;
        return true;
    }
    else if (guess > num)
    {
        cout << "Too big!" << endl;
        return false;
    }
    else
    {
        cout << "Too small!" << endl;
        return false;
    }
}