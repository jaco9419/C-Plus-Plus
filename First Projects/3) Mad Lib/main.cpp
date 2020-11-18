#include <iostream>

using namespace std;

int main()
{
    string color, pluralNoun, celebrity;

    cout << "Enter a color: ";
    getline(cin, color);
    cout << "Enter a plural noun: ";
    getline(cin, pluralNoun);
    cout << "Enter a celebrity's name: ";
    getline(cin, celebrity);

    cout << endl;
    cout << "Roses are " << color << endl;
    cout << pluralNoun << " are blue" << endl;
    cout << "I love " << celebrity << "." << endl;

    int nums[] = {1, 2,3,4,5,6};

    for (int i = 0; i < 6; i++)
    cout << nums[i];

    return 0;
}
