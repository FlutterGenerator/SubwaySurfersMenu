LOCAL_PATH := $(call my-dir)
MAIN_LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# Имя вашей библиотеки
LOCAL_MODULE    := tojik_9

# Оптимизация кода
# Использование C++17 для поддержки в AIDE
LOCAL_CFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w
LOCAL_CFLAGS += -fno-rtti -fno-exceptions -fpermissive

# Флаги компилятора для C++
LOCAL_CPPFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w -Werror -s -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fms-extensions -fno-rtti -fno-exceptions -fpermissive

# Флаги линковки
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all, -llog

# Используем ARM архитектуру (в случае 32-битной сборки)
LOCAL_ARM_MODE := arm

# Указание путей к заголовочным файлам
LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)

# Указание исходных файлов
LOCAL_SRC_FILES := Main.cpp \
	Substrate/hde64.c \
	Substrate/SubstrateDebug.cpp \
	Substrate/SubstrateHook.cpp \
	Substrate/SubstratePosixMemory.cpp \
	Substrate/SymbolFinder.cpp \
	KittyMemory/KittyMemory.cpp \
	KittyMemory/MemoryPatch.cpp \
    KittyMemory/MemoryBackup.cpp \
    KittyMemory/KittyUtils.cpp \
	And64InlineHook/And64InlineHook.cpp

# Библиотеки, которые нужно линковать
LOCAL_LDLIBS := -llog -landroid -lGLESv2

# Включение сборки как общей библиотеки
include $(BUILD_SHARED_LIBRARY)

# Для поддержки нескольких архитектур, например, armeabi-v7a и arm64-v8a
# Добавьте это в Application.mk:
# APP_ABI := armeabi-v7a arm64-v8a