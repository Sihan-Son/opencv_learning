#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

//디버그용 라이브러리
#ifdef _DEBUG
//#pragma comment(lib, "opencv_core2413d.lib")
//#pragma comment(lib, "opencv_imgproc2413d.lib")
//#pragma comment(lib, "opencv_highgui2413d.lib")
//#pragma comment(lib, "opencv_video2413d.lib")
#pragma comment(lib, "opencv_world320d.lib");
//릴리즈 모드 일 때
#else
//#pragma comment(lib, "opencv_core2413.lib")
//#pragma comment(lib, "opencv_imgproc2413.lib")
//#pragma comment(lib, "opencv_highgui2413.lib")
//#pragma comment(lib, "opencv_video2413.lib")
#pragma comment(lib, "opencv_world320.lib");
#endif


void main()
{
	VideoCapture stream1(1);

	if (!stream1.isOpened())
		cout << "cannot open camera";
	
	namedWindow("Processing");
	namedWindow("Origin");

	while (true)
	{
		Mat cameraFrame;
		stream1.read(cameraFrame);
		try {
			imshow("Origin", cameraFrame);
		}
		catch (Exception)
		{
			break;
		}
		Sobel(cameraFrame, cameraFrame, CV_8U, 1, 0);
		imshow("Processing", cameraFrame);

		if (waitKey(30) >= 0)
			break;
	}

	destroyAllWindows();

}