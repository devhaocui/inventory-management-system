#include <iostream>
#include <zbar.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
using namespace zbar;

int main() {
    // Open the default camera
    VideoCapture cap(0);
    if(!cap.isOpened()) {
        cerr << "Error opening camera" << endl;
        return -1;
    }

    // Create a window to display the video feed
    namedWindow("Barcode Scanner", WINDOW_AUTOSIZE);

    // Initialize the ZBar scanner
    ImageScanner scanner;
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

    while(true) {
        Mat frame;
        cap >> frame; // Capture a frame from the camera
        if(frame.empty()) {
            cerr << "Error capturing frame" << endl;
            break;
        }

        // Convert the frame to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Wrap the grayscale image data in a ZBar image
        Image zbar_image(gray.cols, gray.rows, "Y800", gray.data, gray.cols * gray.rows);

        // Scan the image for barcodes
        int n = scanner.scan(zbar_image);

        // Extract and display the results
        for(Image::SymbolIterator symbol = zbar_image.symbol_begin(); symbol != zbar_image.symbol_end(); ++symbol) {
            cout << "Decoded: " << symbol->get_data() << endl;

            // Draw a rectangle around the detected barcode
            vector<Point> points;
            for(int i = 0; i < symbol->get_location_size(); i++) {
                points.push_back(Point(symbol->get_location_x(i), symbol->get_location_y(i)));
            }
            RotatedRect rect = minAreaRect(points);
            Point2f rect_points[4]; 
            rect.points(rect_points);
            for (int j = 0; j < 4; j++) {
                line(frame, rect_points[j], rect_points[(j+1)%4], Scalar(0, 255, 0), 2);
            }
        }

        // Display the frame with the barcode rectangle
        imshow("Barcode Scanner", frame);

        // Break the loop if the user presses the 'q' key
        if(waitKey(30) == 'q') {
            break;
        }
    }

    cap.release(); // Release the camera
    destroyAllWindows(); // Destroy all the windows

    return 0;
}
