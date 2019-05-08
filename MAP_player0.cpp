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
            cout<<"Pole pionka ktorym chcesz sie ruszyc:\n";
            cout<<"Podaj X: ";
            cin>>R.n.x;

            cout<<"Podaj Y: ";
            cin>>R.n.y;

            if(polehelp(R.n)!=2)
                R.id = scanid(R.n);


            if((act==0)&&(Realid(R.id)!=R.id)) R.id=9999;
            if((act==1)&&(Realid(R.id)==R.id)) R.id=9999;

            realid = Realid(R.id);
        }

        realid = Realid(R.id);

        cout<<"Pole na ktore chcesz sie ruszyc\n:";

        cout<<"Podaj X: ";
        cin>>R.n.x;

        cout<<"Podaj Y: ";
        cin>>R.n.y;

        if(act==0) R.o = T0[realid].pozycja();
        else R.o = T1[realid].pozycja();

        //
        R.show();
        if(act==0) T0[realid].show();
        else T1[realid].show();
        //

        if(possible(&R)) return R;
        else
        {
            cout<<"Ruch niemozliwy!\n";
        }


        realid=99;
    }
}

int MAP::scanid(c pole)
{
    for(int i =0; i<12; i++)
    {
        if(T0[i].pozycja()==pole) return T0[i].getid();
        if(T1[i].pozycja()==pole) return T1[i].getid();
    }

    return -1;
}
