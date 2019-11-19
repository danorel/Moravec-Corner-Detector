#include "moravec.h"


int main(){
    const string pathToImg = "/Users/danorel/Workspace/World of C/C++/KMA/MMPI/Bonus/";
    const string image     = "geneva.tif";

    const string imageLabel  = "Source image";
    const string resultLabel = "Result image";

    Mat Img = imread(
            pathToImg + image,
            IMREAD_GRAYSCALE);
    Mat ResultingImg = MoravecDetector(
            Img,
            1000);

    imshow(
            imageLabel,
            Img);
    imshow(
            resultLabel,
            ResultingImg);
    waitKey();
    return 0;
}