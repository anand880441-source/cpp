// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// class StringUtils
// {
// public:
//     static bool isPalindrome(string s)
//     {
//         transform(s.begin(), s.end(), s.begin(), ::tolower);

//         string reversedS = s;
//         reverse(reversedS.begin(), reversedS.end());

//         return s == reversedS;
//     }
// };

// int main()
// {
//     StringUtils s1;
//     cout << s1.isPalindrome("radar") << endl;
//     cout << s1.isPalindrome("hello") << endl;
//     return 0;
// }


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Utils{
   public: 
   
   static bool isPalindrome(string word){
        int j = word.size()-1;
        int i = 0;
        while(i<j){
            if(tolower(word[i]) == tolower(word[j])) {
                i++;
                j--;
                continue;
            }
            return false;
        }
        return true;
   }
};

int main(){
    Utils u;
    cout<< u.isPalindrome("radar")<< endl;
    return 0;
}