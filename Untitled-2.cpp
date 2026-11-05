#include <iostream>
using namespace std;

int countVowels(const char* p)
{
    int cnt = 0;
    while (*p != '\0')
    {
        char c = *p;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            cnt++;
        }
        p++;
    }
    return cnt;
}

int main()
{
    char str[1000];
    cin.getline(str, 1000);
    int res = countVowels(str);
    cout << "Number of vowels: " << res << endl;
    return 0;
}