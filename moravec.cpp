//
// Created by Dan Orel on 2019-11-17.
//
#include "moravec.h"


Mat
    MoravecDetector(
            const Mat& Img,
            int threshold) {
    Mat MoravecImage = Mat(
            Img.rows,
            Img.cols,
            CV_8UC1,
            Scalar(0));
    // Copying the data from the source to the resulting image
    for (int i = 0; i < Img.rows * Img.cols; i++)
        MoravecImage.data[i] = Img.data[i];

    // Defining the W window frame, where we check up the corners
    vector<Point> shifts = {
            Point(-1, 0),
            Point(0, -1),
            Point(1, 0),
            Point(0, 1),
            Point(-1, -1),
            Point(-1, 1),
            Point(1, -1),
            Point(1, 1)
    };
    // Initialization of frame width
    const int frame_width = 3;

    // Initialization step of the second frame
    int frame_x[]{-1, 0, 1, -1, 0, 1, -1, 0, 1 };
    int frame_y[]{-1, -1, -1, 0, 0, 0, 1, 1, 1 };

    // Initialization of parameters to calculate the corner values
    int shift_x         = 0,
        shift_y         = 0,
        minimum         = 0,
        summary         = 0,
        red_positive_x  = 0,
        red_positive_y  = 0,
        red_value       = 0,
        blue_negative_x = 0,
        blue_negative_y = 0,
        blue_value      = 0;

    // Iterating through image, and applying the Harris corner detection algorithm
    for (int i = frame_width - 1; i < Img.rows - (frame_width - 1); i++)
        for (int j = frame_width - 1; j < Img.cols - (frame_width - 1); j++) {
            minimum = INT_MAX;
            for (const Point& shift : shifts) {
                shift_x = i + shift.x;
                shift_y = j + shift.y;
                summary = 0;
                for (int k = 0; k < frame_width * frame_width; k++) {
                    red_positive_x  = i + frame_x[k];
                    red_positive_y  = j + frame_y[k];
                    blue_negative_x = shift_x + frame_x[k];
                    blue_negative_y = shift_y + frame_y[k];
                    red_value = Img.at<uchar>(
                            red_positive_x,
                            red_positive_y);
                    blue_value = Img.at<uchar>(
                            blue_negative_x,
                            blue_negative_y);
                    summary += pow(
                            red_value - blue_value,
                            2);
                }
                if (minimum > summary)
                    minimum = summary;
            }

            if (minimum > threshold) // If corner was detected - draw the point around the origin
                for (int k = i - 1; k <= i + 1; k++)
                    for (int l = j - 1; l <= j + 1; l++)
                        MoravecImage.at<uchar>(k, l) = 255;

        }
    return MoravecImage;
}
