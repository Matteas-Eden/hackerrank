#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
// 'abbaba'
// 1, 4, 6 (n = 6)
// 'abbabaabb'
// 1, 4, 6, 7 (n = 9)
// 'abbaba abbaba'
// 1, 4, 6, 7, 10, 12 (n = 12) 
// if (n - length = index * x)


// Old approach
// Create array of indexes of 'a' in s
// Calculate occurences per index
// Sum
// Return

// New approach
// Find multiples of length that n is (n / length)
// Find the remainder (n % length)
// if remainder >= index for indices, then count++

// Edge cases
// n < length
// n = length
long repeatedString(string s, long n) {

    vector<int> indices;
    int found = 0;
    long count = 0;
    long len = s.length();

    found = s.find('a', found);

    while (found != string::npos) {

        indices.push_back(found+1);
        found = s.find('a', found+1);

    } 

    count = (n / len) * indices.size();

    for (vector<int>::iterator it = indices.begin(); it != indices.end(); ++it) {

        if (n % len >= *it) {
            count++;
        }

    }

    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
