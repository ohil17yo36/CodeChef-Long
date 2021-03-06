    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    char str[200035];
    int lcp[200035];
    #ifndef ONLINE_JUDGE
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
    #endif
    inline int read_int(){register char c=getchar_unlocked();while(c<'0' || c>'9')c=getchar_unlocked();int ret=0;while(c>='0'&&c<='9'){ret=(ret<<3)+(ret<<1)+c-48;c=getchar_unlocked();}return ret;}
    inline void fastwrite(long long int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)putchar_unlocked(snum[i--]);putchar_unlocked('\n');}
    int n;
    struct state
    {
    int index,first,second;
    }prefix[200015];
    int sorted[19][200014];
    int lefts[200014],rights[200014];
    ll ans[200014];
    vector <int> pos[200014];
    struct lists
    {
    int idx,pos;
    }arr[200004];
    bool comp(const state &lhs,const state &rhs)
    {
    return lhs.first==rhs.first?(lhs.second<rhs.second):(lhs.first<rhs.first);
    }
    bool comps(const lists &lhs, const lists &rhs)
    {
    return lhs.pos<rhs.pos;
    }
    int main()
    {
    int t;
    cin>>t;
    while(t--)
    {
    		scanf("%s",str);
    		n=strlen(str);
    		//now let us construct suffix array
    		for(int i=0;i<n;i++)
    				sorted[0][i]=str[i]-'a';
    		int total=0,pro=1;
    	for(int gap=1,cur=1; gap<n ; gap*=2,cur++)
    	{
    	//for all the suffixes
   			pro=gap;
    		for(int i=0 ; i<n ; i++)
    		{
    			prefix[i].index=i;
    			prefix[i].first=sorted[cur-1][i];
    			prefix[i].second=(i+gap<n)?sorted[cur-1][i+gap]:-1;
    		}
    	//done
    		sort(prefix,prefix+n,comp);
    		total=cur;
    		for(int i=0; i<n ; i++)
    			sorted[cur][prefix[i].index]=(i>0 && prefix[i].first==prefix[i-1].first && prefix[i].second==prefix[i-1].second)?sorted[cur][prefix[i-1].index]:i;
    	}
    	//working fine :)
    	//now time to build the lcp array
    	lcp[0]=0;
   	 	//find lcp between i and (i-1)th in sorted
   	 	for(int i=0; i<n; i++)
    	{
    		arr[i].idx=i;
    		arr[i].pos=sorted[total][i];
    		lcp[i]=0;
    	}
    	lcp[n]=0;
    	lcp[n+1]=0;
    	sort(arr,arr+n,comps);
    	int left,right;
    	for(int i=1 ; i<n ; i++)
    	{
    		left=arr[i-1].idx;
   			right=arr[i].idx;
    		// printf("Going to compare %d %d--\n",arr[i].idx,arr[i-1].idx);
    		for(int j=total-1,gap=pro ; j>=0 && left<n && right<n; j--,gap/=2)
    		{
    			if(sorted[j][left]==sorted[j][right])
    			{
    				lcp[i]+=gap;
    				left+=gap;
    				right+=gap;
    			}
    		}
    	}
    	for(int i=0; i<n-1; i++)
    		lcp[i]=lcp[i+1];
    	//now e have to calculate lefts and rights
    	stack <int> arr;
    	for(int i=0 ; i<n-1; i++)
    	{
    		while(arr.empty()==false && lcp[arr.top()]>=lcp[i])
    		arr.pop();
    		if(arr.empty()==true)
    		lefts[i]=-1;
    		else
    		lefts[i]=arr.top();
    		arr.push(i);
    	}
    	while(arr.empty()==false)
    		arr.pop();
    	for(int i=n-2; i>=0 ;i--)
    	{
    		while(arr.empty()==false && lcp[arr.top()]>=lcp[i])
    			arr.pop();
    			if(arr.empty()==true)
    			rights[i]=n-1;
    			else
    			rights[i]=arr.top();
    		arr.push(i);
    	}	
    	for(int i=0 ; i<=n+2 ; i++)
    		pos[i].clear();
    	for(int i=0; i<n-1;i++)
    	{
    		pos[lcp[i]].push_back(i);
    		ans[i]=0;
    	}
   		 ans[n]=0;
    	ans[n-1]=0;
    	for(int i=1; i<n; i++)
    	{
    		int go=pos[i].size();
    		for(int j=0; j<go; )
    		{
   			 	int minimum = i;
    			int k = pos[i][j];
    			if(lefts[k] != -1 && minimum > i - lcp[lefts[k]]) minimum = i - lcp[lefts[k]];
    			if(rights[k] != n-1 && minimum > i - lcp[rights[k]]) minimum = i - lcp[rights[k]];
    			int range = rights[k] - lefts[k];
   				ans[range] += (ll)minimum * (ll)range;
    			while(j < pos[i].size() && pos[i][j] < rights[k]) j++;
    		}
    	}
    		// for(int i=n-1; i>0; i--)
    		// {
    		// 	ans[i]=ans[i]+ans[i+1];
    		// 	//printf("%lld %d %lld\n",ans[i],i,ans[i+1]);
    		// }
    		ans[1]=(ll)(n)*(ll)(n+1);
    		ans[1]/=2;
    		for(int i=0;i<n;i++)
    			printf("frequeny %d:-%lld\n",i,ans[i]);
    		// int q;
    		// q=read_int();
    		// while(q--)
    		// {
    		// 	int x;
    		// 	x=read_int();
    		// 	fastwrite(x>n?0:ans[x]);
   			// }
    }
    return 0;
} 