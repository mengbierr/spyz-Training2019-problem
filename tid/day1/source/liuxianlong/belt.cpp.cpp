#include<bits/stdc++.h>
using namespace std;
double t1,t2,ans1x,ans1y,ans2x,ans2y,num1x,num1y,num2x,num2y,maxx,maax,q,p,r,ax,ay,bx,by,cx,cy,dx,dy;
double dist(double aa,double bb,double cc,double dd){return sqrt(((cc-aa)*(cc-aa))+((bb-dd)*(bb-dd)));}
double sanfen2(double befx,double befy,double l2x,double l2y,double r2x,double r2y)
{
	num1x=(l2x+r2x)/3;num1y=(l2y+r2y)/3;num2x=((l2x+r2x)*2)/3;num2y=((l2y+r2y)*2)/3;
	maxx=(p*dist(befx,befy,ax,ay))+(q*dist(num1x,num1y,dx,dy))+(r*dist(befx,befy,num1x,num1y));
	maax=(p*dist(befx,befy,ax,ay))+(q*dist(num2x,num2y,dx,dy))+(r*dist(befx,befy,num2x,num2y));
	if(maxx<=maax) sanfen2(befx,befy,l2x,l2y,num2x,num2y);
	else sanfen2(befx,befy,num1x,num1y,r2x,r2y); 
	if(abs(maax-maxx)<0.01)return min(maxx,maax);
}
double sanfen1(double l1x,double l1y,double r1x,double r1y)
{
	ans1x=(l1x+r1x)/3;ans1y=(l1y+r1y)/3;ans2x=((l1x+r1x)*2)/3;ans2y=((l1y+r1y)*2)/3;
	t1=sanfen2(ans1x,ans1y,cx,cy,dx,dy);t2=sanfen2(ans2x,ans2y,cx,cy,dx,dy);
	if(t1>=t2)sanfen1(ans1x,ans1y,r1x,r1y);
	else sanfen1(l1x,l1y,ans2x,ans2y); 
	if(abs(t1-t2)<0.01)return min(t1,t2);
}
void spcz12(){printf("%.2lf",sanfen1(ax,ay,bx,by));}
int main()
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
	spcz12();
}
