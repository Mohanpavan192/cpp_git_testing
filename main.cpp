#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
            getline(cin,s);
        if (!(cin >> n)) return 0;
    while(n--)
        // consume the leftover newline after reading n
        getline(cin, s);
        //cout<<n<<"\n";
        for (int i = 0; i < n; ++i) {
            if (!getline(cin, s)) break;
            cout << s.size() << "\n";
            if (s.size() > 10) {
                cout << "hi" << s.front() << (s.size() - 2) << s.back() << "\n";
            } else {
                cout << "hlo" << s << "\n";
            }
        }

        return 0;
    }