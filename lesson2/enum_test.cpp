#include <bits/stdc++.h>

using namespace std;

int main()
{
    enum class Gender
    {
        Male,
        Female
    };

    Gender boy = Gender::Male;

    switch (boy)
    {
    case Gender::Male:
        cout << "That's a male." << endl;
        break;
    case Gender::Female:
        cout << "That's a female." << endl;
        break;
    default:
        cout << "Beyond Binary." << endl;
    }

    return 0;
}