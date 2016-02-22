//solution by Wsl_F
#include <bits/stdc++.h>

using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

class Point
{
private:

    dbl x,y,z,v;

    Point(dbl x1, dbl y1, dbl z1, dbl v1) : x(x1), y(y1), z(z1), v(v1) { }

public:
    dbl dist(Point &p2)
    {
        dbl d= 0;
        d+= sqr(x-p2.x);
        d+= sqr(y-p2.y);
        d+= sqr(z-p2.z);
        d+= sqr(v-p2.v);
        d= sqrt(d);
        return d;
    }


    friend ostream& operator<<(ostream& out, Point &p)
    {
        out << p.x << " " << p.y << " " << p.z << " " << p.v << endl;
        return out;
    }

    friend istream& operator>>(istream &input, Point &p)
    {
        input >> p.x >> p.y >> p.z >> p.v;
        return input;
    }

};

const int MaxN= 1000;
dbl claster[MaxN+10];
Point p[MaxN+10];

int main()
{

int n= 0;
    {
        int i= 0;
        while (cin>>p[++i]);
        n= i;
    }

    memset(claster, 0, sizeof(claster));
    claster[1]= 1;

    {
        int j= 1;
        dbl d= 0;
        for (int i= 2; i<=n; i++)
        {
            dbl tmp= p[1].dist(p[i]);
            if (tmp>d) j= i;
        }
        claster[j]= 2;
    }


    return 0;
}
