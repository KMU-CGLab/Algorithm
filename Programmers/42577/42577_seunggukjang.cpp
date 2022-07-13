#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <array>
#include <list>
using namespace std;
bool myfunction(string i, string j) { return (i < j); }
bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), myfunction);
    int count = phone_book.size();
    for (int i = 0; i < count - 1; i++)
    {
        if (strncmp(phone_book[i].c_str(), phone_book[i + 1].c_str(), phone_book[i].size()) == 0)
            return false;
    }
    return true;
}