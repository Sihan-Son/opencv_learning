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
	Mat srcImage = imread("img\\test_1.png", 0);

	if (srcImage.empty())
		return -1;

	Mat tImage1 = imread("img\\right_resize.png", 0);
	Mat tImage2 = imread("img\\left_resize.png", 0);

	imshow("tImage1", tImage1);
	imshow("tImage2", tImage2);



	Mat dstImage;
	cvtColor(srcImage, dstImage, COLOR_GRAY2BGR);

	double minVal, maxVal;
	Point minLoc, maxLoc;
	Mat result;
	
	//*
	// 제곱차 매칭 방법(TM_SQDIFF)
	matchTemplate(srcImage, tImage1, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImage, minLoc,Point(minLoc.x + tImage1.cols, minLoc.y + tImage1.rows), Scalar(255, 0, 0), 2); //파랑색 사각형
	putText(dstImage, "right", Point(minLoc.x + tImage1.cols, minLoc.y + tImage1.rows), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1);
	

	// 정규화된 상관계수 방법(TM_CCOEFF_NORMED)
	matchTemplate(srcImage, tImage2, result, TM_CCOEFF_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	rectangle(dstImage, maxLoc, Point(maxLoc.x + tImage2.cols+10, maxLoc.y + tImage2.rows+10), Scalar(255, 0, 255), 2); //자주색 사각형
	putText(dstImage, "left", Point(maxLoc.x + tImage2.cols-130, maxLoc.y + tImage2.rows), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1);


	imshow("dstImage", dstImage);
	waitKey(0);
	return 0;

	/*
	matchTemplate(srcImage, tImage2, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImage, minLoc, Point(minLoc.x + tImage2.cols, minLoc.y + tImage2.rows), Scalar(0, 255, 0), 2); // 녹색 사각형
	*/

	/*
	// 정규화된 제곱차 매칭 방법(TM_SQDIFF_NORMED)
	matchTemplate(srcImage, tImage2, result, TM_SQDIFF_NORMED);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImage, minLoc,Point(minLoc.x + tImage2.cols, minLoc.y + tImage2.rows), Scalar(0, 255, 0), 2); // 녹색 사각형
	*/

	/*
	// 정규화된 상관관계 방법(TM_CCORR_NORMED)
	matchTemplate(srcImage, tImage2, result, TM_CCORR_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	rectangle(dstImage, maxLoc, Point(maxLoc.x + tImage2.cols+5, maxLoc.y + tImage2.rows+5), Scalar(0, 0, 255), 2); //적색 사각형
	*/




}