#include<iostream>
#include<iomanip>
 
using namespace std;
int main()
{
    int t,c[6],p[6];
    float final,att,sub,sumc=0,gpa=0,num[3];
    char a[10];
    cin>>t;
    for(int z=0;z<t;z++)
    {
            int res=1;
            gpa=0;
            cin>>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5];
            sumc=c[0]+c[1]+c[2]+c[3]+c[4]+c[5];
            
            for(int i=0;i<6;i++)
            {
                    sub=0;
                    for(int j=0;j<3;j++)
                    {
                            cin>>a;
                            num[j]=0;
                            if(a[0]<90)
                            {
                                       int r=0;
                                       float pro=1;
                                       for(int k=0;a[k]!='\0';k++)
                                       {
                                               if(a[k]=='.')
                                               {
                                                            r=1;
                                                            continue;
                                               }
                                       if(r==0)
                                               num[j]=num[j]*10 +(a[k]-48);
                                               else
                                               {
                                                   pro=pro*10;
                                                   num[j]=num[j] + (a[k]-48)/pro;
                                               }
                                       }
                            }
                            else
                                num[j]=0;
                    }
                    
                    for(int j=0;j<2;j++)
                    {
                            for(int k=j+1;k<3;k++)
                            {
                                    if(num[j]<num[k])
                                    {
                                                     float t;
                                                     t=num[j];
                                                     num[j]=num[k];
                                                     num[k]=t;
                                    }
                            }
                    }
                    
                    //cout<<"\ninternals : "<<num[0]<<"  "<<num[1]<<"\n";
                    
                    
                    sub=sub+(num[0]+num[1])*45/40;
                    
                    //cout<<"\n"<<sub<<"\n";
                    cin>>final;
                    //cout<<"\n"<<final/2<<"\n";
                    sub=sub+final/2;
                    cin>>att;                    
                    
                    if(att<51)
                      sub=sub+5;
                    else if(att<61)
                      sub=sub+4;
                    else if(att<71)
                      sub=sub+3;        
                    else if(att<81)
                      sub=sub+2;
                    else
                      sub=sub+1;
                      
                    //cout<<"\n"<<sub<<"\n";  
                    
                    if(sub>=91)
                       p[i]=10;
                    else if(sub>=81)
                       p[i]=9;
                    else if(sub>=71)
                       p[i]=8;
                    else if(sub>=61)
                       p[i]=7;
                    else if(sub>50)
                       p[i]=6;
                    else if(sub==50)
                       p[i]=5;
                    else
                       p[i]=0;
                       
                    if(p[i]==0)
                       res=0;
                       
                    //cout<<"\n\npoints:"<<p[i];
            }  
            
            for(int i=0;i<6;i++)
            {
                    gpa=gpa+(c[i]*p[i]);
            }
            gpa=gpa/sumc;
           
            if(res==0)
                      cout<<"FAILED, ";
            else
                      cout<<"PASSED, ";
            cout<<fixed<<setprecision(2)<<gpa<<"\n"; 
           
    }
}
