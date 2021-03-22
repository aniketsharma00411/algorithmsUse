//C++ code to find a pattern of string in another given string
#include <iostream>
using namespace std;

void search(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
    int i = 0, j;
    while (i <= N - M)
    {
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == M)
        {
            cout << " Pattern is found at index  " << i << endl;
            i = i + M;
        }
        else if (j == 0)
        {
            i = i + 1;
        }
        else
        {
            i = i + j;
        }
    }
}

//Driver code
int main()
{
    string txt = "ABCEABCDABCEABCD";
    string pat = "ABCD";
    search(pat, txt);

    return 0;
}