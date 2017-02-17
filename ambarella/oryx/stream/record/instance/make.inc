##
## /S2l/oryx/stream/record/instance/make.inc
##
## History:
##   2014-12-31 - [ypchang] created file
##
## Copyright (C) 2008-2014, Ambarella Co, Ltd.
##
## All rights reserved. No Part of this file may be reproduced, stored
## in a retrieval system, or transmitted, in any form, or by any means,
## electronic, mechanical, photocopying, recording, or otherwise,
## without the prior consent of Ambarella.
##

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

RECORD_TARGET := libamstream-record.so
RECORD_VER_FILE = $(ORYX_DIR)/include/stream/version.h
RECORD_VER_PREFIX = RECORD

LOCAL_TARGET := $(RECORD_TARGET)
LOCAL_SRCS   := $(wildcard $(LOCAL_PATH)/*.cpp)

LOCAL_CFLAGS := -I$(LOCAL_PATH)                     \
                -I$(ORYX_DIR)/include               \
                -I$(ORYX_DIR)/include/utility       \
                -I$(ORYX_DIR)/include/stream        \
                -I$(ORYX_DIR)/stream/include/amf    \
                -I$(ORYX_DIR)/stream/include/record \
                -std=c++11 -Werror

LOCAL_LIBS := libamstream-record-engine.so

RECORD_SO_VER_MAJ := $(shell awk '/define\ $(RECORD_VER_PREFIX)_LIB_MAJOR/{print $$3}' $(RECORD_VER_FILE))
RECORD_SO_VER_MIN := $(shell awk '/define\ $(RECORD_VER_PREFIX)_LIB_MINOR/{print $$3}' $(RECORD_VER_FILE))
RECORD_SO_VER_PAT := $(shell awk '/define\ $(RECORD_VER_PREFIX)_LIB_PATCH/{print $$3}' $(RECORD_VER_FILE))
RECORD_SO_VER_STR := $(RECORD_SO_VER_MAJ).$(RECORD_SO_VER_MIN).$(RECORD_SO_VER_PAT)

RECORD_SO_NAME   := $(patsubst %.so,%.so.$(RECORD_SO_VER_MAJ), $(RECORD_TARGET))
RECORD_SO_TARGET := $(patsubst %.so,%.so.$(RECORD_SO_VER_STR), $(RECORD_TARGET))

LOCAL_SO_NAME := $(RECORD_SO_NAME)

include $(BUILD_APP)

.PHONY: $(LOCAL_TARGET)

$(LOCAL_TARGET): $(LOCAL_MODULE)
	@mkdir -p $(ORYX_LIB_DIR)
	@cp -dpRf $< $(ORYX_LIB_DIR)/$(RECORD_SO_TARGET)
	@ln -sf $(RECORD_SO_TARGET) $(ORYX_LIB_DIR)/$(RECORD_SO_NAME)
	@echo "Build $@ Done."

$(call add-target-into-build, $(LOCAL_TARGET))