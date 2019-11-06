//#pragma warning(disable : C4996) //_CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<opencv2/opencv.hpp>
using namespace cv;

int main() {
	VideoCapture cap;
	cap.open(0); //打开视频,以上两句等价于VideoCapture cap("E://2.avi");

	//cap.open("http://www.laganiere.name/bike.avi");//也可以直接从网页中获取图片，前提是网页有视频，以及网速够快
	if (!cap.isOpened())//如果视频不能正常打开则返回
		return 0;
	Mat frame;
	Mat frame_left;
	Mat frame_right;
	int count = 1812041;
	while (1)
	{
		char leftimage_name[50];
		char righttimage_name[50];

		cap.read(frame);
		cap.set(CAP_PROP_FRAME_WIDTH, 2048.0);
		cap.set(CAP_PROP_FRAME_HEIGHT, 1536.0);
		if (frame.empty())//如果某帧为空则退出循环
			break;
		namedWindow("video", 0);
		imshow("video", frame);
		int width = frame.cols;
		int height = frame.rows;
		
		int width_hafp = width / 2;
		int height_hafp = height / 2;
		frame_left = frame(Rect(0, 0, width_hafp, height));
		imshow("left_image", frame_left);
		frame_right = frame(Rect(width_hafp, 0, width_hafp, height));
		imshow("right_image", frame_right);
		char c = cvWaitKey(20);
		if (c == 'q')
		{
			break;
		}
		else if (c == 'r')
		{
			sprintf(leftimage_name, "%d%s%s", count, "L", ".jpg");
			imwrite(leftimage_name, frame_left);
			sprintf(righttimage_name, "%d%s%s", count, "R", ".jpg");
			imwrite(righttimage_name, frame_right);
			count++;

		}

	}
	cap.release();//释放资源
}