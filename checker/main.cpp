#include <bits/stdc++.h>

using namespace std;

int main() {

    //题目名称： title
    //源程序: title.cpp
    //测试数据个数： T
    //输入数据： datas/in/title1.in  title2.in ...
    //标准输出 : datas/ans/title1.ans title2.ans ...

    string title = "H";
    string log = title + ".log";

    //编译
    string command = "g++ " + title + ".cpp -o " + title + " 2>> " + title + ".log";
    //cout << command << endl;
    system(command.c_str());

    int T = 1;

    for (int i = 1; i <= T; i++) {
        string in = "datas/in/" + title + (char)('0' + i) + ".in";
        string out = "datas/out/" + title + (char)('0' + i) + ".out";
        string ans = "datas/ans/" + title + (char)('0' + i) + ".ans";

        //运行
        command = "./" + title + " < " + in + " > " + out + " 2>> " + log;
        system(command.c_str());

        //比对答案
        command = "diff " + ans + " " + out + " -b >> " + log;
        if(system(command.c_str())) {
            cout << "Wrong Answer on Test " << i << endl;
        }else{
            cout << "Accepted on Test " << i << endl;
        }

    }

    return 0;
}