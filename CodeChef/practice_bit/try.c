    #include<stdio.h>
    #include<string.h>
     
    int main()
    {
    char s[500];
    int t,flag,i;
    int hash[26];
    scanf("%d",&t);
    int c=getchar();
    while(t--)
    {
    memset(hash,0,sizeof(hash));
    flag=0;
    gets(s);
    int n=strlen(s);
    for(i=0;i<n;i++)
    {
    if(s[i]>=65 && s[i]<=90)
    hash[s[i]-65]++;
    else if(s[i]>=97 && s[i]<=122)
    hash[s[i]-97]++;
    }
    for(i=0;i<26;i++)
    {
    if(hash[i]==0){
    printf("%c\n",'a'+i);
    flag=1;
    break;
    }
    }
    if(flag==0)
    printf("~\n");
    }
    return 0;
    } 