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

int g_slider;
int g_slider_max;

void on_trackbar(int, void*)
{
	/* sobel 변환할때
	if (g_slider % 2 == 0)
		g_slider += 1;
	*/
	cout << g_slider << endl;
}

int main()
{
	/*
	Mat img = imread("aa.jpg");
	Mat img2;

	g_slider = 0;
	g_slider_max = 31;

	namedWindow("My Window", 1);
	createTrackbar("TrackbarName", "My Window", &g_slider, g_slider_max, on_trackbar);


	while (1)
	{
		Sobel(img, img2, CV_8U, 1, 0, g_slider);

		imshow("My Window", img2);

		int r = waitKey(10);
		cout << r << endl;
		if (r > 0 && r!=255)
			break;
	}
	*/

	Mat edges;
	VideoCapture cap = VideoCapture(0);
	
	if (!cap.isOpened())
		return -1;

	g_slider = 0;
	g_slider_max = 255;
	namedWindow("edges", 1);

	createTrackbar("Trackbar", "edges", &g_slider, g_slider_max, on_trackbar);

	for (;;)
	{
		Mat frame;
		cap >> frame;
		cvtColor(frame, edges, CV_RGB2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, g_slider, 30, 3);
		imshow("edges", edges);
		if (waitKey(30) >= 0 && waitKey(30)!=255)
			break;
	}
}