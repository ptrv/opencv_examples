#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image1 = imread("data/stuff.jpg");
    Mat image2 = imread("data/lena.jpg");

    // height, width
    Mat result(480, 640, CV_8UC3);

    int tilePos = 320;

    // Mat for resize images
    Mat img1Resized;
    Mat img2Resized;

    // width, height
    Size sizeImg1(tilePos, result.rows);
    Size sizeImg2(result.cols - tilePos, result.rows);

    // resize images
    resize(image1, img1Resized, sizeImg1);
    resize(image2, img2Resized, sizeImg2);

    //Iterate over all pixels
    for (int row = 0; row < result.rows; ++row) {
        //get row data
        uchar* dataResult = result.ptr(row);
        uchar* dataImg1 = img1Resized.ptr(row);
        uchar* dataImg2 = img2Resized.ptr(row);
        for (int col = 0; col < result.cols; ++col) {
            // get every value for all three channels
            if(col < tilePos){
                *dataResult++ = *dataImg1++;
                *dataResult++ = *dataImg1++;
                *dataResult++ = *dataImg1++;
            } else {
                *dataResult++ = *dataImg2++;
                *dataResult++ = *dataImg2++;
                *dataResult++ = *dataImg2++;
            }
        }
    }

    namedWindow("Tiled images");
    imshow("Tiled images", result);
    waitKey();
    return 0;
}

