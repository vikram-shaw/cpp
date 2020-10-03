/*

     .c(cx,cy)
     ^ '. 
     |   '.
     |     '.>b(bx,by)
     | 
     |
     .a(ax,ay)
    * slope of ac > slope of cb for clock wise turn
	*  (cy-ay)   (by-cy)
	=> ------- > --------
	*  (cx-ax)   (by-cx)
	*  
	*  cy*bx - cy*cx - ay*bx + ay*cx > cx*by - cx*cy - ax*by + ax*cy
	* ax(by-cy) + bx(cy-ay) + cx(ay-by) > 0

*/
#include<bits/stdc++.h>
using namespace std;

class point{
	public:
	int x,y;
	bool operator ==(point p){
		return x == p.x && y == p.y;
	}
	bool operator <(point p){
		if(x == p.x)
			return y < p.y;
		return x < p.x;
	}
};

bool cw(point a, point b, point c)
{
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0;
}

bool ccw(point a, point b, point c)
{
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
}

bool collinear(point a, point b, point c)
{
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) == 0;
}

void convex_hull(vector<point>& p)
{
	int n = p.size();
	if(n <= 2)
		return;
	sort(p.begin(),p.end());
	vector<point> up, down;
	point p1 = p[0], p2 = p[n-1];
	up.push_back(p1);
	down.push_back(p1);
	for(int i=1;i<n;i++)
	{
		if(i==n-1 || !ccw(p1,p[i],p2))
		{
			//p[i] is in the upper half
			while(up.size()>=2 && ccw(up[up.size()-2],up[up.size()-1],p[i]))
				up.pop_back();
			up.push_back(p[i]);
		}
		if(i== n-1 || !cw(p1,p[i],p2))
		{
			//p[i] is in the lower half
			while(down.size()>=2 && cw(down[down.size()-2],down[down.size()-1],p[i]))
				down.pop_back();
			down.push_back(p[i]);
		}
	}
	p.clear();
	for(int i=0;i<(int)up.size();i++)
		p.push_back(up[i]);
	for(int i=0;i<(int)down.size();i++)
		p.push_back(down[i]);
	sort(p.begin(),p.end());
	p.resize(unique(p.begin(),p.end())-p.begin());
}

int main()
{
	int n;
	cin>>n;
	vector<point> p(n);
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	convex_hull(p);
	for(int i=0;i<(int)p.size();i++)
		cout<<p[i].x<<' '<<p[i].y<<'\n';
}
