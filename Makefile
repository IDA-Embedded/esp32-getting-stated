# you can set this to 1 to see all commands that are being run
VERBOSE ?= 1

ifeq ($(VERBOSE),1)
export Q :=
export VERBOSE := 1
else
export Q := @
export VERBOSE := 0
endif

all :  getESPSDK format lizard cppcheck target

# Output directory
BUILD ?= target

# build  target
.PHONY: target
target: | $(BUILD)
	$(Q) cd $(BUILD);  idf.py build;
# flash  target
.PHONY: flash
flash_int: | $(BUILD)
	$(Q) cd $(BUILD);  idf.py -p /dev/ttyUSB0 flash monitor;

.PHONY: getESPSDK
getESPSDK: |
	$(Q) ./tools/installESPIDF.sh


.PHONY: format
format: |
	$(Q) ./tools/format.sh;
	
.PHONY: lizard
lizard: |
	$(Q) ./tools/lizard.sh;
	
.PHONY: clang
clang: |
	$(Q) ./tools/clang-tidy.sh;

.PHONY: cppcheck
cppcheck: |
	$(Q) ./tools/cppcheck.sh;
