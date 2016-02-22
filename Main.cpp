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

public:
    Point(dbl x1, dbl y1, dbl z1, dbl v1) : x(x1), y(y1), z(z1), v(v1) { }

    Point() : x(0), y(0), z(0), v(0) { }

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
const dbl alpha= 0.7;
dbl claster[MaxN+10];
Point p[MaxN+10];
double sumDist= 0;

int getClosestCenter(int curPoint, set<int> &centres)
{
    dbl dist= INFINITY;
    int ans= 0;
    for (int center : centres)
    {
        dbl tmp= p[curPoint].dist( p[center] );
        if (tmp < dist)
        {
            dist= tmp;
            ans= center;
        }
    }

    return ans;
}


dbl getMinDist(int curPoint, set<int> &centres)
{
        return p[curPoint].dist(p [getClosestCenter(curPoint, centres)] );
}


void addCenter(set<int> &centres, int newCenter)
{
    for (int center : centres)
        sumDist+= p[newCenter].dist( p[center] );

    centres.insert(newCenter);

    claster[newCenter]= centres.size();
}


dbl getAverageDist(set<int> &centres)
{
    dbl n= centres.size();
    n= n*(n-1)/2;

    return sumDist / n;
}


int read()
{
    ifstream in("input.txt");

    int i= 0;
    while (in>>p[++i]);

    return i;
}

set<int> getCentres(int n)
{
    memset(claster, 0, sizeof(claster));
    set<int> centres;
    centres.clear();
    centres.insert(1);
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
        centres.insert(j);
        sumDist= d;
    }

    while (1)
    {
        dbl maxDist= 0;
        int j= 0;

        for (int i= 1; i<=n; i++)
            if (claster[i]==0)
        {
            dbl d= getMinDist(i, centres);
            if (d>maxDist)
            {
                maxDist= d;
                j= i;
            }
        }

        if (getAverageDist(centres) * alpha < maxDist)
            addCenter(centres,j);
        else break;

    }

    return centres;
}

void getClasters(int n, set<int> centres)
{
    for (int i= 1; i<=n; i++)
        if (claster[i]==0)
    {
        claster[i]= getClosestCenter(i, centres);
    }
}


int main()
{
    int n= read();

    set<int> centres= getCentres(n);

    cout<<"Number of clasters: "<<centres.size()<<endl;

    return 0;
}
