link_libraries(drogon)

add_executable(cache_map_test CacheMapTest.cc)
add_executable(cache_map_test2 CacheMapTest2.cc)
add_executable(cookies_test CookiesTest.cc)
add_executable(class_name_test ClassNameTest.cc)
add_executable(sha1_test Sha1Test.cc ../src/ssl_funcs/Sha1.cc)
add_executable(view_data_test HttpViewDataTest.cc)
add_executable(md5_test Md5Test.cc ../src/ssl_funcs/Md5.cc)
add_executable(http_full_date_test HttpFullDateTest.cc)
add_executable(gzip_test GzipTest.cc)
add_executable(url_codec_test UrlCodecTest.cc)
add_executable(main_loop_test MainLoopTest.cc)

set(test_targets
    cache_map_test
    cache_map_test2
    cookies_test
    class_name_test
    sha1_test
    view_data_test
    md5_test
    http_full_date_test
    gzip_test
    url_codec_test
    main_loop_test)

set_property(TARGET ${test_targets}
             PROPERTY CXX_STANDARD ${DROGON_CXX_STANDARD})
set_property(TARGET ${test_targets} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${test_targets} PROPERTY CXX_EXTENSIONS OFF)
