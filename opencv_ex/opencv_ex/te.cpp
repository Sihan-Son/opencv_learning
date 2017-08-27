#include "opencv2/opencv.hpp"

using namespace cv;

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
	
	Mat edges;
	namedWindow("edges", 1);

	for (;;)
	{
		Mat frame;
		cap >> frame;
		cvtColor(frame,edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if (waitKey(5) == 27)
			break;
	}
	return 0;
}