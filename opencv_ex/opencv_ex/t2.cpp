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
	VideoCapture cap(0);

	if (!cap.isOpened())
		return -1;

	
	Mat tImage1 = imread("img\\right_resize.png");
	Mat tImage2 = imread("img\\left_resize.png");

	imshow("tImage1", tImage1);
	imshow("tImage2", tImage2);
	cvtColor(tImage1, tImage1, CV_RGB2GRAY);
	cvtColor(tImage2, tImage2, CV_RGB2GRAY);

	

	Mat dstImage;
	namedWindow("dstImage", 1);


	double minVal, maxVal;
	Point minLoc, maxLoc;
	Mat result;



	while (1)
	{
		Mat frame;
		cap >> frame;


		cvtColor(frame, frame, CV_RGB2GRAY);

		
		//*
		// ������ ��Ī ���(TM_SQDIFF)
		matchTemplate(frame, tImage1, result, TM_SQDIFF);
		minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
		rectangle(frame, minLoc, Point(minLoc.x + tImage1.cols, minLoc.y + tImage1.rows), Scalar(255, 0, 0), 2); //�Ķ��� �簢��
		putText(frame, "right", Point(minLoc.x + tImage1.cols, minLoc.y + tImage1.rows), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1);


		// ����ȭ�� ������ ���(TM_CCOEFF_NORMED)
		matchTemplate(frame, tImage2, result, TM_CCOEFF_NORMED);
		minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
		rectangle(frame, maxLoc, Point(maxLoc.x + tImage2.cols + 10, maxLoc.y + tImage2.rows + 10), Scalar(255, 0, 255), 2); //���ֻ� �簢��
		putText(frame, "left", Point(maxLoc.x + tImage2.cols - 130, maxLoc.y + tImage2.rows), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1);
		//*/

		imshow("dstImage", frame);

		if (waitKey(1) >= 0 && waitKey(1) != 255)
			break;
	}
	return 0;
}