#include<iostream.h>
#include<string.h>

int main()
{
    int t,i,j,k,a[3];
    char s[6000];
    while(1)
    {
                    cin>>s;
                    if(strcmp(s,"0")==0)
                                        break;
                    if(strlen(s)==1)
                                    a[0]=1;
                    else if(strlen(s)==2)
                    {
                             a[0]=0;
                             a[1]=1;
                             if( s[1]=='0' )
                             {
                                      a[0]=a[1];
                             }
                             else
                             {
                                         a[0]=a[1];
                                         if( (s[0]-48)*10+s[1]-48<=26 )
                                             a[0]++;
                             }
                         
                    }
                    else
                    {
                        a[0]=0;
                        a[1]=a[2]=1;
                        for(j=1;j<strlen(s);j++)
                        {
                                                if(s[j]=='0')
                                                {
                                                                 a[0]=a[2];
                                                }
                                                else
                                                {
                                                    a[0]=a[0]+a[1];
                                                    if( (s[j-1]-48)*10 + s[j]-48 <=26 )
                                                    {
                                                        if(s[j-1]!='0')
                                                                       a[0]=a[0]+a[2];
                                                    }
                                                }
                                                //cout<<a[2]<<" "<<a[1]<<" "<<a[0]<<"\n";
                                                a[2]=a[1];
                                                a[1]=a[0];
                                                if(j<strlen(s)-1)
                                                              a[0]=0;
                        }
                    }    
                    cout<<a[0]<<"\n";
    }
}
                                            


