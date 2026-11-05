#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string name;
    double chinese;
    double math;
    double english;
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        Student s;
        cin >> s.name >> s.chinese >> s.math >> s.english;
        double avg = (s.chinese + s.math + s.english) / 3.0;

        cout << left
             << setw(8) << s.name
             << fixed << setprecision(2)
             << setw(8) << s.chinese
             << setw(8) << s.math
             << setw(8) << s.english
             << setw(8) << avg;

        if (avg >= 90)
        {
            cout << " Excellent";
        }
        cout << endl;
    }
    return 0;
}