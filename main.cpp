#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv) {

    IplImage *src, *append, *result;
    char srcFile[] = "/full/path/to/src/file.ext",
         appendFile[] = "/full/path/to/append/file.ext";

    src = cvLoadImage(srcFile, 0);
    append = cvLoadImage(appendFile, 0);

    result = cvCreateImage(cvSize(src->width + append->width, src->height), IPL_DEPTH_8U, 1);
    cvSetImageROI(result, cvRect(0, 0, src->width, append->width));
    cvCopy(src, result);
    cvResetImageROI(result);
    cvSetImageROI(result, cvRect(src->width, 0, append->width, append->height));
    cvCopy(append, result);
    cvResetImageROI(result);

    cvSaveImage(srcFile, result);
    cvReleaseImage(&result);
    cvReleaseImage(&src);
    cvReleaseImage(&append);

    return 0;
}