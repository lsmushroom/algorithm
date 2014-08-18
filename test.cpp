#include <iostream>
#include <cstring>

using namespace std;

bool Match(const string pattern, const string str){
    int len = str.size(); //TODO: judge edge condition
    for(int i = 0; i < len; ++i){
        int j = i, k = 0;
        while(true){
            if (k == pattern.size()) return true;
            if (j >= len) return false;
            if(pattern[k] == '*'){
                if(k == pattern.size()-1) return true;
                else{
                    do{
                        j++;
                    }while(j < len && str[j] != pattern[k+1]);
                    if(j < len) { k+=2; j++;}
                }
            }else if(pattern[k] == '?'){
                j++; k++;
            }else{
                if(pattern[k] == str[j]){
                    k++; j++;
                }else{
                    k = 0; break;
                }
            }
        }
    }        
}


int main(int argc ,char** argv ){
//    cout<<Match("*ac*bd*XXX???s", "xacvbdf***XXX123s");
    cout<<Match(argv[1], argv[2]);
}
