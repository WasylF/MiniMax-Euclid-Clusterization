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

int main()
{

    return 0;
}
