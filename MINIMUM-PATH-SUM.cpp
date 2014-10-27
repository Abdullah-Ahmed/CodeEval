#include <bits/stdc++.h>
#define loop(i,s,e) for(int i =s ; i <e ; i++)
#define inf 1<<30
using namespace std;

static int dx [] = {-1,0,0,1};
static int dy[] =  {0,-1,1,0};

typedef  pair<int,pair<int,int> >  doublepair ;

priority_queue< doublepair ,vector< doublepair >,  greater< doublepair >  > q;

int n ;
int a[1000][1000];
int d[1000][1000];

bool check(int x , int y){ return (x >= 0&& y >=0 && x < n && y < n ) ;}
void shortpath()
{
    d[0][0] = a[0][0] ;

   q.push(make_pair(d[0][0],make_pair(0,0)));

   while(!q.empty())
   {
       doublepair parentvalue ;
       parentvalue = q.top(); q.pop();
       pair<int,int> parentindex = parentvalue.second;
       int x , y , valuee;
       valuee = parentvalue.first; x = parentindex.first, y = parentindex.second;
       if(parentvalue.first == d[x][y])
       {
           int xs,ys;
           loop(i,0,4)
           {
               xs = x + dx[i];
               ys = y + dy[i];
            if(check(xs,ys) && d[xs][ys] > d[x][y]+a[xs][ys]){
                d[xs][ys] = d[x][y] + a[xs][ys];
                q.push(make_pair(d[xs][ys],make_pair(xs,ys)));
            }
           }
       }

   }
}

int main(int argc, char* argv[])
{
//    ifstream file("file.txt");
    ifstream file(argv[1]);
    string str ,t;
    char ss[2000];
 while (getline(file,str))
   {
       n = atoi(str.c_str()) ;
loop(i,0,n) {
    int j = 0 ;
getline(file,str)  ;
 strcpy(ss,str.c_str()) ;
char *p = strtok(ss, ",");
while (p) {
        str =  p ;
       a[i][j] = atoi(str.c_str()); //cout<<a[i][j];
         d[i][j] = inf;
         j++;
    p = strtok(NULL, ",");
}
}
shortpath();
cout<<d[n-1][n-1]<<endl;
}
    return 0;
}
