#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
using namespace std;
int main()
{
    vector<int> vec = {23,2,54,7,3,23, 2, 7, 54, 23};
    auto same = [](vector<int>& obj){
        unordered_set<int> no_repeat;
        for (auto i : obj){
           no_repeat.insert(i);
        }
        vector<int> result;
        result.reserve(no_repeat.size());
        for (auto i : no_repeat){
            result.push_back(i);
        }
        unique_ptr<vector<int>> unicPtr = make_unique<vector<int>>(result);
        return unicPtr;
    };

    cout << "vec" << endl;
    for (auto i : vec){
        cout << i << " ";
    }
    cout << endl;
    vector<int> vec2;
    vec2 = *same(vec);
    cout << "vec2 - no repeat" << endl;
    for (auto i : vec2){
        cout << i << " ";
    }
}