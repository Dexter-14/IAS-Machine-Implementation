
//II add and dividion of two digits

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<string> m(1000);
int PC = 0;
int MAR;
string MBR, IR, IBR = "";
int AC, MQ;
bool flag = true, rhs = false;
void execute();
void fetch();

int stob(string s) //convert binary string into decimal int
{
    int val = 0;
    for( int i = 0; i < s.length(); i++ )
    {
        val *= 2;
        val += s[i] - '0';
    }
    return val;
}

void ias()
{
    while(flag)
    {
        fetch();
    }
}

void fetch()
{
    MAR = PC;
    MBR = m[MAR];
    IR = MBR.substr(0,8);
    MAR = stob(MBR.substr(8,12));
    if ( MBR.length() == 40 ) IBR = MBR.substr(20), rhs = true;
    PC = PC + 1;
    execute();
    if ( rhs )
    {
        IR = IBR.substr(0,8);
        MAR = stob(IBR.substr(8,12));
        execute();
    }
}

void execute()
{
    if ( IR == "00000001") //load m(x)
    {
        AC = stoi(m[MAR]);
    }
    if ( IR == "00100001" ) //stor m(x)
    {
        m[MAR] = to_string(AC);
    }
    if ( IR == "00000010") //load -m(x)
    {
        AC = -stoi(m[MAR]);
    }
    if ( IR == "00000011") //load |m(x)|
    {
        if ( stoi(m[MAR]) > 0) AC = stoi(m[MAR]);
        else AC = -stoi(m[MAR]);
    }
    if ( IR == "00000100" ) //load -|m(x)|
    {
        if ( stoi(m[MAR]) > 0) AC = -stoi(m[MAR]);
        else AC = stoi(m[MAR]);
    }
    if ( IR == "00000101") //add m(x)
    {
        AC = AC + stoi(m[MAR]);
    }
    if ( IR == "00000111") //add |m(x)|
    {
        AC = AC + abs(stoi(m[MAR]));
    }
    if ( IR == "00000110") //sub m(x)
    {
        AC =  AC - stoi(m[MAR]);
    }
    if ( IR == "00001000") //sub |m(x)|
    {
        AC = AC - abs(stoi(m[MAR]));
    }
    if ( IR == "00001100") //div m(x)
    {
        MQ = AC/(stoi(m[MAR]));
        AC = AC%(stoi(m[MAR]));
    }

    if ( IR == "00001010") AC = MQ;
    if ( IR == "00000000") flag = false;
}


int main()
{
    // int a = 5, b = 3, c, def
    // c = a + b
    // d = a/b

    m[512] = "20";
    m[513] = "3";

    m[0] = "0000000100100000000000000101001000000001";
    m[1] = "0010000100100000001000000001001000000000";
    m[2] = "0000110000100000000100001010000000000000";
    m[3] = "0010000100100000001100000000000000000000";
    m[4] = "0000000000000000000000000000000000000000";
    ias();

    cout << m[512] << " " << m[513] << " " << m[514] << " " << m[515];
}
