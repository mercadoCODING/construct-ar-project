#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open the default camera (camera ID 0)
    cv::VideoCapture cap(0);

    // Check if the camera is opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the camera." << std::endl;
        return -1;
    }

    cv::Mat frame;
    std::cout << "Press 'q' to quit the application." << std::endl;

    // Main loop to capture frames from the camera
    while (true) {
        cap >> frame; // Capture a frame

        // Check if the frame is empty
        if (frame.empty()) {
            std::cerr << "Error: Captured empty frame." << std::endl;
            break;
        }

        // Display the frame in a window
        cv::imshow("Camera Feed", frame);

        // Break the loop if 'q' is pressed
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // Release the camera and close any OpenCV windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
