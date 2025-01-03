#include <bits/stdc++.h>
using namespace std;

void process()
{
    int length; cin >> length;
    vector<int> values(length);
    for (int i = 0; i < length; i++)
        cin >> values[i];

    while (!values.empty() && values.back() == 0)
        values.pop_back();

    reverse(values.begin(), values.end());
    while (!values.empty() && values.back() == 0)
        values.pop_back();
    reverse(values.begin(), values.end());

    if (values.empty())
    {
        cout << 0 << '\n';
        return;
    }

    bool containsZero = false;
    for (const auto val : values)
        containsZero |= val == 0;
    if (containsZero)
        cout << 2 << '\n';
    else
        cout << 1 << '\n';
}

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
        process();

    return 0;
}
