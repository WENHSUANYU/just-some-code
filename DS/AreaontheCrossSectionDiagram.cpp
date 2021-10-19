/*
* Input 
* backslash | slash | underscore
* E.g., \\///\_/\/\\\\/_/\\///__\\\_\\/_\/_/\
* Output
* area: int
* the number of floods: int
* each of flood areas: int
* E.g., 35
*       5 4 2 1 19 9
*/
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    stack<int> backslash;
    stack<pair<int, int>> backslash_area;
    char ch;
    int sum = 0;
    for(int i = 0; cin >> ch; i++) {
        if (ch == '\\') {
            backslash.push(i);
        } else if (ch == '/' && backslash.size() > 0) {
            int j = backslash.top();
            backslash.pop();
            sum += i - j;
            int area = i - j;
            while (!backslash_area.empty() && backslash_area.top().first > j) {
                area += backslash_area.top().second;
                backslash_area.pop();
            }
            backslash_area.push(make_pair(j,area));
        }
    }
    vector<int> ans;
    while(!backslash_area.empty()) {
        ans.push_back(backslash_area.top().second);
        backslash_area.pop();
    }
    reverse(ans.begin(),ans.end());
    cout << sum << endl;
    cout << ans.size();
    for(int i = 0; i < ans.size(); i++) {
        cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}