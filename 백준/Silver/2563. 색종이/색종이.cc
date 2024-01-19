#include <iostream>
#define WHITE_PAPER_LENGTH 100
#define COLOR_PAPER_LENGTH 10
#define COLORED_FLAG 1
using namespace std;

int whitePaper[WHITE_PAPER_LENGTH][WHITE_PAPER_LENGTH] = {};

void attachColorPaper(int startX, int startY){
    int endX = startX + COLOR_PAPER_LENGTH;
    int endY = startY + COLOR_PAPER_LENGTH;
    for(int y = startY; y < endY; y++){
        if(y < 0 || y >= WHITE_PAPER_LENGTH) break;
        for(int x = startX; x < endX; x++){
            if(x < 0 || x >= WHITE_PAPER_LENGTH) break;
            whitePaper[y][x] = COLORED_FLAG;
        }
    }
}

int getColoredArea(){
    int coloredArea = 0;
    for(int y = 0; y < WHITE_PAPER_LENGTH; y++){
        for(int x = 0; x < WHITE_PAPER_LENGTH; x++){
            if(whitePaper[y][x] == COLORED_FLAG) coloredArea++;
        }
    }
    return coloredArea;
}

int main(){
    //색종이의 수
    int n; cin >> n;
    //색종이를 붙인 위치 (두개의 자연수)
    //색종이의 왼쪽 변과 도화지의 완쪽 변 사이의 거리, 색종이의 아래쪽 변과 도화지의 아래쪽 변 사이의 거리
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        attachColorPaper(a, b);
    }
    cout << getColoredArea();
    return 0;
}