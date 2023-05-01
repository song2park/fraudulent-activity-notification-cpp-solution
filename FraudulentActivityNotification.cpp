#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int getMedianX2(int* arr, int mid1, int mid2) {
    int summ[201] = { 0, };

    summ[0] = arr[0];
    for (int i = 1; i < 201; i++) {
        summ[i] = arr[i] + summ[i - 1];
    }

    int m1, m2;
    for (int i = 0; i < 201; i++) {
        if (mid1 <= summ[i]) {
            m1 = i;
            break;
        }
    }
    for (int i = 0; i < 201; i++) {
        if (mid2 <= summ[i]) {
            m2 = i;
            break;
        }
    }

    float m = (m1 + m2) / 2.0;
    return m * 2;
}

int activityNotifications(vector<int> expenditure, int d) {
    int counts[201] = { 0, };

    for (int i = 0; i < d; i++) {
        counts[expenditure[i]]++;
    }

    int results = 0;
    int mid1, mid2;
    if (d % 2 == 1) mid1 = mid2 = d / 2 + 1;
    else { mid1 = d / 2; mid2 = d / 2 + 1; }

    for (int i = d; i < expenditure.size(); i++) {
        int med = getMedianX2(counts, mid1, mid2);

        if (expenditure[i] >= med) {
            results++;
        }

        counts[expenditure[i - d]]--;
        counts[expenditure[i]]++;
    }

    return results;
}

int main()
{
    ofstream fout("output.txt");
    ifstream fin("input.txt");
    string first_multiple_input_temp;
    getline(fin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(fin, expenditure_temp_temp);
    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
