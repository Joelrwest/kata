load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_test(
    name = "kata2-test",
    srcs = ["kata2-test.cpp"],
    copts = [
      "-Iexternal/gtest/googletest/include",
      "-Iexternal/gtest/googletest",
    ],
    deps = [
        "@googletest//:gtest",
        "@googletest//:gtest_main",
        "//src:kata2",
    ],
)
