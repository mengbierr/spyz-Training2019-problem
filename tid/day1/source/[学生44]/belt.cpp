#include<bits/stdc++.h> 
#define dd double
#define eps 0.001
#define maxn 1000005
#define INF 99999999
using namespace std;
dd ax,ay, bx,by, cx,cy, dx,dy; 
dd lp,lq;         
dd p,q,r;      
dd nowx,nowy;
dd now;
dd ans=INF;
dd dis(dd a,dd b,dd c,dd d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void Tri_div(){
	  dd le=0.000,ri=lq;
	  dd mid1,mid2,mid1x,mid1y,mid2x,mid2y;
	  //cout<<"*";
	  while(le+0.001<ri){
	      mid1=le+((ri-le)/3);
	      mid2=ri-((ri-le)/3);
			mid1x=cx+((mid1/lq)*(dx-cx));
			mid1y=cy+((mid1/lq)*(dy-cy));
			mid2x=cx+((mid2/lq)*(dx-cx));
			mid2y=cy+((mid2/lq)*(dy-cy));
		  dd f1=(now/p)+(dis(nowx,nowy,mid1x,mid1y)/r)+((lq-mid1)/q);
		  dd f2=(now/p)+(dis(nowx,nowy,mid2x,mid2y)/r)+((lq-mid2)/q);
			//cout<<f1<<" "<<f2<<endl;
	      ans=min(ans,f2);
	      ans=min(ans,f1);
	      if(f1>=f2){le=mid1;} else {ri=mid2;}
	  }
	return;
}
int main(){
	  freopen("belt.in","r",stdin);
	  freopen("belt.out","w",stdout);
	  cin>>ax>>ay >>bx>>by >>cx>>cy >>dx>>dy;
	  cin>>p>>q>>r;
	  lp=dis(ax,ay,bx,by);
	  lq=dis(cx,cy,dx,dy);
	  
	  if(ax==dx&&ay==dy){
	  	cout<<"0.00";
	  	return 0;
	  }
	  
	  for(dd v=0.00;v<=lp;v+=0.001){
			nowx=ax+(v/lp)*(bx-ax);
			nowy=ay+(v/lp)*(by-ay);
			now=v;
			//cout<<nowx<<"  "<<nowy<<endl;
			Tri_div();
	  }
	  
      printf("%.2f\n",ans);
	  //cout<<endl<<"over"<<endl;
      return 0;
}
