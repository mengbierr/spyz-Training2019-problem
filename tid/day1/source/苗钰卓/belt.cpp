#include<cstdio>
#include<cmath>
#include<algorithm>
//#include<ÃçîÚ×¿>
using namespace std;
typedef float F;
struct zb{
	F x,y;
};
zb A,D;
F lab,rab,lcd,rcd,kab,kcd,bab,bcd;
F vab,vcd,v;
bool AA,CC;
void prepare()
{
	F _,__;
	scanf("%f%f%f%f",&A.x,&A.y,&_,&__);
	if(A.x==_){
		lab=(F)min(A.y,__);
		rab=(F)max(A.y,__);
		AA=true;
	}
	else {
		lab=min(A.x,_);
		rab=max(A.x,_);
		kab=(__-A.y)/(_-A.x);
		bab=(A.x*__-_*A.y)/(A.x-_);
	}
	scanf("%f%f%f%f",&_,&__,&D.x,&D.y);
	if(D.x==_){
		CC=true;
		lcd=(F)min(D.y,__);
		rcd=(F)max(D.y,__);
	}
	else {
		lcd=min(D.x,_);
		rcd=max(D.x,_);
		kcd=(D.y-__)/(D.x-_);
		bcd=(D.x*__-_*D.y)/(D.x-_);
	}
	scanf("%f%f%f",&vab,&vcd,&v);
}
F AB(F g){return kab*g+bab;}
F CD(F g){return kcd*g+bcd;}
F len(F _1,F _2,F _3,F _4){
	return sqrt((_1-_3)*(_1-_3)+(_2-_4)*(_2-_4));
}
F js(F r,F t,F o,F u,F s)
{
	return r+len(t,o,u,s)/(F)v+len(u,s,D.x,D.y)/(F)vcd;
}
F three_cd(F x1,F y1)
{
	F mid,midd,k1,k2;
	F G=len(A.x,A.y,x1,y1)/(F)vab,L=lcd,R=rcd;
	if(CC==false){
		while(R-L>=1e-5){
			mid=(R+L)/2;
			midd=(mid+R)/2;
			k1=js(G,x1,y1,mid,CD(mid));
			k2=js(G,x1,y1,midd,CD(midd));
			if(k1>=k2)L=mid;
			if(k2>=k1)R=midd;
		}
		return js(G,x1,y1,L,CD(L));
	}
	else {
		while(R-L>=1e-5){
			mid=(R+L)/2;
			midd=(mid+R)/2;
			k1=js(G,x1,y1,D.x,mid);
			k2=js(G,x1,y1,D.x,midd);
			if(k1>=k2)L=mid;
			if(k2>=k1)R=midd;
		}
		return js(G,x1,y1,D.x,L);
	}
}
void three_ab()
{
	F mid,midd,k1,k2;
	if(AA==false){
		while(rab-lab>=1e-5){
			mid=(rab+lab)/2;
			midd=(mid+rab)/2;
			k1=three_cd(mid,AB(mid));
			k2=three_cd(midd,AB(midd));
			if(k1>=k2)lab=mid;
			if(k2>=k1)rab=midd;
		}
		printf("%.2f",three_cd(lab,AB(lab)));
	}
	else {
		while(rab-lab>=1e-5){
			mid=(rab+lab)/2;
			midd=(rab+mid)/2;
			k1=three_cd(A.x,mid);
			k2=three_cd(A.x,midd);
			if(k1>=k2)lab=mid;
			if(k2>=k1)rab=midd;
		}
		printf("%.2f",three_cd(A.x,lab));
	}
	return;
}
int main(){
	freopen("belt.in","r",stdin); 
	freopen("belt.out","w",stdout); 
	prepare();
	three_ab();
	return 0;
}
