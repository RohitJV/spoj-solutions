#include<iostream>
using namespace std;
 
int main()
{
        int n,i,j,count,x,y,z;
        while(1)
        {
                count=0;
                //cout<<"\n\n";
                cin>>n;
                if(n==-1)
                        break;
                z=y=4*n-1;
 
                for(i=0;i<y;i++)
                {
                        //cout<<i;
                        if(i<n)
                        {
                                //cout<<i;
                                for(j=0;j<2*n-2*i-1;j++)
                                        cout<<" ";
                                for(j=0;j<(4*i)+1;j++)
                                {
                                        //cout<<"j"<<j;
                                        if(j%4==0)
                                                cout<<"_";
                                        else if(j%4==1)
                                                cout<<"/";
                                        else if(j%4==2)
                                                cout<<" ";
                                        else
                                                cout<<"\\";
                                }
                        }
                        else if(i<3*n)
                        {
                                for(j=0;j<3*n+n-1;j++)
                                {
                                        if(count%2==0)
                                        {
                                        if(j%4==0)
                                                cout<<"/";
                                        else if(j%4==1)
                                                cout<<" ";
                                        else if(j%4==2)
                                                cout<<"\\";
                                        else
                                                cout<<"_";
                                        }
                                        else
                                        {
                                        if(j%4==0)
                                                cout<<"\\";
                                        else if(j%4==1)
                                                cout<<"_";
                                        else if(j%4==2)
                                                cout<<"/";
                                        else
                                                cout<<" ";
                                        }
                                 }
                                 count++;
                        }
                        else
                        {
                                x=i-3*n+1;
                                for(j=0;j<2*x;j++)
                                        cout<<" ";
                        
                                z=z-4;
                                for(j=0;j<z;j++)
                                {
                                        if(j%4==0)
                                                cout<<"\\";
                                        else if(j%4==1)
                                                cout<<"_";
                                        else if(j%4==2)
                                                cout<<"/";
                                        else
                                                cout<<" ";
                                }
                        }
                        cout<<"\n";
                }
                cout<<"***\n";
        }
}
