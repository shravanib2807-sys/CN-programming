#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ip;

    cout << "Enter IP Address: ";
    cin >> ip;

    int p1 = ip.find('.');
    int p2 = ip.find('.', p1 + 1);
    int p3 = ip.find('.', p2 + 1);

    if (p1 == -1 || p2 == -1 || p3 == -1)
    {
        cout << "Invalid IP Address";
        return 0;
    }

   
    int first = stoi(ip.substr(0, p1));
    int second = stoi(ip.substr(p1 + 1, p2 - p1 - 1));
    int third = stoi(ip.substr(p2 + 1, p3 - p2 - 1));
    int fourth = stoi(ip.substr(p3 + 1));

    
    if (first < 0 || first > 255 ||
        second < 0 || second > 255 ||
        third < 0 || third > 255 ||
        fourth < 0 || fourth > 255)
    {
        cout << "Invalid IP Address";
        return 0;
    }

   
    if (first == 0)
    {
        cout << "Invalid IP Address";
        return 0;
    }

    cout << "Valid IP Address" << endl;

    if (first >= 1 && first <= 126)
    {
        cout << "Class: A" << endl;
        cout << "Network ID: " << first << ".0.0.0" << endl;
        cout << "Host ID: 0." << second << "." << third << "." << fourth << endl;
        cout << "Default Mask: 255.0.0.0";
    }
    else if (first >= 128 && first <= 191)
    {
        cout << "Class: B" << endl;
        cout << "Network ID: " << first << "." << second << ".0.0" << endl;
        cout << "Host ID: 0.0." << third << "." << fourth << endl;
        cout << "Default Mask: 255.255.0.0";
    }
    else if (first >= 192 && first <= 223)
    {
        cout << "Class: C" << endl;
        cout << "Network ID: " << first << "." << second << "." << third << ".0" << endl;
        cout << "Host ID: 0.0.0." << fourth << endl;
        cout << "Default Mask: 255.255.255.0";
    }
    else if (first >= 224 && first <= 239)
    {
        cout << "Class: D";
    }
    else
    {
        cout << "Class: E";
    }

    return 0;
}
