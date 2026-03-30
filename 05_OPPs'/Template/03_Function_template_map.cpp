#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>



// void add(T1 a, T2 b){
//      cout << a+b << endl;
// }

class Pair{
    
    public:
      
      T1 first;
      T2 second;
      
      Pair(T1 a, T2 b){
          first = a;
          second = b;
      }
      
      void display(){
          cout << "First value is -> " << first << " and Second value is-> " << second << endl;
      }
    
};


// void add3(string a,  char b){
//     cout << a+b<<endl;
// }

// void add2(char a,  char b){
//     cout << a+b<<endl;
// }

// void add1(int a,  float b){
//     cout << a+b<<endl;
// }

// void add(int a,  int b){
//     cout << a+b<<endl;
// }

int main(){
    
    // map<int, string> m1();
    Pair<string, char>p1("SPINO", 'G');
    p1.display();
    
    // add(10, 20);
    // add(10, 56.3);
    // add(23.678, 34.2);
    // add("HII ", '!');
    return 0;
}