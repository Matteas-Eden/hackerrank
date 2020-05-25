#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
// Essentially just count the number of times the level moves from a negative value to 0
int countingValleys(int n, string s) {

    // Denote increments above/below sea level as an integer
    int level = 0;
    int numValleys = 0;

    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'U':
                if (level == -1) numValleys++;
                level++;
                break;
            case 'D':
                level--;
                break;
            default:
                break;
        }
    }

    return numValleys;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
