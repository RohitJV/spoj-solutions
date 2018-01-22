#include<iostream.h>

int main()
{
    int n,s,t1=0,t2,c1=0,c2=0,sum1=0,sum2=0,i,min,sec,x=0;
    char a[6],o[6];
    cin>>n;
    for(i=0;i<n;i++)
    {
                    cin>>s>>o;
                    t2 =  ((o[0]-48)*10+(o[1]-48))*60 + (o[3]-48)*10+o[4]-48;
                    if(s==1)
                            c1++;
                    else    
                            c2++;
                    if(x==1)
                            sum1=sum1+t2-t1;
                    if(x==2)
                            sum2=sum2+t2-t1;
                    if(c1>c2)
                             x=1;
                    else if(c2>c1)
                                  x=2;
                    else
                        x=0;
                    t1=t2;
    }
    if(x==1)
            sum1=sum1+48*60-t1;
    if(x==2)
            sum2=sum2+48*60-t1;
    min=sum1/60;
    sec=sum1%60;
    a[2]=':';
    if(min<10)
    {
              a[0]='0';
              a[1]=min+48;
    }
    else
    {
              a[0]=min/10+48;
              a[1]=min%10+48;
    }
    if(sec<10)
    {
              a[3]='0';
              a[4]=sec+48;
    }
    else
    {
              a[3]=sec/10+48;
              a[4]=sec%10+48;
    }
    a[5]='\0';
    cout<<a<<"\n";
    min=sum2/60;
    sec=sum2%60;
    a[2]=':';
    if(min<10)
    {
              a[0]='0';
              a[1]=min+48;
    }
    else
    {
              a[0]=min/10+48;
              a[1]=min%10+48;
    }
    if(sec<10)
    {
              a[3]='0';
              a[4]=sec+48;
    }
    else
    {
              a[3]=sec/10+48;
              a[4]=sec%10+48;
    }
    a[5]='\0';
    cout<<a<<"\n";  
}
                    
                    
                    
                    
