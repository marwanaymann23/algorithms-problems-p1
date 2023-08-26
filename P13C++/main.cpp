#include<iostream>
#include<cstring>

using namespace std;

const int maxn=100000000;

class Node
{
public:
    int x,y;
}node[15];

int num;
int dp[15][15],s[15][15];

void printpath(int i,int j)
    {
        if(i==j) cout<<"A"<<i+1;
        else
            {
                cout<<"(";
                printpath(i, s[i][j]);
                cout<<" x ";
                printpath(s[i][j]+1, j);
                cout<<")";
            }
    }

int main()
    {
        int pos=0;
        while(cin>>num&&num)
            {
                for(int i=0;i<num;i++)
                    cin>>node[i].x>>node[i].y;

                memset(dp,0,sizeof(dp));
                memset(s,0,sizeof(s));
                int cost;
                for(int l=1;l<num;l++)
                    {
                        for(int i=0;i<num-l;i++)
                            {
                                int j=l+i;
                                dp[i][j]=maxn;
                                for(int k=i;k<j;k++)
                                    {
                                        cost=dp[i][k]+dp[k+1][j]+node[i].x*node[k].y*node[j].y;
                                        if(cost<dp[i][j])
                                            {
                                                dp[i][j]=cost;
                                                s[i][j]=k;
                                            }
                                    }
                            }
                    }
                cout<<"Case "<<++pos<<": ";
                printpath(0, num-1);
                cout<<endl;
               //cout<<dp[0][num-1]<<endl;
            }
        return 0;
    }