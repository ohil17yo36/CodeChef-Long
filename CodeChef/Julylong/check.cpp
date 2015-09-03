// if(lazysub[node]!=0)
        // {
        //  tree[node]=((lazysub[node]%mod)*((end-start+1)%mod))%mod;
        //  lazymul[node]=1;
        //  lazyrest[node]=0;
        //  if(start!=end)
        //  {
        //      lazysub[2*node]+=lazysub[node];
        //      lazysub[2*node + 1]+=lazysub[node];
        //      if(lazysub[2*node]>=mod)
        //          lazysub[2*node]=lazysub[2*node]%mod;
        //      if(lazysub[2*node + 1]>=mod)
        //          lazysub[2*node + 1]=lazysub[2*node + 1]%mod;
        //      lazysub[node]=0;
        //  }

        //  else
        //  {
        //      lazysub[node]=0;
        //      return tree[node];
        //  }
            
        //  return query(2*node,start,(start+end)/2) + query(2*node + 1,((start+end)/2)+1,end);
        // }
        // else
        // {
// if(lazysub[node]!=0)
                // {
                //      tree[node]=((lazysub[node])*((end-start+1)))%mod;
                //      lazymul[node]=1;
                //      lazyrest[node]=0;
                //      if(start!=end)
                //      {
                //              lazysub[2*node]+=lazysub[node];
                //              lazysub[2*node + 1]+=lazysub[node];
                //              if(lazysub[2*node]>=mod)
                //                      lazysub[2*node]=(lazysub[2*node]%mod);
                //              if(lazysub[2*node + 1]>=mod)
                //                      lazysub[2*node + 1]=(lazysub[2*node + 1]%mod);
                //      }
                //      lazysub[node]=0;
                //      if(start!=end)
                //      {
                //              update(2*node,start,(start+end)/2);
                //              update(2*node + 1,((start+end)/2)+1,end);
                //      }
                //      return ;
                // }
                // else
                // {
        // // if(type==3)
                // // {
                // //   // printf("Helo %lld %lld\n",start,end );
                // //   lazysub[node]+=v;
                // //   if(lazysub[node]>=mod)
                // //           lazysub[node]=lazysub[node]%mod;
                // //   tree[node]=((lazysub[node])*((end-start+1)))%mod;
                // //   lazyrest[node]=0;
                // //   lazymul[node]=1;
                // //   if(start!=end)
                // //   {
                // //           lazysub[2*node]+=lazysub[node];
                // //           lazysub[2*node + 1]+=lazysub[node];
                // //           if(lazysub[2*node]>=mod)
                // //                   lazysub[2*node]=(lazysub[2*node]%mod);
                // //           if(lazysub[2*node + 1]>=mod)
                // //                   lazysub[2*node + 1]=(lazysub[2*node + 1]%mod);
                // //   }
                // //   lazysub[node]=0;
                // //   if(start!=end)
                // //   {
                // //           update(2*node,start,(start+end)/2);
                // //           update(2*node + 1,((start+end)/2)+1,end);
                // //   }
                // //   return ;
                // // }
                // else 