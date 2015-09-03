    #include <bits/stdc++.h>
    using namespace std;
    int main(int argc, char const *argv[])
    {
    long long int t;
    cin>>t;
    while(t--)
    {
    long long int n;
    cin>>n;
    long long int H[n];
    long long int K[n];
    long long int num;
    long long int ans[1004]={0};
    long long int maximum=0;
    for (int i = 0; i <n; ++i)
    {
    cin>>H[i];
    H[i]*=2;
    maximum=max(maximum,H[i]);
    }
     
    //sort(H.begin(), H.end());
    for (int i = 0; i < n; ++i)
    {
    cin>>K[i];
    ans[K[i]]=1;
    }
    for (int i = 1; i <= maximum; i++)
    {
    if(ans[i]==0)
    {
    //cout<<"Hello "<<i<<endl;
    long long int minimum=1000005;
    for (int j = 1; j <=(i/2) ; ++j)
    {
    minimum=min(minimum,(ans[j]+ans[i-j]));
    // cout<<minimum<<endl;
    }
    ans[i]=minimum;
    //cout<<ans[i]<<endl;
    }
    }
    long long int sum=0;
    for (int i = 0; i < n; ++i)
    {
    sum+=ans[H[i]];
    }   
    cout<<sum<<endl;
    }
    return 0;
    } 