// mianshi.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>

using namespace std;

//找到字符串当中的最长回文子串
/*
    如果字符串长度是奇数应该怎么做
    如果是偶数应该怎么做
    应该从中心往外扩展
    双指针
*/

//i往两面扩展是回文子串的长度
int string_huiwen(string s, int left, int right)
{
    int N = s.size();
    //单独字符串
    int len = 1;
    while (left >= 0 && right<N && s[left] == s[right])
    {
        len = right - left + 1;
        left -= 1;
        right += 1;
    }
    return len;
    
}

int main01()
{
    string str = "ccc";
    int N = str.size();
    int index = 0;
    int len1 = 0, len2 = 0;
    //用来记录全局最大
    int ans = 0;
    //用来记录局部谁最大
    int res1 = 0,res2 = 0;
    for (int i = 0; i < N; i++)
    {
        len1 = string_huiwen(str, i, i);
        len2 = string_huiwen(str, i, i + 1);
        cout << len1 << " " << len2<<endl;
        if (max(len1, len2) > ans)
        {
            ans = max(len1, len2);
            index = i;
        }
        
    }
    //输出的最大长度
    cout <<"输出的最大长度: " << ans << endl;
    string s1 = str.substr(index, ans);
    cout << s1 << endl;
    return 0;
}

