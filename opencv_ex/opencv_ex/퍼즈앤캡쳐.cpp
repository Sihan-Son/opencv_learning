#include < stdio.h>
#include < iostream>

#include < opencv2\opencv.hpp>

//디버그용 라이브러리
#ifdef _DEBUG
#pragma comment(lib, "opencv_world320d.lib")

//릴리즈 모드 일 때
#else
#pragma comment(lib, "opencv_world320.lib")

#endif


using namespace std;
using namespace cv;

bool selectObject = false;
Rect selection;
Point origin;
Mat image;
bool pause = false;
double fpss;

Rect PatchRect;
Mat PatchImg;

unsigned int frame_index = 0;

static void onMouse(int event, int x, int y, int, void*)
{
	if (selectObject & pause)
	{

		selection.x = MIN(x, origin.x);
		selection.y = MIN(y, origin.y);
		selection.width = std::abs(x - origin.x);
		selection.height = std::abs(y - origin.y);
		selection &= Rect(0, 0, image.cols, image.rows);
	}

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		origin = Point(x, y);
		selection = Rect(x, y, 0, 0);
		selectObject = true;
		break;
	case CV_EVENT_LBUTTONUP:
		if (selectObject && pause)
		{
			if (selection.width > 5 && selection.height > 5)
			{
				PatchRect = selection;
				image(PatchRect).copyTo(PatchImg);
				imshow("Selected Img", PatchImg);


				char str[100];
				sprintf_s(str, "%d.jpg", int(frame_index / fpss));
				imwrite(str, PatchImg);

			}
			else
				selection = Rect(0, 0, 0, 0);
		}
		selectObject = false;
		pause = false;

		break;
	}
}


int main(void)
{

	/*
	printf("avi file name?");
	char nstr[255];
	scanf_s("%s", nstr);
	printf("-> %s", nstr);
	*/
	VideoCapture cap(0);

	Mat frame;
	namedWindow("Demo", 0);
	setMouseCallback("Demo", onMouse, 0);
	printf("P key is pause, ESC key is exit.\n");

	for (;;)
	{
		frame_index++;

		if (!pause)
			cap >> frame;
		if (frame.empty())
			break;
		frame.copyTo(image);


		if (pause && selection.width > 0 && selection.height > 0)
		{
			rectangle(image, Point(selection.x - 1, selection.y - 1), Point(selection.x + selection.width + 1, selection.y + selection.height + 1), CV_RGB(255, 0, 0));
		}

		imshow("Demo", image);

		char k = waitKey(10);

		if (k == 27)
			break;
		else if (k == 'p' || k == 'P')
			pause = !pause;
	}

	return 0;
}
