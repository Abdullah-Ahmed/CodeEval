#include <bits/stdc++.h>

using namespace std;

string add(string n, string m) //big int add
{
   long long carry = 0 ;
   long long cell = 0 ;
   string bigernumber ;
   string smallernumber ;
   string temp[1000];
   string temp2[1000];
   int index = 0 ;
    if(m.size() >= n.size())
        bigernumber = m , smallernumber = n;
    else
              bigernumber = n , smallernumber = m;

    long long totallength = bigernumber.size();


        char ss[100000];
        int j,i,z;
for( j = bigernumber.size()-1 ,i = smallernumber.size() - 1,z = 0 ;i >= 0 && j >= 0 ;j--,i--){
    ss[z] =((((bigernumber[j]-'0') + (smallernumber[i]-'0') ) +carry )%10 )+'0';
   carry = ((((bigernumber[j]-'0') + (smallernumber[i]-'0') ) +carry ) /10 );
   z++;
  }

while(j>=0)
{
    ss[z] =(((bigernumber[j]-'0')    +carry )%10 )+'0';
   carry = (((bigernumber[j]-'0')  +carry ) /10 );
   z++;
   j--;
}
if(carry)
    ss[z++] = carry+'0';

 char tmp[100000];
    for(int tt = 0,ttt = z - 1 ; tt < z ; tt++,ttt--) tmp[tt] = ss[ttt];
   tmp[z] = '\0';
return (string) tmp;
}

int main(int argc, char* argv[])
{
string s[1000+2];
s[0] = "0";
s[1] = "1" ;
    for(int i= 2 ; i <= 1000 ; i++)
        s[i] = add(s[i-2],s[i-1]);

int n ;
ifstream file(argv[1]);
//ifstream file("text.txt");
    string str ;
 while (getline(file,str))
   {
       n = atoi(str.c_str()) ;
   cout<<s[n+1]<<endl;
   }
   return 0;
}
