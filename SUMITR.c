n,t,i,j,x,c[100][100]={0},s;
main(){scanf("%d",&t);while(t--){scanf("%d%d",&n,&x);s=c[1][1]=x;for(i=2;i<=n;i++)for(j=1;j<=i;j++){scanf("%d",&x);s=(c[i][j]=(c[i-1][j-1]>c[i-1][j]?c[i-1][j-1]:c[i-1][j])+x)>s?c[i][j]:s;}printf("%d\n",s);}return(0);}
