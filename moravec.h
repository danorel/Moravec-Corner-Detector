//
// Created by Dan Orel on 2019-11-17.
//
#include <iostream>
#include <queue>
#include <list>
#include <cmath>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;
#ifndef BONUS_MORAVEC_H
#define BONUS_MORAVEC_H
Mat
    MoravecDetector(
            const Mat& Img,
            int threshold);
#endif //BONUS_MORAVEC_H
