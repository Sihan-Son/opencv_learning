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

int main(int, char)
{
	Mat img = imread("beaut.jpg");
	Mat img_add;
	Mat img_sub;
	Mat img_Mul;
	Mat img_Div;
	Mat img_absdiff;

	//add(img, Scalar(0, 150, 200), img_add);

	subtract(img, Scalar(0, 255, 255), img_sub);
	multiply(img, 20, img_Mul);
	divide(img, 20, img_Div);
	absdiff(img, Scalar(255, 255, 255), img_absdiff);

	namedWindow("img", 0);
	namedWindow("img_absdiff", 0);
	namedWindow("img_Div", 0);
	namedWindow("img_Mul", 0);

	imshow("img_Mul", img_Mul);
	imshow("img", img_Div);
	imshow("img", img);
	imshow("mg_absdiff", img_absdiff);

	waitKey(0);
}