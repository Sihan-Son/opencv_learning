#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//����׿� ���̺귯��
#ifdef _DEBUG
#pragma comment(lib, "opencv_world320d.lib")

//������ ��� �� ��
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
	// ������ ��Ī ���(TM_SQDIFF)
	matchTemplate(srcImage, tImage1, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImage, minLoc,Point(minLoc.x + tImage1.cols, minLoc.y + tImage1.rows), Scalar(255, 0, 0), 2); //�Ķ��� �簢��
	putText(dstImage, "right", Point(minLoc.x + tImage1.cols, minLoc.y + tImage1.rows), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1);
	

	// ����ȭ�� ������ ���(TM_CCOEFF_NORMED)
	matchTemplate(srcImage, tImage2, result, TM_CCOEFF_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	rectangle(dstImage, maxLoc, Point(maxLoc.x + tImage2.cols+10, maxLoc.y + tImage2.rows+10), Scalar(255, 0, 255), 2); //���ֻ� �簢��
	putText(dstImage, "left", Point(maxLoc.x + tImage2.cols-130, maxLoc.y + tImage2.rows), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1);


	imshow("dstImage", dstImage);
	waitKey(0);
	return 0;

	/*
	matchTemplate(srcImage, tImage2, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImage, minLoc, Point(minLoc.x + tImage2.cols, minLoc.y + tImage2.rows), Scalar(0, 255, 0), 2); // ��� �簢��
	*/

	/*
	// ����ȭ�� ������ ��Ī ���(TM_SQDIFF_NORMED)
	matchTemplate(srcImage, tImage2, result, TM_SQDIFF_NORMED);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImage, minLoc,Point(minLoc.x + tImage2.cols, minLoc.y + tImage2.rows), Scalar(0, 255, 0), 2); // ��� �簢��
	*/

	/*
	// ����ȭ�� ������� ���(TM_CCORR_NORMED)
	matchTemplate(srcImage, tImage2, result, TM_CCORR_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	rectangle(dstImage, maxLoc, Point(maxLoc.x + tImage2.cols+5, maxLoc.y + tImage2.rows+5), Scalar(0, 0, 255), 2); //���� �簢��
	*/




}