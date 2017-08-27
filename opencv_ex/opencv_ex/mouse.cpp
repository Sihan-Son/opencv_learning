#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//디버그용 라이브러리
#ifdef _DEBUG
#pragma comment(lib, "opencv_world320d.lib")

//릴리즈 모드 일 때
#else
#pragma comment(lib, "opencv_world320.lib")

#endif

//mouse callbackfunction
void CallBackFunc(int event, int x, int y, int flags, void*userdata);


int main(int, char)
{
	namedWindow("img", 0);

	Mat img = imread("aa.jpg");


	setMouseCallback("img", CallBackFunc, &img);

	imshow("img", img);
	
	waitKey(0);
}

void CallBackFunc(int event, int x, int y, int flags, void*userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "LBUTTONDOWN down " << x << " " << y << endl;
		circle(*(Mat*)userdata, Point(x, y), 2, CV_RGB(255, 0, 0), 3);
	}
	if(event == EVENT_RBUTTONDOWN)
		cout << "RBUTTONDOWN down " << x << " " << y << endl;


	if (event == EVENT_MBUTTONDOWN)
		cout << "MBUTTONDOWN down " << x << ", " << y << endl;
	else if(event == EVENT_MOUSEMOVE)
		cout << "move " << x << ", " << y << endl;

	imshow("img",(*(Mat*)userdata));
}