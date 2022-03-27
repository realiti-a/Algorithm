#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int cross, ratioH, ratioW;
	cin >> cross >> ratioH >> ratioW;

	double ratioC = sqrt(ratioH*ratioH + ratioW * ratioW);

	int height = ratioH * cross / ratioC;
	int width = ratioW * cross / ratioC;

	cout << height << " " << width;
	return 0;
}