#include <functional>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    size_t hash_res;
    hash<string> hash_str;
    string a = "abcd";
    hash_res = hash_str(a);
    cout << hash_res << " " << (hash_res << 8);

    return 0;
}
