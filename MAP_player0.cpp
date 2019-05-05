#include <iostream>
#include <string>

#include "class.h"

using namespace std;

ruch MAP::player0()
{
    string xD;
    ruch R;
    int realid=99;

    R.team = act;

    for(;;)
    {
        while((realid<0)||(realid>11))
        {
            cout<<"Podaj id: ";
            cin>>R.id;
            
            if((act==0)&&(id>=12)) R.id=9999;
            if((act==1)&&(id<12)) R.id=9999;

            realid = Realid(R.id);
        }
        realid = Realid(R.id);

        cout<<"Podaj X: ";
        cin>>R.n.x;

        cout<<"Podaj Y: ";
        cin>>R.n.y;

        if(act==0) R.o = T0[realid].pozycja();
        else R.o = T1[realid].pozycja();

        if(possible(&R)) return R;

        R.id=99;
    }

}
