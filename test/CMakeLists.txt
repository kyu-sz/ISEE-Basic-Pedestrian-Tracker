if (test)
    add_executable(tracker_test tracker_test.cpp)
    include_directories(tracker_test PUBLIC ${PROJECT_SOURCE_DIR}/include)
    target_link_libraries(tracker_test basic_pedestrian_tracker opencv_core opencv_highgui opencv_imgproc)
    add_test(NAME tracker_test COMMAND tracker_test ${TEST_VIDEO_PATH})

    add_executable(lib_test EXCLUDE_FROM_ALL lib_test.cpp)
    include_directories(lib_test PUBLIC ${PROJECT_SOURCE_DIR}/include)
    target_link_libraries(lib_test basic_pedestrian_tracker)
    add_test(NAME lib_test COMMAND lib_test ../test_video/20131220184349-20131220184937.h264 ../conf/CAM01_0.conf)
endif ()
