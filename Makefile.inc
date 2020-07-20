#$(eval $(call add_third_party_download,$(PERSON_MODEL_URL),$(PERSON_MODEL_MD5),person_model_grayscale,))

hotdog_detection_MODEL_SRCS := \
tensorflow/lite/micro/examples/hotdog_detection/model_settings.cc \
tensorflow/lite/micro/examples/hotdog_detection/hotdog_model/hotdog_detect_model_data.cc

hotdog_detection_MODEL_HDRS := \
tensorflow/lite/micro/examples/hotdog_detection/model_settings.h \
tensorflow/lite/micro/examples/hotdog_detection/hotdog_model/hotdog_detect_model_data.h

hotdog_detection_TEST_SRCS := \
tensorflow/lite/micro/examples/hotdog_detection/hotdog_detection_test.cc \
tensorflow/lite/micro/examples/hotdog_detection/hotdogimage/hotdog_image_data_int.cc
#tensorflow/lite/micro/examples/hotdog_detection/tmp_test/tmp_test.cc 
#$(hotdog_detection_TEST_SRCS)

hotdog_detection_TEST_HDRS := \
tensorflow/lite/micro/examples/hotdog_detection/hotdogimage/hotdog_image_data_int.h \
tensorflow/lite/micro/examples/hotdog_detection/simple_model/simple_model.h 
#$(hotdog_detection_MODEL_HDRS)

IMAGE_PROVIDER_TEST_SRCS := \
tensorflow/lite/micro/examples/hotdog_detection/image_provider.cc \
tensorflow/lite/micro/examples/hotdog_detection/image_provider_test.cc \
tensorflow/lite/micro/examples/hotdog_detection/model_settings.cc

IMAGE_PROVIDER_TEST_HDRS := \
tensorflow/lite/micro/examples/hotdog_detection/image_provider.h \
tensorflow/lite/micro/examples/hotdog_detection/model_settings.h

DETECTION_RESPONDER_TEST_SRCS := \
tensorflow/lite/micro/examples/hotdog_detection/detection_responder.cc \
tensorflow/lite/micro/examples/hotdog_detection/detection_responder_test.cc

DETECTION_RESPONDER_TEST_HDRS := \
tensorflow/lite/micro/examples/hotdog_detection/detection_responder.h

hotdog_detection_SRCS := \
tensorflow/lite/micro/examples/hotdog_detection/detection_responder.cc \
tensorflow/lite/micro/examples/hotdog_detection/image_provider.cc \
tensorflow/lite/micro/examples/hotdog_detection/main.cc \
tensorflow/lite/micro/examples/hotdog_detection/main_functions.cc \
tensorflow/lite/micro/examples/hotdog_detection/himax_driver/HM01B0.c \
tensorflow/lite/micro/examples/hotdog_detection/himax_driver/HM01B0_optimized.c \
$(hotdog_detection_MODEL_SRCS)

hotdog_detection_HDRS := \
tensorflow/lite/micro/examples/hotdog_detection/detection_responder.h \
tensorflow/lite/micro/examples/hotdog_detection/image_provider.h \
tensorflow/lite/micro/examples/hotdog_detection/main_functions.h \
$(hotdog_detection_MODEL_HDRS)

#Find any platform - specific rules for this example.
include $(wildcard tensorflow/lite/micro/examples/hotdog_detection/*/Makefile.inc)

# Tests loading and running a vision model.
$(eval $(call microlite_test,hotdog_detection_test,\
$(hotdog_detection_TEST_SRCS),$(hotdog_detection_TEST_HDRS)))

# Tests the image provider module.
$(eval $(call microlite_test,hotdog_image_provider_test,\
$(IMAGE_PROVIDER_TEST_SRCS),$(IMAGE_PROVIDER_TEST_HDRS)))

# Tests the detection responder module.
$(eval $(call microlite_test,hotdog_detection_responder_test,\
$(DETECTION_RESPONDER_TEST_SRCS),$(DETECTION_RESPONDER_TEST_HDRS)))

# Builds a standalone object recognition binary.
$(eval $(call microlite_test,hotdog_detection,\
$(hotdog_detection_SRCS),$(hotdog_detection_HDRS)))
