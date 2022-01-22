// M items are to be delivered in a circle of size N.
// Find the position where the M-th item will be delivered if we start from a given position K.
// Note that items are distributed at adjacent positions starting from K.

#include <bits/stdc++.h>
using namespace std;

//n->number of person
//m->number of items to be distributed
//k->initial point to start
int calc_last_position(int n,int items,int initial_point)
{
    // starting from initial point we can reach begining after - n-k+1 positions
    int positions_left_before_begin_of_circle = n-initial_point+1;
    if(items<=positions_left_before_begin_of_circle)
    {
        //distribute m items to people after inital position -> inital postion + m
        return items + initial_point -1;
    }

    //case when we need to take a round  of the circle
    // extra items = total items - (total points-starting point+1)
    int extra_items = items - (n-initial_point+1);

    // total items = size of circle
    if(extra_items%n==0)
    {
        return n;
    }

    //total items!=size of circle
    else
    {
        return extra_items%n;
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    cout << calc_last_position(n, m, k);
    return 0;
}
