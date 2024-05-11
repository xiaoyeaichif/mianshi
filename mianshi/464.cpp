/*
    ǰ׺�� + �������
*/

//#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

const int N = 100000 + 10;
vector<int>yuan_(N, 0);
vector<long long>Presum(N, 0);

/*
    ǰ׺�� + �������
*/


void chafen_(int l, int r, int c)
{
    Presum[l] += c;
    Presum[r + 1] -= c;
}



int main02()
{
    int n, m, q;
    cin >> n >> m >> q;
    //���ԭ����
    for (int i = 1; i <= n; i++)
    {
        cin >> yuan_[i];
        //���²������
        Presum[i] = yuan_[i] - yuan_[i - 1];
    }
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        chafen_(l, r, c);
    }
    //���²������ĺ�
    for (int i = 1; i <= n; i++)
    {
        Presum[i] += Presum[i - 1];
    }

    //���²�������ǰ׺��
    for (int i = 1; i <= n; i++)
    {
        Presum[i] += Presum[i - 1];
    }
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cout << Presum[r] - Presum[l - 1] << endl;
    }
    return 0;
}
