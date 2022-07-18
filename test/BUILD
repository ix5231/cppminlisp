cc_test(
    name = "test",
    size = "small",
    srcs = ["test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//main:main",
        "@com_google_googletest//:gtest_main",
    ],
)
