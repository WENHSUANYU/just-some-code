#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

typedef struct {
    int height;
    int pos;
}Rectangle;

class LargestRectangle{
    public:
        int H, W;
        int **T;
        LargestRectangle(int H, int W): H(H), W(W) 
        {
            T = new int*[H];
            for (int i = 0; i < H; i++) {
                T[i] = new int[W + 1];
            }
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    cin >> T[i][j];
                }
            }

            for (int j = 0; j < W; j++) {
                for (int i = 0; i < H; i++) {
                    if (T[i][j]) {
                        T[i][j] = 0;
                    } else {
                        T[i][j] = (i > 0) ? (T[i - 1][j] + 1) : 1;
                    }
                
                }
            }

        }

        int solution(int W, int T[]);
        ~LargestRectangle()
        {
            for (int i = 0; i < H; i++) {
                delete [] T[i];
            }
            delete [] T;
        }
};


int LargestRectangle::solution(int W, int T[])
{
    stack<Rectangle> S;
    int current_max_area = 0;
    T[W] = 0;

    for (int i = 0; i <= W; i++) {
        Rectangle rect;
        rect.height = T[i];
        rect.pos = i;

        if(S.empty()) {
            S.push(rect);
        } else {
            if(S.top().height < rect.height) {
                S.push(rect);
            } else if(S.top().height > rect.height) {
                int new_pos;
                while(!S.empty() && S.top().height >= rect.height) {
                    Rectangle pre = S.top();
                    S.pop();
                    int area = pre.height * (i - pre.pos);
                    current_max_area = max(current_max_area, area);
                    new_pos = pre.pos;
                }
                rect.pos = new_pos;
                S.push(rect);
            }
        }

    }

    return current_max_area;
}

//Time complexity: O(HW)
int main(void)
{
    int H, W;
    cin >> H >> W;
    LargestRectangle R(H, W);
    int max_area = 0;
    for (int i = 0; i < H; i++) {
        max_area = max(max_area, R.solution(W, R.T[i]));
    }
    cout << max_area << endl;
    return 0;
}