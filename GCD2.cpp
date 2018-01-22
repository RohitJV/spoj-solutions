    #include<iostream>
    #include<cstdio>
    using namespace std;
    long int gcd(long int a,long int b)
    {
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
    main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            long int a,b,res;
            cin>>a>>b;
            if(a==0)
                res=b;
            else
                res=gcd(a,b);
            cout<<res<<"\n";
        }
    }
