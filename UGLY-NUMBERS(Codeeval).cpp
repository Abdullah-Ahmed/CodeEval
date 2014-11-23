#include <bits/stdc++.h>

using namespace std;
vector<string>tri;
void checkNumberofWays(string tmp , int index){
   if(index==tmp.size()){
    tri.push_back(tmp);
    return;
   }
string t1;
   for(int i = 0 ; i < tmp.size();){
    if(i == index){
    t1.push_back('+');
        t1.push_back(tmp[i]);
        i++;
    }
        else{
        t1.push_back(tmp[i]);
        i++;
        }
   }
    string t2;
   for(int i = 0 ; i < tmp.size();){
    if(i == index){
    t2.push_back('-');
        t2.push_back(tmp[i]);
        i++;
    }
        else{
        t2.push_back(tmp[i]);
        i++;
        }
   }
   checkNumberofWays(t1,index+2);
    checkNumberofWays(t2,index+2);
    checkNumberofWays(tmp,index+1);
}

int process(string s){
long long sum = 0 , t = 0 ;
bool f = true;
for(int i = 0 ; i < s.size();){
    while(s[i]!='+'&&s[i]!='-'&&i < s.size())
           t*=10,t+=s[i]-'0',i++;
    
        if(f) sum += t,t = 0; 
    else  sum -= t , t = 0 ; 

        if(s[i] == '+') f = true;
    if(s[i] == '-') f = false;
i++;
    
}
return sum;
}

int main(int argc, char* argv[]){
    ifstream file(argv[1]);
string ss;
tri.clear();
while(getline(file, ss)){
checkNumberofWays(ss,1);

long long c = 0 ,x;
for(int i = 0 ; i < tri.size() ; i++){
  x = process(tri[i]) ;
if(!(x%2) || !(x%3)|| !(x%5)|| !(x%7)) c++;
}
cout<<c<<endl;
tri.clear();
}
    return 0;
}
