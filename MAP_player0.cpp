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
    cout<<"act:"<<act<<endl;

    for(;;)
    {
        while(!((realid>=0)&&(realid<=11)))
        {
            cout<<"Podaj id: ";
            cin>>R.id;

            if((act==0)&&(Realid(R.id)!=R.id)) R.id=9999;
            if((act==1)&&(Realid(R.id)==R.id)) R.id=9999;

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
        else
        {
            cout<<"Ruch niemozliwy!\n";
            R.show();
        }

        realid=99;
    }

}
