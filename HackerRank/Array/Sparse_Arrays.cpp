#pragma GCC optimize("O2")

#include <bits/stdc++.h>

using namespace std;


int main()
{
	int strings_count;
	ifstream fin("input");
	fin >> strings_count;
	fin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(fin, strings_item);
        strings[i] = strings_item;
    }

    // ofstream fout(getenv("output"));

    int queries_count;
    fin >> queries_count;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    string queries;
    int count = 0;
    for (int i = 0; i < queries_count; ++i) {
        getline(fin, queries);
        for(int j = 0; j < strings.size();)
        {
            if (queries.compare(strings[j]) == 0)
            {
                ++count;
                strings[j] = strings[strings.size() - 1];
                strings.pop_back();
            }
            else {
                ++j;
            }
        }
        cout << count << endl;
        count = 0;
        queries.clear();
    }
    fin.close();

    // fout.close();

    return 0;
}
